#include "obs.h"
#include "benutzer.h"
#include <iostream>
#include <vorlesung.h>
using std::cin, std::cout, std::string, std::endl;
Obs::Obs()
{
}

Obs::~Obs(){
}

bool Obs::einloggen()
{
    std::string input;
    do {
        cout << "ID: ";
        cin >> input;
        angemeldeterBenutzer=findeBenutzer(QString::fromStdString(input));
        if (angemeldeterBenutzer == nullptr){
            cout<<"ID does not exist"<<endl;
            continue;
        }
        cout<<"Programm running"<<endl;
        angemeldeterBenutzer->benutzerDialog();
    } while (input != "Exit");
    return false;



}

Vorlesung *Obs::findeVorlesung(QString belegNummer)
{
    for (const auto &v : alleVorlesungen){
        if (v->getBelegNr() == belegNummer)
            return v;
    }
    return nullptr;

}

Benutzer* Obs::findeBenutzer(QString id)
{
    for (const auto &b: alleBenutzer){
        if (b->getId() == id)
            return b;
    }
    cout<<"Not found"<<endl;
    return nullptr;
}

void Obs::setAngemeldeterBenutzer(Benutzer *newAngemeldeterBenutzer)
{
    angemeldeterBenutzer = newAngemeldeterBenutzer;
}

Benutzer *Obs::getAngemeldeterBenutzer() const
{
    return angemeldeterBenutzer;
}



