#include "Reteta.h"
#include <iostream>

int Reteta::nrReteta = 0;

Reteta::Reteta(Pacient* p, Medic* m, const std::vector<std::string>& meds)
    : pacient(p), medic(m), medicamente(meds) {
    id = ++nrReteta;
}
Reteta::~Reteta() {}
void Reteta::afisareReteta() const {
    std::cout << "Reteta #" << id << "\n";
    for (const auto& med : medicamente)
    std::cout << med << " ";
    std::cout << "\n\n";
}
void Reteta::adaugaMedicament(const std::string& med) {
    medicamente.push_back(med);
}
Pacient* Reteta::getPacient() const {
    return pacient;
}
 
const std::vector<std::string>& Reteta::getMedicamente() const {
    return medicamente;
}
 