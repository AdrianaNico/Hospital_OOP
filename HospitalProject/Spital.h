#ifndef SPITAL_H
#define SPITAL_H

#include "Medic.h"
#include "Pacient.h"
#include "Consultatie.h"
#include <vector>

class Spital {
private:
    vector<Medic> medici;
    vector<Pacient> pacienti;
    vector<Consultatie> consultatii;

public:
    void adaugaMedic(Medic m) {
        medici.push_back(m);
    }

    void adaugaPacient(Pacient p) {
        pacienti.push_back(p);
    }

    void adaugaConsultatie(Pacient* p, Medic* m, string data, string diagnostic) {
        consultatii.push_back(Consultatie(p, m, data, diagnostic));
    }

    void afisareConsultatii() {
        for (auto& c : consultatii)
            c.afisareDetalii();
    }
};

#endif // SPITAL_H
