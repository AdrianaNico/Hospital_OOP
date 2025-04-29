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

    void adaugaPacient(Pacient* pacient);

    void afisareDetalii() override;
    void afisareConsultatii(const vector<Consultatie>& consultatii, Medic* medic) override;
    string getNumeMedic() const;
    string getSpecializare() const;
};

#endif // MEDIC_H
