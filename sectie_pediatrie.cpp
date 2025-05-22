#include "sectie_pediatrie.h"
#include "medic.h"
#include <iostream>
#include <vector>

SectiePediatrie::SectiePediatrie() {}
SectiePediatrie::~SectiePediatrie() {}

void SectiePediatrie::AfisareSectie() {
    std::cout << "Sectia Pediatrie" << std::endl;
}

void SectiePediatrie::GetMediciPediatrie() const {
    for (auto& medic : m_medici_sectie_pediatrie) {
        std::cout << medic.GetNumeMedic() << std::endl;
    }
}

void SectiePediatrie::AdaugaMedicSectiePediatrie(const Medic& medic) {
    m_medici_sectie_pediatrie.push_back(medic);
}
