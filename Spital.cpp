#include "spital.h"
#include <memory> // pentru std::shared_ptr si std::unique_ptr

void Spital::AdaugaMedic(Medic m) {
    m_medici.push_back(std::make_unique<Medic>(m));
}

void Spital::AdaugaPacient(Pacient p) {
    m_pacienti.push_back(std::make_unique<Pacient>(p));
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

std::vector<std::unique_ptr<Medic>>& Spital::GetMedici() {
    return m_medici;
}

std::vector<Consultatie>& Spital::GetConsultatii() {
    return m_consultatii;
}

std::vector<Reteta>& Spital::GetRetete() {
    return m_retete;
}

Pacient* Spital::CautaPacient(std::string nume) {
    for (const auto& pacient_ptr : m_pacienti) {
        if (pacient_ptr->GetNumePacient() == nume) {
            return pacient_ptr.get(); //returneaza pointerul brut
        }
    }
    return nullptr;
}

Medic* Spital::CautaMedic(std::string nume) {
    for (const auto& medic_ptr : m_medici) {
        if (medic_ptr->GetNumeMedic() == nume) {
            return medic_ptr.get(); // Returnează pointerul brut
        }
    }
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
