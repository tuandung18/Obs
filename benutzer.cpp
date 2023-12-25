#include "benutzer.h"


Benutzer::Benutzer(const QString &id, const QString &vorname, const QString &nachname, Obs *obs) : id(id),
    vorname(vorname),
    nachname(nachname),
    obs(std::move(obs))
{}

QString Benutzer::getId() const
{
    return id;
}

QString Benutzer::getVorname() const
{
    return vorname;
}

QString Benutzer::getNachname() const
{
    return nachname;
}
