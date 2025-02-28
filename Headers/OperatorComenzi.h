#include <cstring>
#include <iostream>
#include "Comanda.h"
#include "Angajat.h"
#pragma once


using namespace std;

class OperatorComenzi: public Angajat{
protected:
    Comanda comenzi[3];
    int nrComenzi = 0;
    double bonusComenzi;
public:
    OperatorComenzi(int&, string&, string&, string&, tm&);
    int getNrComenzi() const;
    void preluareaComenzii(double);
    void calculeazaSalariu();
    void afiseazaDetalii();

};
