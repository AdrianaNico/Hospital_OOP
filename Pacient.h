#ifndef PACIENT_H
#define PACIENT_H

#include "Persoana.h"
#include <iostream>
#include <vector>

class Medic; // Forward declaration pentru a evita includerea ciclică

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
        cout << "Pacient: " << nume << ", Varsta: " << varsta << endl;
        cout << "Istoric medical: ";
        for (const auto& diag : istoricMedical) {
            cout << diag << "; ";
        }
        cout << endl;
    }

    void adaugaIstoricMedical(const string& i) {
        istoricMedical.push_back(i);
    }
    vector<string> getIstoricMedical() {
        return istoricMedical;
    }

    void afisareConsultatii(const vector<Consultatie>& consultatii, Medic* medic) override {
        cout << "Consultatiile pacientului "<<endl;
    }
    

    string getNumePacient() const {
        return nume;
    }

};

#endif // PACIENT_H
