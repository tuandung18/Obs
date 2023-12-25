#include "vorlesung.h"



bool Vorlesung::belegen(QSharedPointer<Student> s)
{
    belegtVon.push_back(s);
}

QString Vorlesung::getBelegNr() const
{
    return belegNr;
}

void Vorlesung::setBelegNr(const QString &newBelegNr)
{
    belegNr = newBelegNr;
}

QString Vorlesung::getBezeichnung() const
{
    return bezeichnung;
}

void Vorlesung::setBezeichnung(const QString &newBezeichnung)
{
    bezeichnung = newBezeichnung;
}

unsigned int Vorlesung::getKapa() const
{
    return kapa;
}

void Vorlesung::setKapa(unsigned int newKapa)
{
    kapa = newKapa;
}

QSharedPointer<Dozentin> Vorlesung::getAngebotVon() const
{
    return angebotVon;
}

void Vorlesung::setAngebotVon(QSharedPointer<Dozentin> newAngebotVon)
{
    angebotVon = newAngebotVon;
}

QVector<QSharedPointer<Student>>& Vorlesung::getBelegtVon()
{
    return belegtVon;
}


Vorlesung::Vorlesung(const QString &belegNr, const QString &bezeichnung, unsigned int kapa) : belegNr(belegNr),
    bezeichnung(bezeichnung),
    kapa(kapa)
{}
