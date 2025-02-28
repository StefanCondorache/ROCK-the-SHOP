#include <iostream>
#include <ctime>
#include "Produs.h"
#include <cstring>
#pragma once

using namespace std;

class Disc: public Produs{
private:
    string casaDiscuri, trupa, album;
    tm dataLansare;
public:
    Disc(const int&, const string&, const int, const double, const string&, const string&, const string&, const tm&);
    void calculeazaPretFinal() override;
    void afiseazaDetalii() const override;

};
