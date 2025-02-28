#include <iostream>
#include <cstring>
#include <ctime>
#include "OperatorComenzi.h"

using namespace std;

OperatorComenzi::OperatorComenzi(int &id, string &nume, string &prenume, string &cnp, tm &data_angajare):Angajat(id, nume, prenume, cnp, data_angajare, 1.0){}

void OperatorComenzi::calculeazaSalariu(){
    Angajat::calculeazaSalariu();
    this->salariu += this->bonusComenzi;
}

int OperatorComenzi::getNrComenzi() const {
    return nrComenzi;
}

void OperatorComenzi::preluareaComenzii(Comanda &comanda){
    this->comenzi[nrComenzi] = comanda;
    this->bonusComenzi += 0.005 * comanda->valoareComanda;
    this->nrComenzi++ ;
}

void OperatorComenzi::afiseazaDetalii(){
    cout << "Operator de comenzi: \n";
    Angajat::afiseazaDetalii();
}

