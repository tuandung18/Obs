#ifndef BENUTZER_H
#define BENUTZER_H
#include <QtCore>
#include <iostream>
using std::cout,std::cin, std::endl, std::string;

class Obs;
class Benutzer
{
public:
    Benutzer(const QString &id, const QString &vorname, const QString &nachname, Obs* obs);
    virtual void benutzerDialog() = 0;
    virtual ~Benutzer() = default;
    QString getId() const;

    virtual QString getVorname() const;
    virtual QString getNachname() const;

protected:
    QString id, vorname, nachname;
    Obs* obs;

};

#endif // BENUTZER_H
