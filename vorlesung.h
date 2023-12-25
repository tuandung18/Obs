#ifndef VORLESUNG_H
#define VORLESUNG_H

#include <QtCore>
class Student;
class Dozentin;
class Vorlesung
{
public:
    Vorlesung(const QString &belegNr, const QString &bezeichnung, unsigned int kapa);
    bool belegen(QSharedPointer<Student>);
    virtual ~Vorlesung() = default;
    QString getBelegNr() const;
    void setBelegNr(const QString &newBelegNr);
    QString getBezeichnung() const;
    void setBezeichnung(const QString &newBezeichnung);
    unsigned int getKapa() const;
    void setKapa(unsigned int newKapa);
    QSharedPointer<Dozentin> getAngebotVon() const;
    void setAngebotVon(QSharedPointer<Dozentin> newAngebotVon);

    QVector<QSharedPointer<Student> > &getBelegtVon();

private:
    QString belegNr, bezeichnung;
    unsigned int kapa;
    QVector<QSharedPointer<Student>> belegtVon;
    QSharedPointer<Dozentin> angebotVon;
};

#endif // VORLESUNG_H
