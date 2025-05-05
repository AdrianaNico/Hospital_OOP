#include "Pacient.h"
#include <iostream>

Pacient::Pacient(std::string n, int v, std::string c) : Persoana(n, v, c) {}

void Pacient::adaugaConsultatie(std::string diagnostic) {
    istoricMedical.push_back(diagnostic);
}

void Pacient::afisareDetalii() {
    std::cout << "Pacient: " << nume << ", Varsta: " << varsta << ", CNP: " << CNP << std::endl;
    std::cout << "Istoric medical: ";
    for (const auto& diag : istoricMedical) {
        std::cout << diag << "; ";
    }
    std::cout <<std:: endl; 
}
void Pacient::adaugaIstoricMedical(const std::string& i) {
    istoricMedical.push_back(i);
}
void Pacient::afisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) {
    std::cout << "Consultatiile pacientului... (de implementat)" << std::endl;
}

std::vector<std::string> Pacient::getIstoricMedical() {
    return istoricMedical;
}
std::string Pacient::getNumePacient() const {
    return nume;
}