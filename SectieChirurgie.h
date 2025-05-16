#ifndef PACIENT_H
#define PACIENT_H

#include "Sectie.h"
#include "Medic.h"
#include <iostream>
#include <vector>

class SectieChirurgie: public Sectie {
public:
    void afisareSectie() override {}
};

std::vector<Medic> mediciSectieChirurgie;

void adaugaMedicSectieChirurgie(const Medic& medic){}

#endif // PACIENT_H