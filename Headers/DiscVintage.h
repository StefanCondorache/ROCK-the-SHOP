#include <iostream>
#include <ctime>
#include "Disc.h"
#include <cstring>
#pragma once

using namespace std;

class DiscVintage: public Disc{
protected:
    bool mint;
    int coeficientRaritate;
public:
    DiscVintage(const int&, const string&, int, double, const string&, const string&, const string&, const tm&, bool, int);
    void calculeazaPretFinal() override;
    void afiseazaDetalii() const override;
};
