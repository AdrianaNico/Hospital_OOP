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

    void adaugaConsultatie(string diagnostic);

    void afisareDetalii() override;

    void adaugaIstoricMedical(const string& i);
    vector<string> getIstoricMedical();

    void afisareConsultatii(const vector<Consultatie>& consultatii, Medic* medic) override;

    string getNumePacient() const;

};

#endif // PACIENT_H
