#include <iostream>
#include <vector>
#include <ctime>
#include "Produs.h"
#pragma once

using namespace std;

class Comanda{
    int idComanda;
    vector<Produs*> produseComandate;
    double valoareComanda = 0.0;
    int procesareTimp;
    tm dataComanda;

public:
    Comanda(const int&, const vector<Produs*> &, const tm&, int procesareTimp);

    int getIdComanda() const;
    vector<Produs*> getComenzi() const;
    tm getDataComanda() const;
    int getProcesareTimp() const;
    double getValoareComanda() const;
    void calculeazaValoareComanda();
    bool comandaValida() const;
    void afisareaComenzii() const;
};
