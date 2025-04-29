#ifndef SPITAL_H
#define SPITAL_H

#include "Medic.h"
#include "Pacient.h"
#include "Consultatie.h"
#include "Persoana.h"
#include "Reteta.h"
#include <vector>
#include <string>
#include <iostream>

class Spital {
private:
    std::vector<Medic> medici;
    std::vector<Pacient> pacienti;
    std::vector<Consultatie> consultatii;

public:
    void adaugaMedic(Medic m);
 
    void adaugaPacient(Pacient p);

    void adaugaConsultatie(Consultatie c);

    void afisareConsultatii();

    std::vector<Medic>& getMedici();

    std::vector<Consultatie>& getConsultatii();

    Pacient* cautaPacient(std::string nume);

    Medic* cautaMedic(std::string nume);
};

#endif // SPITAL_H
