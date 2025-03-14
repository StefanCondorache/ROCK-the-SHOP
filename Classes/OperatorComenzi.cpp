#include <iostream>
#include <cstring>
#include <ctime>
#include "OperatorComenzi.h"

using namespace std;

OperatorComenzi::OperatorComenzi(const int &id, const string &nume, const string &prenume, const string &cnp, tm &data_angajare):
    Angajat(id, nume, prenume, cnp, data_angajare, 1.0){}

double OperatorComenzi::calculeazaSalariu(){
    Angajat::calculeazaSalariu();
    this->salariu += this->bonusComenzi;
    return this->salariu;
}

int OperatorComenzi::getNrComenzi() const {
    return this->nrComenzi;
}

double OperatorComenzi::getBonusComenzi() const {
    return this->bonusComenzi;
}

void OperatorComenzi::preluareaComenzii(const Comanda& comanda) {
    this->bonusComenzi += 0.005 * comanda.getValoare();
    this->nrComenzi++;
}

void OperatorComenzi::afiseazaDetalii(){
    cout << "Operator de comenzi: \n";
    Angajat::afiseazaDetalii();
}

