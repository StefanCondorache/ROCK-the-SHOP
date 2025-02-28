#include <cstring>
#include <iostream>
#include <ctime>
#pragma once
#include "Angajat.h"

using namespace std;

class Asistent: public Angajat{
public:
    Asistent(const int&, const string&, const string&, const string&,const tm&);
    void calculeazaSalariu();
    void afiseazaDetalii();
};
