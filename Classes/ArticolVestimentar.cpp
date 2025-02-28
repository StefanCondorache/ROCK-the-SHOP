#include <iostream>
#include <cstring>
#include "ArticolVestimentar.h"

using namespace std;

ArticolVestimentar::ArticolVestimentar(const int &cod, const string &nume, const int &stoc, const double &pret, const string &culoare, const string &marca)
    : Produs(cod, nume, stoc, pret), culoare(culoare), marca(marca) {}


void ArticolVestimentar::calculeazaPretFinal(){
    pretBaza += 20.0;
}

void ArticolVestimentar::afiseazaDetalii() const {
    cout << "Articol vestimentar: \n";
    Produs::afiseazaDetalii();
    cout << "Culoarea: " << culoare << endl;
    cout << "Marca: " << marca << endl;
}
