#ifndef CONSULTATIE_H
#define CONSULTATIE_H

#include "Pacient.h"
#include "Medic.h"

class Consultatie {
private:
    Pacient* pacient;
    Medic* medic;
    string data;
    string diagnostic;

public:
    Consultatie(Pacient* p, Medic* m, string d, string diag) 
        : pacient(p), medic(m), data(d), diagnostic(diag) {}

    void afisareDetalii() {
        cout << "Consultatie: " << data << ", Diagnosticul: " << diagnostic
             << " (Pacient: " << pacient->getNume() << ", Medic: " << medic->getNume() << ")\n";
    }
};

#endif // CONSULTATIE_H
