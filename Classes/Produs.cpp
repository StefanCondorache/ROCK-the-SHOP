#include <iostream>
#include "Produs.h"
#include <cstring>

using namespace std;

Produs::Produs(const int &cod, const string &denumire, int stoc, double pretBaza):
   codProdus(cod), denumire(denumire), stoc(stoc), pretBaza(pretBaza) {}


int Produs::getCod() const {
    return codProdus;
}

string Produs::getDenumire() const {
    return denumire;
}

int Produs::getStoc() const {
    return stoc;
}

double Produs::getPretBaza() const {
    return pretBaza;
}

void Produs::setStoc(int stoc){
    this->stoc = stoc;
}

void Produs::calculeazaPretFinal() {
    this->pretBaza = 0;
}


void Produs::afiseazaDetalii() const {
    cout << "Cod: " << codProdus << "\n";
    cout << "Denumire produs: " << denumire << "\n";
    cout << "Cantitatea stocului: " << stoc << "\n";
    cout << "Pret de baza: " << pretBaza << "\n";
}
