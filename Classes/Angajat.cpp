#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Angajat.h"
#include "functions.h"

using namespace std;


Angajat::Angajat(const int &id, const string &nume, const string &prenume, const  string &cnp, const tm &dataAngajare, double coeficientSalarial):
    id(id), dataAngajare(dataAngajare), coeficientSalarial(coeficientSalarial)
{

    if( (nume.length() >= 3 &&  nume.length() <= 30) && (prenume.length() >= 3 &&  prenume.length() <= 30)){
        this->nume = nume;
        this->prenume = prenume;
    }

    if( isValidCNP(cnp) ){
        this->cnp = cnp;
    }
}

void Angajat::calculeazaSalariu(){
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    int yearsOfService = now->tm_year - this->dataAngajare.tm_year;
    this->salariu = (this->salariu + 100 * yearsOfService) * this->coeficientSalarial;
}

int Angajat::getId() const {
    return this->id;
}

string Angajat::getNume() const {
    return this->nume;
}

string Angajat::getPrenume() const {
    return this->prenume;
}

string Angajat::getCNP() const {
    return this->cnp;
}

tm Angajat::getDataAngajare() const {
    return this->dataAngajare;
}

void Angajat::setNumePrenume(string &nume_nou, string &prenume_nou){
    if( (nume_nou.length() >= 3 &&  nume_nou.length() <= 30) && (prenume_nou.length() >= 3 &&  prenume_nou.length() <= 30)){
        this->nume = nume_nou;
        this->prenume = prenume_nou;
    }
}

void Angajat::afiseazaDetalii(){
    cout << "ID: " << this->id << "\n";
    cout << "Nume: " << this->nume << "\n";
    cout << "Prenume: " << this->prenume << "\n";
    cout << "CNP: " << this->cnp << "\n";
    cout << "Data de angajare: " << this->dataAngajare.tm_mday << "/" << this->dataAngajare.tm_mon + 1 << "/" << this->dataAngajare.tm_year + 1900 << "\n";
    cout << "Salariu: " << calculeazaSalariu() << "\n";
}


