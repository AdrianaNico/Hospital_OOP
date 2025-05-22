#include "sectie_chirurgie.h"
#include <iostream>
#include <vector>

SectieChirurgie::SectieChirurgie() {}
SectieChirurgie::~SectieChirurgie() {}

void SectieChirurgie::AfisareSectie() {
    std::cout << "Sectia Chirurgie" << std::endl;
}

void SectieChirurgie::AdaugaMedicSectieChirurgie(const Medic& medic) {
    m_medici_sectie_chirurgie.push_back(medic);
}

void SectieChirurgie::GetMediciChirurgie() const {
    for (auto& medic : m_medici_sectie_chirurgie) {
        std::cout << medic.GetNumeMedic() << std::endl;
    }
}
