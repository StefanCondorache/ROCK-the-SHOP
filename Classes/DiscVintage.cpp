#include <iostream>
#include <ctime>
#include <cstring>
#include "DiscVintage.h"

using namespace std;

DiscVintage::DiscVintage(const int &cod, const string &nume, int stoc, double pret, const string &casaDiscuri, const string &trupa, const string &album, const tm &dataLansare, bool mint, int coefRaritate)
    : Disc(cod, nume, stoc, pret, casaDiscuri, trupa, album, dataLansare), mint(mint) {
    if( coefRaritate >= 1 && coefRaritate <= 5){
        coeficientRaritate = coefRaritate;
    }
    else{
        throw invalid_argument("Coeficientul de raritate trebuie să fie între 1 și 5.");
    }
}

void DiscVintage::calculeazaPretFinal(){
    pretBaza += 5.0 + (15.0 * coeficientRaritate);
}

void DiscVintage::afiseazaDetalii() const {
    cout << "Disc vintaj: " << endl;
    Disc::afiseazaDetalii();
    cout << "Conditia mint: " << (mint ? "Da" : "Nu") << endl;
    cout << "Coeficientul de raritate: " << coeficientRaritate << endl;
}
