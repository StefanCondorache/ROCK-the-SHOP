#include <cstring>
#include <iostream>
#include <ctime>
#include "Manager.h"

using namespace std;

Manager::Manager(int &id, string &nume, string &prenume, string &cnp, tm &dataAngajare):Angajat(id, nume, prenume, cnp, dataAngajare, 1.25){}


void Manager::calculeazaSalariu(){
    Angajat::calculeazaSalariu();
}

void Manager::afiseazaDetalii(){
    cout << "Manager: \n";
    Angajat::afiseazaDetalii();
}
