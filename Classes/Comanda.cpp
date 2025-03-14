#include "Comanda.h"
#include <iostream>

using namespace std;

Comanda::Comanda(int id, const tm& data, int durata)
    : idComanda(id), dataComenzii(data), durata(durata), valoare(0.0) {}

int Comanda::getIdComanda() const {
    return idComanda;
}

tm Comanda::getDataComenzii() const {
    return dataComenzii;
}

int Comanda::getDurata() const {
    return durata;
}

double Comanda::getValoare() const {
    return valoare;
}

void Comanda::adaugaProdus(Produs* produs) {
    produse.push_back(produs);
    calculeazaValoare();
}

void Comanda::calculeazaValoare() {
    valoare = 0.0;
    for (const auto& produs : produse) {
        valoare += produs->getPretBaza();
    }
}

vector<Produs*> Comanda::getProduse() const {
    return produse;
}

void Comanda::afiseazaDetalii() const {
    std::cout << "ID Comanda: " << idComanda << "\n";
    std::cout << "Data Comenzii: " << dataComenzii.tm_mday << "/" << dataComenzii.tm_mon + 1 << "/" << dataComenzii.tm_year + 1900 << "\n";
    std::cout << "Durata: " << durata << "\n";
    std::cout << "Valoare: " << valoare << "\n";
    std::cout << "Produse:\n";
    for (const auto& produs : produse) {
        produs->afiseazaDetalii();
    }
}
