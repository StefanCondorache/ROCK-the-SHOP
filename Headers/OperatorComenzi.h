#include <cstring>
#include <iostream>
#include "Comanda.h"
#include "Angajat.h"
#pragma once


using namespace std;

class OperatorComenzi: public Angajat{
protected:
    int nrComenzi = 0;
    double bonusComenzi;
public:
    OperatorComenzi(const int&, const string&, const string&, const string&, tm&);
    int getNrComenzi() const;
    double getBonusComenzi() const;
    void preluareaComenzii(const Comanda&);
    double calculeazaSalariu() override;
    void afiseazaDetalii();

};
