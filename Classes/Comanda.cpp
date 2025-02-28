#include <iostream>
#include "Comanda.h"
#include "Disc.h"
#include "DiscVintage.h"
#include "ArticolVestimentar.h"
#include <cstring>
#include <ctime>

using namespace std;

Comanda::Comanda(const int &id, const vector<Produs*> &produse, const tm &dataComanda, int procesareTimp):
    idComanda(id), produseComandate(produse), dataComanda(dataComanda), procesareTimp(procesareTimp), valoareComanda(0.0) {
    calculeazaValoareComanda();
}

void Comanda::calculeazaValoareComanda(){
    for(const auto &produs : produseComandate){
        this->valoareComanda += produs->getPretBaza();
    }
}


int Comanda::getIdComanda() const {
    return idComanda;
}

vector<Produs*> Comanda::getComenzi() const {
    return produseComandate;
}

tm Comanda::getDataComanda() const{
    return dataComanda;
}

int Comanda::getProcesareTimp() const{
    return procesareTimp;
}

double Comanda::getValoareComanda() const{
    return valoareComanda;
}

bool Comanda::comandaValida() const {
    if( valoareComanda < 100.0) return false;

    int nrDisc = 0;
    int nrArticol = 0;
    for(const auto &produs : produseComandate){
        if(dynamic_cast<Disc*>(produs) != nullptr || dynamic_cast<DiscVintage*>(produs) != nullptr){
            nrDisc++;
        }
        else if ( dynamic_cast<ArticolVestimentar*>(produs) != nullptr ){
            nrArticol++;
        }
    }
    return nrDisc <= 5 && nrArticol <= 3;
}

void Comanda::afisareaComenzii() const{
    cout << "Id comanda: " << idComanda << "\n";
    cout << "Data Comenzii: " << dataComanda.tm_mday << "/" << dataComanda.tm_mon + 1 << "/" << dataComanda.tm_year + 1900 << "\n";
    cout << "Durata de procesare: " << procesareTimp << " units\n";
    cout << "Valoarea comenzii: " << valoareComanda << "\n";
    cout << "Produse:\n";
    for (const auto &produs : produseComandate) {
        produs->afiseazaDetalii();
        cout << "-------------------\n";
    }
}

