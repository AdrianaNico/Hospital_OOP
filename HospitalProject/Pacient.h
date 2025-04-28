#ifndef PACIENT_H
#define PACIENT_H

#include "Persoana.h"
#include <iostream>  // Pentru std::cout și std::endl
#include <vector>
using namespace std;

class Pacient : public Persoana {
private:
    vector<string> istoricMedical;

public:
    Pacient(string n, int v, string c) : Persoana(n, v, c) {}

    void adaugaConsultatie(string diagnostic) {
        istoricMedical.push_back(diagnostic);
    }

    void afisareDetalii() override {
        cout << "Pacient: " << nume << ", Varsta: " << varsta << ", CNP: " << CNP << endl;
        cout << "Istoric medical: ";
        for (const auto& diag : istoricMedical) {
            cout << diag << " ";
        }
        cout << endl;
    }
};

#endif // PACIENT_H
