#include "Reteta.h"
#include <iostream>

int Reteta::nrReteta = 0;

Reteta::Reteta(Pacient* p, Medic* m, const std::vector<std::string>& meds)
    : pacient(p), medic(m), medicamente(meds) {
    id = ++nrReteta;
}

void Reteta::afisareReteta() const {
    std::cout << "Reteta #" << id << " pentru pacientul cu CNP: " << pacient->getCNP() << "\n";
    std::cout << "Medic: " << medic->getCNP() << "\n";
    std::cout << "Medicamente: ";
    for (const auto& med : medicamente)
    std::cout << med << " ";
    std::cout << "\n";
}
void Reteta::adaugaMedicament(const std::string& med) {
    medicamente.push_back(med);
}

const std::vector<std::string>& Reteta::getMedicamente() const {
    return medicamente;
}
 