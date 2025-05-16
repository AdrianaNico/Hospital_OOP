#ifndef PACIENT_H
#define PACIENT_H

#include "Sectie.h"
#include "Medic.h"
#include <iostream>
#include <vector>

class SectieCardiologie: public Sectie {
public:
    void afisareSectie() override {}
};

std::vector<Medic> mediciSectieCardiologie;

void adaugaMedicSectieCardiologie(const Medic& medic){}

#endif // PACIENT_H