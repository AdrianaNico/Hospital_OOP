#ifndef SECTIECARDIOLOGIE_H
#define SECTIECARDIOLOGIE_H

#include "Sectie.h"
#include "Medic.h"
#include <iostream>
#include <vector>

class SectieCardiologie: public Sectie {
public:
    void afisareSectie() override;
    void adaugaMedicSectieCardiologie(const Medic& medic);
    void getMediciCardiologie() const;
private:
    std::vector<Medic> mediciSectieCardiologie;
};

#endif