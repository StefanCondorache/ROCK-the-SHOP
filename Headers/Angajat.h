#include <cstring>
#include <iostream>
#include <ctime>
#pragma once

using namespace std;


class Angajat{
protected:
    int id;
    string nume, prenume;
    string cnp;
    tm dataAngajare;
    double salariu = 3500;
    double coeficientSalarial;
public:
    Angajat() = default;
    Angajat(const int&, const string&, const string&, const string&, const tm&, double);
    virtual ~Angajat() = default;

    int getId() const;
    string getNume() const;
    string getPrenume() const;
    string getCNP() const;
    tm getDataAngajare() const;

    virtual double calculeazaSalariu();
    void setNumePrenume(string&, string&);
    virtual void afiseazaDetalii();
};
