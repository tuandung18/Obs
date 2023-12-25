#include "student.h"
#include <obs.h>
#include <iostream>
#include <vorlesung.h>
void Student::benutzerDialog()
{
    char c;
    do{
        std::cout<<"1.Vorlesung belegen \n2. Meine Belegungen anzeigen \n0. Abmelden"<<endl;
        cin >> c;
        switch (c) {
        case '1':{
            cout<<"Belegnr: ";
            std::string nr;
            cin >> nr;
            QString belegNr = QString::fromStdString(nr);
            belegen(belegNr);
            break;
        }
        case '2':
            belegungenAnzeigen();
            break;
        case '0':
            break;
        default:
            cout<<"Invalid input"<<endl;
            break;
        }
    } while (c != '0');
}



void Student::belegungenAnzeigen()
{
    for (const auto &b: meineBelegungen)
        std::cout<<"BelegNr: "<<b->getBelegNr().toStdString()<<'\n';
}

QVector<QSharedPointer<Vorlesung> > Student::getMeineBelegungen() const
{
    return meineBelegungen;
}

QString Student::belegen(QString belegeNur)
{
    auto vorlesung = QSharedPointer<Vorlesung> (obs->findeVorlesung(belegeNur));
    if(vorlesung != nullptr){
        if(vorlesung->getKapa() > vorlesung->getBelegtVon().length()){
            auto newStud = QSharedPointer<Student>(this);
            vorlesung->belegen(newStud);
            meineBelegungen.push_back(vorlesung);
        }
        else{
            cout<<"Vorlesung is full"<<endl;
            return QString("Vorlesung full");
        }
    }
    else{
        cout<<"Vorlesung not found"<<endl;
        return QString("Vorlesung not found");
    }
}

Student::Student(const QString &id, const QString &vorname, const QString &nachname, Obs *obs) : Benutzer(id, vorname, nachname, obs)

{}
