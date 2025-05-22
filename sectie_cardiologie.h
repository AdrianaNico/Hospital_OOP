#ifndef SECTIE_CARDIOLOGIE_H
#define SECTIE_CARDIOLOGIE_H

#include "sectie.h"
#include "medic.h"
#include <iostream>
#include <vector>

class SectieCardiologie : public Sectie {
public:
    SectieCardiologie(); // constructor implicit
    ~SectieCardiologie() override;

    void AfisareSectie() override;
    void AdaugaMedicSectieCardiologie(const Medic& medic);
    void GetMediciCardiologie() const;

private:
    std::vector<Medic> m_medici_sectie_cardiologie;
};

#endif // SECTIE_CARDIOLOGIE_H
