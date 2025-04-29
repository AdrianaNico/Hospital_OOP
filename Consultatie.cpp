#include "Consultatie.h"
#include "Medic.h"
#include <iostream>

using namespace std;
 
Consultatie::Consultatie(Pacient* p, Medic* m, string d, string diag)
    : pacient(p), medic(m), data(d), diagnostic(diag) {}

void Consultatie::afisareDetalii() {
    cout << "Consultatie: " << data << ", Diagnosticul: " << diagnostic
         << ", Medic: " << medic->getNumeMedic() << "\n";
}

Medic* Consultatie::getMedic() const {
    return medic;
}

Pacient* Consultatie::getPacient() const {
    return pacient;
}

string Consultatie::getData() const {
    return data;
}
