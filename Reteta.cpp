#include "Reteta.h"
#include <iostream>

int Reteta::nrReteta = 0;

Reteta::Reteta(Pacient* p, Medic* m, const vector<string>& meds)
    : pacient(p), medic(m), medicamente(meds) {
    id = ++nrReteta;
}

void Reteta::afisareReteta() const {
    cout << "Reteta #" << id << " pentru pacientul cu CNP: " << pacient->getCNP() << "\n";
    cout << "Medic: " << medic->getCNP() << "\n";
    cout << "Medicamente: ";
    for (const auto& med : medicamente)
        cout << med << " ";
    cout << "\n";
}
void Reteta::adaugaMedicament(const string& med) {
    medicamente.push_back(med);
}

const vector<string>& Reteta::getMedicamente() const {
    return medicamente;
}
