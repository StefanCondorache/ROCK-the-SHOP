#include <vector>
#include "Angajat.h"
#include "Produs.h"
#include "Comanda.h"
#pragma once

using namespace std;

class Magazin {
private:
    vector<Angajat*> angajati;
    vector<Produs*> produse;
    vector<Comanda> comenziInAsteptare;
    vector<Comanda> comenziProcesate;

public:
    Magazin();
    void adaugaAngajat(Angajat* angajat);
    void stergeAngajat(int id);
    void modificaAngajat(int id, string& nume, string& prenume);
    void afiseazaAngajat(int id) const;
    void afiseazaTotiAngajatii() const;

    void adaugaProdus(Produs* produs);
    void stergeProdus(int cod);
    void modificaStocProdus(int cod, int stoc);
    void afiseazaProdus(int cod) const;
    void afiseazaToateProdusele() const;

    void proceseazaComanda(const Comanda& comanda);
    void afiseazaRaport() const;
};

