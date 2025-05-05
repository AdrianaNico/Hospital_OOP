#include "Medic.h"
#include <iostream>

void Medic::afisareDetalii() {
    std::cout << "Medic: " << nume << ", Specializare: " << specializare <<std:: endl;
    std::cout << "Pacienti: ";
    for (const auto& pacient : pacienti) {
        std::cout << pacient->getNumePacient() << " -> ";
        for (const auto& diag : pacient->getIstoricMedical()) {
            std:: cout << diag << ", ";
        }
    }
    std::cout << std::endl;
}

void Medic::adaugaPacient(Pacient* pacient) {
    pacienti.push_back(pacient);
}
void Medic::afisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) {
    if (consultatii.empty()) {
        std:: cout << "Nu exista consultatii." << std::endl;
        return;
    } 
    for (auto& consultatie : consultatii) {
        if (consultatie.getMedic()->getNumeMedic() == medic->getNumeMedic()) {
            std::cout << "Pacient: " << consultatie.getPacient()->getNumePacient()
                 << " in data de " << consultatie.getData() << std::endl;
        }
    }
}

std::string Medic::getNumeMedic() const {
    return nume;
}
std::string Medic::getSpecializare() const {
    return specializare;
}

