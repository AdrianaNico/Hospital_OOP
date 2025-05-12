#include "Spital.h"

void Spital::adaugaMedic(Medic m) {
    medici.push_back(m);
}

void Spital::adaugaPacient(Pacient p) {
    pacienti.push_back(p);
}
 
void Spital::adaugaConsultatie(Consultatie c) {
    consultatii.push_back(c);
}

void Spital::adaugaReteta(Reteta r) {
    retete.push_back(r);
}

void Spital::afisareConsultatii() {
    for (auto& c : consultatii)
        c.afisareDetalii();
}
 
std::vector<Medic>& Spital::getMedici() {
    return medici;
}

std::vector<Consultatie>& Spital::getConsultatii() {
    return consultatii;
}

std::vector<Reteta>& Spital:: getRetete() {
    return retete;
}

Pacient* Spital::cautaPacient(std::string nume) {
    for (auto& pacient : pacienti)
        if (pacient.getNumePacient() == nume)
            return &pacient;
    return nullptr;
}

Medic* Spital::cautaMedic(std::string nume) {
    for (auto& medic : medici)
        if (medic.getNumeMedic() == nume)
            return &medic;
    return nullptr;
}
