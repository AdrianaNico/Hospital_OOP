#include "spital.h"

void Spital::AdaugaMedic(Medic m) {
    m_medici.push_back(m);
}

void Spital::AdaugaPacient(Pacient p) {
    m_pacienti.push_back(p);
}

void Spital::AdaugaConsultatie(Consultatie c) {
    m_consultatii.push_back(c);
}

void Spital::AdaugaReteta(Reteta r) {
    m_retete.push_back(r);
}

void Spital::AfisareConsultatii() {
    for (auto& c : m_consultatii)
        c.AfisareDetalii();
}

std::vector<Medic>& Spital::GetMedici() {
    return m_medici;
}

std::vector<Consultatie>& Spital::GetConsultatii() {
    return m_consultatii;
}

std::vector<Reteta>& Spital::GetRetete() {
    return m_retete;
}

Pacient* Spital::CautaPacient(std::string nume) {
    for (auto& pacient : m_pacienti)
        if (pacient.GetNumePacient() == nume)
            return &pacient;
    return nullptr;
}

Medic* Spital::CautaMedic(std::string nume) {
    for (auto& medic : m_medici)
        if (medic.GetNumeMedic() == nume)
            return &medic;
    return nullptr;
}

bool Spital::ExistaConsultatie(std::string numeMedic, std::string numePacient) {
    const std::vector<Consultatie>& consultatii = GetConsultatii();
    for (const auto& consultatie : consultatii) {
        if (consultatie.GetMedic()->GetNumeMedic() == numeMedic &&
            consultatie.GetPacient()->GetNumePacient() == numePacient) {
            return true;
        }
    }
    return false;
}

Spital::~Spital() {}
