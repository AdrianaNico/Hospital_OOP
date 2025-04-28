#include "Medic.h"

void Medic::afisareDetalii() {
    cout << "Medic: " << nume << ", Specializare: " << specializare << endl;
    cout << "Pacienti: ";
    for (const auto& pacient : pacienti) {
        cout << pacient->getNume() << " ";
    }
    cout << endl;
}
