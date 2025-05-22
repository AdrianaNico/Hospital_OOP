#include "sectie_cardiologie.h"
#include <iostream>
#include <vector>

SectieCardiologie::SectieCardiologie() {}
SectieCardiologie::~SectieCardiologie() {}

void SectieCardiologie::AfisareSectie() {
    std::cout << "Sectia Cardiologie" << std::endl;
}

void SectieCardiologie::AdaugaMedicSectieCardiologie(const Medic& medic) {
    m_medici_sectie_cardiologie.push_back(medic);
}

void SectieCardiologie::GetMediciCardiologie() const {
    for (auto& medic : m_medici_sectie_cardiologie) {
        std::cout << medic.GetNumeMedic() << std::endl;
    }
}
