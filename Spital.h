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

    void adaugaConsultatie(Consultatie c) {
        consultatii.push_back(c);
    }

    void afisareConsultatii() {
        for (auto& c : consultatii)
            c.afisareDetalii();
    }

    vector<Medic>& getMedici() {
        return medici;
    }
    vector<Consultatie>& getConsultatii() {
        return consultatii;
    }

    Pacient* cautaPacient(string nume)
    {
        for (auto& pacient : pacienti)
        {
            if (pacient.getNumePacient() == nume)
            {
                cout << "Pacient gasit: " << pacient.getNumePacient() << endl;
                return &pacient;
            }
        }
        return nullptr;
    }

    Medic* cautaMedic(string nume)
    {
        for (auto& medic : medici)
        {
            if (medic.getNumeMedic() == nume)
            {
                cout << "Medic gasit: " << medic.getNumeMedic() << endl;
                return &medic;
            }
        }
        return nullptr;
    }
    
};

#endif // SPITAL_H
