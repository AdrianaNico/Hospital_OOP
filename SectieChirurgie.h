#ifndef SECTIECHIRURGIE_H
#define SECTIECHIRURGIE_H

#include "Sectie.h"
#include "Medic.h"
#include <iostream>
#include <vector>

class SectieChirurgie: public Sectie {
private:
    std::vector<Medic> mediciSectieChirurgie;
public:
    SectieChirurgie() {}
    ~SectieChirurgie() {}
    void afisareSectie() override;
    void adaugaMedicSectieChirurgie(const Medic& medic);
    void getMediciChirurgie() const;
};
#endif