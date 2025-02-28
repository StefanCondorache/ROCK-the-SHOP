#include "Asistent.h"
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;


Asistent::Asistent(const int &id, const string &nume, const string &prenume, const string &cnp, const tm &dataAngajare):
    Angajat(id, nume, prenume, cnp, dataAngajare, 0.75) {}

void Asistent::calculeazaSalariu() {
    Angajat::calculeazaSalariu();
}

void Asistent::afiseazaDetalii(){
    cout << "Asistent: \n";
    Angajat::afiseazaDetalii();
}
