#include <iostream>
#include <cstring>
#include <ctime>
#include "Disc.h"

using namespace std;

Disc::Disc(const int &cod, const string &nume, int stoc, const double pret, const string &casaDiscuri, const string &trupa, const string &album, const tm &dataLansare)
    : Produs(cod, nume, stoc, pret), casaDiscuri(casaDiscuri), dataLansare(dataLansare), trupa(trupa), album(album){}

void Disc::calculeazaPretFinal(){
    pretBaza += 5.0;
}

void Disc::afiseazaDetalii() const {
    cout << "Disc: \n";
    Produs::afiseazaDetalii();
    cout << "Casa de dicuri: " << casaDiscuri << endl;
    cout << "Data de lansare: " << dataLansare.tm_mday << "/" << dataLansare.tm_mon + 1 << "/" << dataLansare.tm_year + 1900 << endl;
    cout << "Trupa: " << trupa << endl;
    cout << "Album: " << album << endl;
}
