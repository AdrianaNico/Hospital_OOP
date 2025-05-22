#include "reteta.h"
#include <iostream>

int Reteta::m_nr_reteta = 0;

Reteta::Reteta(Pacient* pacient, Medic* medic, const std::vector<std::string>& medicamente)
    : m_pacient(pacient), m_medic(medic), m_medicamente(medicamente) {
    m_id = ++m_nr_reteta;
}

Reteta::~Reteta() {}

void Reteta::AfisareReteta() const {
    std::cout << "Reteta #" << m_id << "\n";
    for (const auto& medicament : m_medicamente)
        std::cout << medicament << " ";
    std::cout << "\n\n";
}

void Reteta::AdaugaMedicament(const std::string& medicament) {
    m_medicamente.push_back(medicament);
}

Pacient* Reteta::GetPacient() const {
    return m_pacient;
}

const std::vector<std::string>& Reteta::GetMedicamente() const {
    return m_medicamente;
}
