#include <iostream>
#include <cstring>
#pragma once

using namespace std;

class Produs{
protected:
    int codProdus;
    string denumire;
    int stoc;
    double pretBaza = 0.0;
public:
    Produs(const int&, const string&, const int, const double);
    virtual ~Produs() = default;

    int getCod() const;
    string getDenumire() const;
    int getStoc() const;
    double getPretBaza() const;
    void setStoc(int);

    virtual void calculeazaPretFinal();
    virtual void afiseazaDetalii() const;
};
