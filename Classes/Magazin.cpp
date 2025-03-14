#include "Magazin.h"
#include "Disc.h"
#include "ArticolVestimentar.h"
#include "OperatorComenzi.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

Magazin::Magazin() {}

void Magazin::adaugaAngajat(Angajat* angajat) {
    angajati.push_back(angajat);
}

void Magazin::stergeAngajat(int id) {
    int i = 0;
    for(auto &angajat : angajati){
        i++;
        if( angajat->getId() == id ){
            angajati.erase(angajati.begin() + i);
            break;
        }
    }
}

void Magazin::modificaAngajat(int id, string& nume, string& prenume) {
    for (auto& angajat : angajati) {
        if (angajat->getId() == id) {
            angajat->setNumePrenume(nume, prenume);
        }
    }
}

void Magazin::afiseazaAngajat(int id) const {
    for (const auto& angajat : angajati) {
        if (angajat->getId() == id) {
            angajat->afiseazaDetalii();
        }
    }
}

void Magazin::afiseazaTotiAngajatii() const {
    for (const auto& angajat : angajati) {
        angajat->afiseazaDetalii();
    }
}

void Magazin::adaugaProdus(Produs* produs) {
    produse.push_back(produs);
}

void Magazin::stergeProdus(int cod) {
    int i = 0;
    for(auto &produs : produse){
        i++;
        if( produs->getCod() == cod ){
            produse.erase(produse.begin() + i);
            break;
        }
    }
}

void Magazin::modificaStocProdus(int cod, int stoc) {
    for (auto& produs : produse) {
        if (produs->getCod() == cod) {
            produs->setStoc(stoc);
        }
    }
}

void Magazin::afiseazaProdus(int cod) const {
    for (const auto& produs : produse) {
        if (produs->getCod() == cod) {
            produs->afiseazaDetalii();
        }
    }
}

void Magazin::afiseazaToateProdusele() const {
    for (const auto& produs : produse) {
        produs->afiseazaDetalii();
    }
}

void Magazin::proceseazaComanda(const Comanda& comanda) {
   if (comanda.getValoare() < 100.0) {
        std::cerr << "Comanda nu îndeplinește valoarea minimă de 100 RON.\n";
        return;
    }

    if (comanda.getProduse().size() > 8) {
        std::cerr << "Comanda conține prea multe produse.\n";
        return;
    }

    int nrDiscuri = 0;
    int nrArticole = 0;
    for (const auto& produs : comanda.getProduse()) {
        if (typeid(produs).name() == typeid(Disc).name()) {
            nrDiscuri++;
        } else if (typeid(produs).name() == typeid(ArticolVestimentar).name()) {
            nrArticole++;
        }
    }

    if (nrDiscuri > 5) {
        std::cerr << "Comanda conține prea multe discuri.\n";
        return;
    }

    if (nrArticole > 3) {
        std::cerr << "Comanda conține prea multe articole vestimentare.\n";
        return;
    }

    OperatorComenzi* operatorDisponibil = nullptr;
    for (auto& angajat : angajati) {
        OperatorComenzi* operatorComenzi = dynamic_cast<OperatorComenzi*>(angajat);
        if (operatorComenzi && operatorComenzi->getNrComenzi() < 3) {
            operatorDisponibil = operatorComenzi;
            break;
        }
    }

    if (operatorDisponibil) {
        operatorDisponibil->preluareaComenzii(comanda);
        comenziProcesate.push_back(comanda);
        std::cout << "Comanda a fost atribuită operatorului de comenzi cu ID-ul " << operatorDisponibil->getId() << ".\n";
    } else {
        std::cerr << "Nu există operatori de comenzi disponibili. Comanda a fost plasată în așteptare.\n";
        comenziInAsteptare.push_back(comanda);
    }
}

void Magazin::afiseazaRaport() const {
    // 1. Angajatul cu cele mai multe comenzi procesate
    auto maxComenzi = std::max_element(angajati.begin(), angajati.end(), [](Angajat* a, Angajat* b) {
        OperatorComenzi* operatorA = dynamic_cast<OperatorComenzi*>(a);
        OperatorComenzi* operatorB = dynamic_cast<OperatorComenzi*>(b);
        if (operatorA && operatorB) {
            return operatorA->getNrComenzi() < operatorB->getNrComenzi();
        }
        return false;
    });

    if (maxComenzi != angajati.end()) {
        std::cout << "Angajatul cu cele mai multe comenzi procesate:\n";
        (*maxComenzi)->afiseazaDetalii();
    }

    // 2. Top 3 angajați care au gestionat cele mai valoroase comenzi
    std::vector<OperatorComenzi*> operatori;
    for (auto* angajat : angajati) {
        if (auto* operatorComenzi = dynamic_cast<OperatorComenzi*>(angajat)) {
            operatori.push_back(operatorComenzi);
        }
    }

    std::sort(operatori.begin(), operatori.end(), [](OperatorComenzi* a, OperatorComenzi* b) {
        return a->getBonusComenzi() > b->getBonusComenzi();
    });

    std::cout << "Top 3 angajați care au gestionat cele mai valoroase comenzi:\n";
    for (size_t i = 0; i < 3 && i < operatori.size(); ++i) {
        operatori[i]->afiseazaDetalii();
    }

    // 3. Top 3 angajați cu cel mai mare salariu în luna curentă
    std::vector<Angajat*> angajatiNonConst = angajati;
    std::sort(angajatiNonConst.begin(), angajatiNonConst.end(), [](Angajat* a, Angajat* b) {
        return a->calculeazaSalariu() > b->calculeazaSalariu();
    });

    std::cout << "Top 3 angajați cu cel mai mare salariu în luna curentă:\n";
    for (size_t i = 0; i < 3 && i < angajatiNonConst.size(); ++i) {
        angajatiNonConst[i]->afiseazaDetalii();
    }

    // Salvare rapoarte în fișiere .csv
    std::ofstream raport1("raport1.csv");
    raport1 << "ID,Nume,Prenume,Salariu\n";
    if (maxComenzi != angajati.end()) {
        raport1 << (*maxComenzi)->getId() << ",";
        raport1 << (*maxComenzi)->getNume() << ",";
        raport1 << (*maxComenzi)->getPrenume() << ",";
        raport1 << (*maxComenzi)->calculeazaSalariu() << "\n";
    }
    raport1.close();

    std::ofstream raport2("raport2.csv");
    raport2 << "ID,Nume,Prenume,Salariu\n";
    for (size_t i = 0; i < 3 && i < operatori.size(); ++i) {
        raport2 << operatori[i]->getId() << ",";
        raport2 << operatori[i]->getNume() << ",";
        raport2 << operatori[i]->getPrenume() << ",";
        raport2 << operatori[i]->calculeazaSalariu() << "\n";
    }
    raport2.close();

    std::ofstream raport3("raport3.csv");
    raport3 << "ID,Nume,Prenume,Salariu\n";
    for (size_t i = 0; i < 3 && i < angajatiNonConst.size(); ++i) {
        raport3 << angajatiNonConst[i]->getId() << ",";
        raport3 << angajatiNonConst[i]->getNume() << ",";
        raport3 << angajatiNonConst[i]->getPrenume() << ",";
        raport3 << angajatiNonConst[i]->calculeazaSalariu() << "\n";
    }
    raport3.close();
}
