#include "medic.h"
#include <iostream>

Medic::Medic(std::string n, int v, std::string c, std::string s) : Persoana(n, v, c), m_specializare(s) {}
Medic::~Medic(){}

void Medic::AfisareDetalii() {
    std::cout << "Medic: " << m_nume << ", Specializare: " << m_specializare <<std:: endl;
    std::cout << "Pacienti: ";
    for (const auto& pacient : m_pacienti) {
        std::cout << pacient->GetNumePacient() << " -> ";
        for (const auto& diag : pacient->GetIstoricMedical()) {
            std:: cout << diag << ", ";
        }
    }
    std::cout << std::endl;
}

void Medic::AdaugaPacient(Pacient* pacient) {
    m_pacienti.push_back(pacient);
}

void Medic::AfisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) {
    if (consultatii.empty()) {
        std:: cout << "Nu exista consultatii." << std::endl;
        return;
    } 
    for (auto& consultatie : consultatii) {
        if (consultatie.GetMedic()->GetNumeMedic() == medic->GetNumeMedic()) {
            std::cout << "Pacient: " << consultatie.GetPacient()->GetNumePacient()
                 << " in data de " << consultatie.GetData() << std::endl;
        }
    }
}

std::string Medic::GetNumeMedic() const {
    return m_nume;
}

std::string Medic::GetSpecializare() const {
    return m_specializare;
}