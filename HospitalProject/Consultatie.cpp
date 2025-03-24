#include "Consultatie.h"

void Consultatie::afisareDetalii() {
    cout << "Consultatie: " << data << ", Diagnosticul: " << diagnostic
         << " (Pacient: " << pacient->getNume() << ", Medic: " << medic->getNume() << ")\n";
}
