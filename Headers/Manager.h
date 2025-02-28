#include <cstring>
#include <iostream>
#include <ctime>
#pragma once
#include "Angajat.h"

using namespace std;

class Manager: public Angajat{
public:
    Manager(int&, string&, string&, string&, tm&);
    void calculeazaSalariu();
    void afiseazaDetalii();
};

