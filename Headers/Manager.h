#include <cstring>
#include <iostream>
#include <ctime>
#pragma once
#include "Angajat.h"

using namespace std;

class Manager: public Angajat{
public:
    Manager(const int&, string, string, string, tm);
    double calculeazaSalariu() override;
    void afiseazaDetalii();
};

