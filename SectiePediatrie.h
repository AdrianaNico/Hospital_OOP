#ifndef PACIENT_H
#define PACIENT_H

#include "Sectie.h"
#include "Medic.h"
#include <iostream>
#include <vector>

class SectiePediatrie: public Sectie {
public:
    void afisareSectie() override {}
};

std::vector<Medic> mediciSectiePediatrie;

void adaugaMedicSectiePediatrie(const Medic& medic){}

#endif // PACIENT_H