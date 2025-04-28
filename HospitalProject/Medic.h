#ifndef MEDIC_H
#define MEDIC_H

#include "Persoana.h"
#include "Pacient.h"  // Adăugat pentru a include definiția clasei Pacient
#include <iostream>  // Pentru std::cout și std::endl
#include <vector>
using namespace std;

class Medic : public Persoana {
private:
    string specializare;
    vector<Pacient*> pacienti;  // Folosim vector de pointeri la Pacient

public:
    Medic(string n, int v, string c, string s) : Persoana(n, v, c), specializare(s) {}

    void adaugaPacient(Pacient* pacient) {
        pacienti.push_back(pacient);
    }

    void afisareDetalii() override {
        cout << "Medic: " << nume << ", Specializare: " << specializare << endl;
        cout << "Pacienti: ";
        for (const auto& pacient : pacienti) {
            cout << pacient->getNume() << " ";
        }
        cout << endl;
    }
};

#endif // MEDIC_H
