#include "Angajat.h"
#include "Manager.h"
#include "Asistent.h"
#include "OperatorComenzi.h"
#include "Produs.h"
#include "Comanda.h"
#include "OperatorComenzi.h"
#include "Magazin.h"
#include "functions.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <typeinfo>

using namespace std;

Magazin::~Magazin() {
    for (auto angajat : angajati){
        delete angajat;
    }
    for (auto produs : produse){
        delete produs;
    }
}

// Gestionarea angajatilor
void Magazin::adaugaAngajat(Angajat* angajat){
    if( isAtLeast18YearsOld(angajat.cnp) ){
        angajati.push_back(angajat);
    }
}

void Magazin::stergeAngajat(int id){
    for(int i = 0; i < angajati.size(); i++){
        if( angajati[i]->getId() == id){
            delete angajati[i];
            angajati.erase(angajati.begin() + i);
            break;
        }
    }
}

void Magazin::afiseazaAngajati() const {
    if( isValidMarket(*this) ){
        for(const auto& angajat : angajati){
            angajat->afiseazaDetalii();
        }
    }
    else{
        cout << "Magazinul nu poate functiona, deoarece nu are stuff-ul minim (un manager, minim 3 operatori de comenzi, și un asistent)" << endl;
    }

}

// Gestionarea produselor

void Magazin::adaugaProdus(Produs* produs) {
    produse.push_back(produs);
}

void Magazin::stergeProdus(int id){
    for(int i = 0; i < produse.size(); i++){
        if( produse[i]->getCod() == id){
            delete produse[i];
            produse.erase(produse.begin() + i);
            break;
        }
    }
}

void Magazin::modificaStoc(int id, int stoc){
    for(auto produs : produse){
        if(produs->getCod() == id){
            produs->setStoc(stoc);
        }
    }
}

void Magazin::afiseazaProduse() const {
    if( gotEnoughStuff(*this) ){
        for(const auto& produs : produse){
            produs->afiseazaDetalii();
        }
    }
}

// Procesarea comenzilor

void Magazin::adaugaComanda(const Comanda& comanda) {
    if (comanda.comandaValida()) {
        comenzi.push_back(comanda);
    } else {
        cout << "Comanda nu este valida si nu poate fi procesata.\n";
    }

}

void Magazin::proceseazaComenzi() {
    for (auto& comanda : comenzi) {
        bool atribuit = false;
        for (auto& angajat : angajati) {
            OperatorComenzi* Operator = dynamic_cast<OperatorComenzi*>(angajat);
            if (Operator && Operator->getNrComenzi() < 3) {
                Operator->preluareaComenzii(comanda);
                atribuit = true;
                break;
            }
        }
        if (!atribuit) {
            cout << "Nu exista operatori disponibili pentru a procesa comanda: " << comanda.getIdComanda() << "\n";
        }
    }
}


