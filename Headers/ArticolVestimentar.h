#include <iostream>
#include "Produs.h"
#include <cstring>
#pragma once

using namespace std;

class ArticolVestimentar: public Produs{
    string culoare, marca;
public:
    ArticolVestimentar(const int&, const string&, const int&, const double&, const string&, const string&);
    void calculeazaPretFinal() override;
    void afiseazaDetalii() const override;
};
