#include "Consultatie.h"
#include "Medic.h"
#include <iostream>

using namespace std;

Consultatie::Consultatie(Pacient* p, Medic* m, string d, string diag, const Reteta& r)
    : pacient(p), medic(m), data(d), diagnostic(diag), reteta(r) {}

void Consultatie::afisareDetalii() {
    cout << "Consultatie: " << data << ", Diagnosticul: " << diagnostic
         << ", Medic: " << medic->getNumeMedic() << "\n";

    cout << "Reteta aferenta:\n";
    reteta.afisareReteta();
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
Reteta& Consultatie::getReteta() {
    return reteta;
}


//am facut ceva
//am facut si altceva uau merge
//am mai facut cevaaaaa