#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include "Angajat.h"
#include "Manager.h"
#include "Asistent.h"
#include "OperatorComenzi.h"
#include "Magazin.h"
#include "Disc.h"
#include "DiscVintage.h"
#include "ArticolVestimentar.h"

using namespace std;

bool isValidCNP(const string& cnp) {
    if (cnp.length() != 13) {
        return false;
    }

    for (char c : cnp) {
        if (!isdigit(c)) {
            return false;
        }
    }

    vector<int> factors = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};

    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        sum += (cnp[i] - '0') * factors[i];
    }

    int remainder = sum % 11;
    int controlDigit = (remainder == 10) ? 1 : remainder;

    return controlDigit == (cnp[12] - '0');
}

bool isAtLeast18YearsOld(const std::string& cnp) {
    if (cnp.length() != 13) {
        throw std::invalid_argument("CNP must be 13 characters long");
    }

    int year, month, day;

    // Extract birth date from CNP
    int century = (cnp[0] - '0');
    if (century == 1 || century == 2) {
        year = 1900 + std::stoi(cnp.substr(1, 2));
    } else if (century == 3 || century == 4) {
        year = 1800 + std::stoi(cnp.substr(1, 2));
    } else if (century == 5 || century == 6) {
        year = 2000 + std::stoi(cnp.substr(1, 2));
    } else {
        throw std::invalid_argument("Invalid century digit in CNP");
    }

    month = std::stoi(cnp.substr(3, 2));
    day = std::stoi(cnp.substr(5, 2));

    // Get current date
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    // Calculate age
    int age = now->tm_year + 1900 - year;
    if (now->tm_mon + 1 < month || (now->tm_mon + 1 == month && now->tm_mday < day)) {
        age--;
    }

    return age >= 18;
}

bool isValidMarket(Magazin& market){
    int nrManager = 0;
    int nrOperator = 0;
    int nrAsistent = 0;
    for(const auto& angajat : market->angajati){
        if( typeof(angajat) == typeof(Manager) ){ nrManager++; }
        if( decltype(angajat) == decltype(OperatorComenzi) ){ nrOperator++; }
        if( decltype(angajat) == decltype(Asistent) ){ nrAsistent++; }
    }
    return ( nrManager == 1 && nrOperator >= 3 && nrAsistent >= 1);


}

bool gotEnoughStuff(Magazin &market){
    int nrDisc = 0;
    int nrVintage = 0;
    int nrArticol = 0;
    for(auto produs : market->produse){
        if( decltype(produs) == decltype(Disc){ nrDisc++; }
        if( decltype(produs) == decltype(DiscVintage){ nrVintage++; }
        if( decltype(produs) == decltype(ArticolVestimentar){ nrArticol++; }
    }
    return ( nrDisc >= 2 && nrVintage >= 2 && nrArticol >= 2 );
}
