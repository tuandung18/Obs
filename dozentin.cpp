#include "dozentin.h"
#include <algorithm>
#include <fstream>
#include <json.hpp>
#include <obs.h>
#include <student.h>
#include <vorlesung.h>
using namespace nlohmann;
void Dozentin::benutzerDialog() {
  char c;
  do {
    cout << "1. Vorlesung anbieten \n2. Meine Vorlesungen anzeigen \n3. Save "
            "as Json \n0. Abmelden"
         << endl;
    cin >> c;

    switch (c) {
    case '1': {
      cout << "Belegnr: ";
      std::string nr;
      cin >> nr;
      QString belegNr = QString::fromStdString(nr);
      vorlesungAnbieten(belegNr);
      break;
    }
    case '2':
      belegungenAnzeigen();
      break;
    case '3':
      saveJSON();
      break;
    case '0':
      break;
    default:
      cout << "Invalid input" << endl;
      break;
    }

  } while (c != '0');
}


void Dozentin::vorlesungAnbieten(QString belegNr) {
  auto vorlesung = QSharedPointer<Vorlesung>(obs->findeVorlesung(belegNr));
  if (vorlesung != nullptr) {
    QSharedPointer<Dozentin> doz = vorlesung->getAngebotVon();
    if (doz != nullptr)
      cout << "Vorlesung wurde von " << doz->getVorname().toStdString() << " "
           << doz->getNachname().toStdString() << " angeboten" << endl;
    else {
      auto newDoz = QSharedPointer<Dozentin>(this);
      vorlesung->setAngebotVon(newDoz);
      meineVorlesung.push_back(vorlesung);
    }
  } else
    cout << "Vorlesung not found" << endl;
}


void Dozentin::saveJSON() {
  json list;
  json student;

  for (const auto &v : meineVorlesung) {
    json vorlesung;
    vorlesung["Belegnummer"] = v->getBelegNr().toStdString();
    vorlesung["Bezeichnung"] = v->getBezeichnung().toStdString();
    json belegungJson;
    for (const auto &s : v->getBelegtVon()) {
      student["Mtr"] = s->getId().toStdString();
      student["Vorname"] = s->getVorname().toStdString();
      student["Nachname"] = s->getNachname().toStdString();
      belegungJson.push_back(student);
      vorlesung["Belegungen"] = belegungJson;
    }
    list.push_back(vorlesung);
  }

  std::ofstream outputS("Belegungen_hihi.json");
  if (!outputS)
    std::cerr << "Json file not opening" << endl;
  outputS << list.dump(4);
  outputS.close();
}


void Dozentin::belegungenAnzeigen() {
  auto &tempVL = meineVorlesung;
  std::sort(tempVL.begin(), tempVL.end(),
            [](QSharedPointer<Vorlesung> x, QSharedPointer<Vorlesung> y) {
              return x->getBezeichnung() < y->getBezeichnung();
            });
  for (const auto &v : meineVorlesung) {
    cout << v->getBezeichnung().toStdString() << endl;
    auto &temp = v->getBelegtVon();
    std::sort(temp.begin(), temp.end(),
              [](QSharedPointer<Student> x, QSharedPointer<Student> y) {
                return x->getNachname() < y->getNachname();
              });
    for (const auto &s : v->getBelegtVon())
      cout << s->getId().toStdString() << " " << s->getVorname().toStdString()
           << " " << s->getNachname().toStdString() << endl;
  }
}


Dozentin::Dozentin(const QString &id, const QString &vorname,
                   const QString &nachname, Obs *obs)
    : Benutzer(id, vorname, nachname, obs) {}
