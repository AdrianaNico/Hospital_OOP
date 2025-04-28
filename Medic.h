#ifndef MEDIC_H
#define MEDIC_H

#include "Persoana.h"
#include "Pacient.h"
#include "Consultatie.h"
#include <string>
#include <iostream>
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
        cout<<"se afiseaza detaliile medicului"<<endl;
        cout << "Medic: " << nume << ", Specializare: " << specializare << endl;
        cout << "Pacienti: ";
        // for (const auto& pacient : pacienti) {
        //     cout << pacient->getNumePacient();//eroare aici
        //     for( const auto& diag :pacient->getIstoricMedical()) {
        //         cout << diag << ", ";
        //     }
        // }
        cout << endl;
    }

    void afisareConsultatii(const vector<Consultatie>& consultatii, Medic* medic) override{
        if (consultatii.empty()) {
            cout << "Nu exista consultatii." << endl;
            return;
        }
        for(auto& consultatie : consultatii)
        if (consultatie.getMedic()->getNumeMedic() == medic->getNumeMedic())
        {
            cout<<"Pacient: "<<consultatie.getPacient()->getNumePacient()<<" in data de "<<consultatie.getData()<<endl;
        }
    }
    string getNumeMedic() const {
        return nume;
    }
    string getSpecializare() const {
        return specializare;
    }
};

#endif // MEDIC_H
