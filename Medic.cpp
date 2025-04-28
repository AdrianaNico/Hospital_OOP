#include "Medic.h"
#include <iostream>

using namespace std;

void Medic::adaugaPacient(Pacient* pacient) {
    pacienti.push_back(pacient);
}

void Medic::afisareDetalii() {
    cout << "Medic: " << nume << ", Specializare: " << specializare << endl;
    cout << "Pacienti: ";
    for (const auto& pacient : pacienti) {
        cout << pacient->getNumePacient() << " -> ";
        for (const auto& diag : pacient->getIstoricMedical()) {
            cout << diag << ", ";
        }
    }
    cout << endl;
}

void Medic::afisareConsultatii(const vector<Consultatie>& consultatii, Medic* medicGasit) {
    for (const auto& consultatie : consultatii) {
        if (consultatie.getMedic()->getNumeMedic() == medicGasit->getNumeMedic())
            cout << "Pacient: " << consultatie.getPacient()->getNumePacient()
                 << " in data de " << consultatie.getData() << endl;
    }
}
