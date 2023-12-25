#ifndef DOZENTIN_H
#define DOZENTIN_H

#include "benutzer.h"
class Vorlesung;
class Dozentin : public Benutzer
{
public:
    Dozentin(const QString &id, const QString &vorname, const QString &nachname, Obs* obs);
    void benutzerDialog() override;
    void saveJSON();
private:
    void vorlesungAnbieten(QString belegNr);
    void belegungenAnzeigen();
    QVector<QSharedPointer<Vorlesung>> meineVorlesung;

};

#endif // DOZENTIN_H
