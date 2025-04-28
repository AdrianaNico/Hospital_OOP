#include "Spital.h"

void Spital::adaugaMedic(Medic m) {
    medici.push_back(m);
}

void Spital::adaugaPacient(Pacient p) {
    pacienti.push_back(p);
}

void Spital::adaugaConsultatie(Pacient* p, Medic* m, string data, string diagnostic) {
    consultatii.push_back(Consultatie(p, m, data, diagnostic));
}

void Spital::afisareConsultatii() {
    for (auto& c : consultatii)
        c.afisareDetalii();
}
