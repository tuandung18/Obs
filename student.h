#ifndef STUDENT_H
#define STUDENT_H

#include "benutzer.h"
class Vorlesung;
class Student : public Benutzer
{
public:
    Student(const QString &id, const QString &vorname, const QString &nachname, Obs *obs);

    void benutzerDialog() override;

    QVector<QSharedPointer<Vorlesung> > getMeineBelegungen() const;

    QString belegen(QString belegeNur);
    void belegungenAnzeigen();
private:
    QVector<QSharedPointer<Vorlesung>> meineBelegungen;

};

#endif // STUDENT_H
