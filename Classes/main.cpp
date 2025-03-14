#include <iostream>
#include <ctime>
#include "Magazin.h"
#include "Manager.h"
#include "OperatorComenzi.h"
#include "Asistent.h"
#include "ArticolVestimentar.h"
#include "Disc.h"
#include "DiscVintage.h"

using namespace std;

int main() {
    // Crearea magazinului
    Magazin magazin;

    // Crearea datelor de test
    tm dataAngajare;
    dataAngajare.tm_year = 2025 - 1900;
    dataAngajare.tm_mon = 5; // Iunie (0-based, deci 5 înseamnă iunie)
    dataAngajare.tm_mday = 15;

    // Adăugarea angajaților
    Angajat* manager = new Manager(1, "Popescu", "Ion", "1234567890123", dataAngajare);
    Angajat* operator1 = new OperatorComenzi(2, "Ionescu", "Maria", "2234567890123", dataAngajare);
    Angajat* operator2 = new OperatorComenzi(3, "Georgescu", "Andrei", "3234567890123", dataAngajare);
    Angajat* operator3 = new OperatorComenzi(4, "Dumitrescu", "Ana", "4234567890123", dataAngajare);
    Angajat* asistent = new Asistent(5, "Vasilescu", "Elena", "5234567890123", dataAngajare);

    magazin.adaugaAngajat(manager);
    magazin.adaugaAngajat(operator1);
    magazin.adaugaAngajat(operator2);
    magazin.adaugaAngajat(operator3);
    magazin.adaugaAngajat(asistent);

    // Adăugarea produselor
    Produs* articol1 = new ArticolVestimentar(101, "Tricou Metallica", 50, 100.0, "Negru", "Metallica");
    Produs* articol2 = new ArticolVestimentar(102, "Geaca Rock", 20, 250.0, "Rosu", "Rock Brand");
    Produs* disc1 = new Disc(201, "Album Metallica", 30, 50.0, "Metallica Records", "Metallica", "Black Album", dataAngajare);
    Produs* disc2 = new Disc(202, "Album Iron Maiden", 40, 60.0, "Iron Maiden Records", "Iron Maiden", "Powerslave", dataAngajare);
    Produs* discVintage1 = new DiscVintage(301, "Album Vintage Beatles", 10, 100.0, "Beatles Records", "The Beatles", "Abbey Road", dataAngajare, true, 5);

    magazin.adaugaProdus(articol1);
    magazin.adaugaProdus(articol2);
    magazin.adaugaProdus(disc1);
    magazin.adaugaProdus(disc2);
    magazin.adaugaProdus(discVintage1);

    // Crearea comenzilor
    tm dataComanda;
    dataComanda.tm_year = 2025 - 1900;
    dataComanda.tm_mon = 2; // Martie (0-based, deci 2 înseamnă martie)
    dataComanda.tm_mday = 14;

    Comanda comanda1(1, dataComanda, 5);
    comanda1.adaugaProdus(articol1);
    comanda1.adaugaProdus(disc1);

    Comanda comanda2(2, dataComanda, 3);
    comanda2.adaugaProdus(articol2);
    comanda2.adaugaProdus(disc2);
    comanda2.adaugaProdus(discVintage1);

    magazin.proceseazaComanda(comanda1);
    magazin.proceseazaComanda(comanda2);

    // Afișarea rapoartelor
    magazin.afiseazaRaport();

    // Afișarea angajaților și produselor
    cout << "\nAngajati:\n";
    magazin.afiseazaTotiAngajatii();

    cout << "\nProduse:\n";
    magazin.afiseazaToateProdusele();

    return 0;
}

