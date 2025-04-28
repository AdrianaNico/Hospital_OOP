#ifndef SPITAL_H
#define SPITAL_H

#include "Medic.h"
#include "Pacient.h"
#include "Consultatie.h"
#include <vector>
#include <string>
#include <iostream>

class Spital {
private:
    std::vector<Medic> medici;
    std::vector<Pacient> pacienti;
    std::vector<Consultatie> consultatii;

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

    std::vector<Medic>& getMedici() {
        return medici;
    }

    std::vector<Consultatie>& getConsultatii() {
        return consultatii;
    }

    Pacient* cautaPacient(std::string nume)
    {
        for (auto& pacient : pacienti)
        {
            if (pacient.getNumePacient() == nume)
            {
                std::cout << "Pacient gasit: " << pacient.getNumePacient() << std::endl;
                return &pacient;
            }
        }
        return nullptr;
    }

    Medic* cautaMedic(std::string nume)
    {
        for (auto& medic : medici)
        {
            if (medic.getNumeMedic() == nume)
            {
                std::cout << "Medic gasit: " << medic.getNumeMedic() << std::endl;
                return &medic;
            }
        }
        return nullptr;
    }
};

#endif // SPITAL_H
