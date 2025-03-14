#include <vector>
#include <ctime>
#include "Produs.h"
#pragma once

using namespace std;

class Comanda {
private:
    int idComanda;
    tm dataComenzii;
    int durata;
    double valoare;
    vector<Produs*> produse;

public:
    Comanda(int id, const tm& data, int durata);
    int getIdComanda() const;
    tm getDataComenzii() const;
    int getDurata() const;
    double getValoare() const;
    void adaugaProdus(Produs* produs);
    void calculeazaValoare();
    void afiseazaDetalii() const;
    vector<Produs*> getProduse() const;
};

