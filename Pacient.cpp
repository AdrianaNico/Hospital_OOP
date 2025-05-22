#include "pacient.h"
#include <iostream>

Pacient::Pacient(std::string n, int v, std::string c) : Persoana(n, v, c) {}
Pacient::~Pacient() {}

void Pacient::AdaugaConsultatie(std::string diagnostic) {
    m_istoric_medical.push_back(diagnostic);
}

// void Pacient::AfisareDetalii() {
//     std::cout << "Pacient: " << m_nume << ", Varsta: " << m_varsta << ", CNP: " << m_cnp << std::endl;
//     std::cout << "Istoric medical: ";
//     for (const auto& diag : m_istoric_medical) {
//         std::cout << diag << "; ";
//     }
//     std::cout <<std:: endl; 
// } 
void Pacient::AfisareDetalii() {
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Pacient& p) {
    out << "Pacient: " << p.m_nume << ", Varsta: " << p.m_varsta << ", CNP: " << p.m_cnp << "\n";
    out << "Istoric medical: ";
    for (const auto& diag : p.m_istoric_medical) {
        out << diag << "; ";
    }
    return out;
}

void Pacient::AdaugaIstoricMedical(const std::string& i) {
    m_istoric_medical.push_back(i);
}

void Pacient::AfisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) {
    std::cout << "Consultatiile pacientului... (de implementat)" << std::endl;
}

std::vector<std::string> Pacient::GetIstoricMedical() {
    return m_istoric_medical;
}

std::string Pacient::GetNumePacient() const {
    return m_nume;
}