#include "Pacient.h"

void Pacient::adaugaConsultatie(string diagnostic) {
    istoricMedical.push_back(diagnostic);
}

void Pacient::afisareDetalii() {
    cout << "Pacient: " << nume << ", Varsta: " << varsta << ", CNP: " << CNP << endl;
    cout << "Istoric medical: ";
    for (const auto& diag : istoricMedical) {
        cout << diag << " ";
    }
    cout << endl;
}
