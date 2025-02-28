#include "Angajat.h"
#include "Produs.h"
#include "Comanda.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Magazin{
protected:
    vector<Angajat*> angajati;
    vector<Produs*> produse;
    vector<Comanda> comenzi;
public:
    Magazin() = default;
    ~Magazin();

    // Gestionarea angajatilor
    void adaugaAngajat(Angajat*);
    void stergeAngajat(int);
    void afiseazaAngajati() const;

    // Gestionarea produselor
    void adaugaProdus(Produs*);
    void stergeProdus(int);
    void modificaStoc(int, int);
    void afiseazaProduse() const;

    // Procesarea comenzilor
    void adaugaComanda(const Comanda&);
    void proceseazaComenzi();

    // Raportare
    Angajat* angajatCuCeleMaiMulteComenzi() const;
    vector<Angajat*> topAngajatiValoareComenzi() const;
    vector<Angajat*> topAngajatiSalarii() const;
    void genereazaRaportCSV(const string&, const vector<string>&) const;

};
