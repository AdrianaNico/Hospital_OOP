#include "Consultatie.h"
#include "Medic.h"
#include <iostream>

 
Consultatie::Consultatie(Pacient* p, Medic* m, std::string d, std::string diag)
    : pacient(p), medic(m), data(d), diagnostic(diag) {}

void Consultatie::afisareDetalii() {
    std::cout << "Consultatie: " << data << ", Diagnosticul: " << diagnostic
         << ", Medic: " << medic->getNumeMedic() << "\n";
}

Medic* Consultatie::getMedic() const {
    return medic;
}

Pacient* Consultatie::getPacient() const {
    return pacient;
}

std::string Consultatie::getData() const {
    return data;
}
