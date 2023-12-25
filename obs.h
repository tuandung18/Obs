#ifndef OBS_H
#define OBS_H
#include "vorlesung.h"
#include "benutzer.h"
#include "dozentin.h"
#include "student.h"
#include <vector>
#include <string>


class Obs
{
public:
    Obs();
    ~Obs();
    bool einloggen();
    Vorlesung *findeVorlesung(QString belegNummer);
    Benutzer *getAngemeldeterBenutzer() const;

    void setAngemeldeterBenutzer(Benutzer *newAngemeldeterBenutzer);

    Benutzer *findeBenutzer(QString id);
private:
    std::vector<Vorlesung*> alleVorlesungen{
                new Vorlesung(QString("30.7122"),QString("Programmieren 1"),32),
                new Vorlesung(QString("30.7128"),QString("Programmieren 2"),32),
                new Vorlesung(QString("30.7220"),QString("Betriebssysteme"),16),
                new Vorlesung(QString("30.7106"),QString("Rechnerarchitektur"),16),
                new Vorlesung(QString("30.7118"),QString("Algorithmen und Datenstrukturen"),32),
                new Vorlesung(QString("30.7126"),QString("IT-Sicherheit"),16),
                new Vorlesung(QString("30.7108"),QString("Technische Grundlagen der Informatik"),2),
                new Vorlesung(QString("30.7120"),QString("Mathematik für Informatiker 1"),8),
                new Vorlesung(QString("30.7124"),QString("Mathematik für Informatiker 2"),8)
    };
    std::vector<Benutzer*> alleBenutzer{
                 new Dozentin(QString("D1000"), QString("Ayla"), QString("Ambrosio"), this),
                 new Dozentin(QString("D1001"), QString("Paul"), QString("Panter"), this),
                 new Dozentin(QString("D1002"), QString("Saskia"), QString("Wegehenkel"), this),
                 new Dozentin(QString("D1003"), QString("Esra"), QString("Topas"), this),
                 new Dozentin(QString("D1004"), QString("Arnim"), QString("Malcherek"), this),
                 new Student(QString("1000000"), QString("Johanna"), QString("Remus"), this),
                 new Student(QString("1000001"), QString("Kai"), QString("Lode"), this),
                 new Student(QString("1000002"), QString("Jeremy"), QString("Moussa"), this),
                 new Student(QString("1000003"), QString("Sarah"), QString("Orth"), this),
                 new Student(QString("1000004"), QString("Miriam"), QString("Klepper"), this),
                 new Student(QString("1000005"), QString("Tuan"), QString("Quang"), this),
                 new Student(QString("1000006"), QString("Tobias"), QString("Thielen"), this),
                 new Student(QString("1000007"), QString("Christian"), QString("Vikulov"), this),
                 new Student(QString("1000008"), QString("Alexandra"), QString("Weber"), this),
                 new Student(QString("1000009"), QString("Adrian"), QString("Fischer"), this)

    };
    Benutzer*angemeldeterBenutzer = nullptr;
};
#endif // OBS_H
