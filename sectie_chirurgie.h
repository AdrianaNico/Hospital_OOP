#ifndef SECTIE_CHIRURGIE_H
#define SECTIE_CHIRURGIE_H

#include "sectie.h"
#include "medic.h"
#include <iostream>
#include <vector>

class SectieChirurgie : public Sectie {
private:
    std::vector<Medic> m_medici_sectie_chirurgie;
public:
    SectieChirurgie();
    ~SectieChirurgie() override;

    void AfisareSectie() override;
    void AdaugaMedicSectieChirurgie(const Medic& medic);
    void GetMediciChirurgie() const;
};

#endif // SECTIE_CHIRURGIE_H
