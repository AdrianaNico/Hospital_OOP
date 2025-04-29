#include "Pacient.h"
#include <iostream>

using namespace std;

Pacient::Pacient(string n, int v, string c) : Persoana(n, v, c) {}

void Pacient::adaugaConsultatie(string diagnostic) {
    istoricMedical.push_back(diagnostic);
}

void Pacient::afisareDetalii() {
    cout << "Pacient: " << nume << ", Varsta: " << varsta << ", CNP: " << CNP << endl;
    cout << "Istoric medical: ";
    for (const auto& diag : istoricMedical) {
        cout << diag << ", ";
    }
    cout << endl;
}
void Pacient::adaugaIstoricMedical(const string& i) {
    istoricMedical.push_back(i);
}
void Pacient::afisareConsultatii(const vector<Consultatie>& consultatii, Medic* medic) {
    cout << "Consultatiile pacientului... (de implementat)" << endl;
}

vector<string> Pacient::getIstoricMedical() {
    return istoricMedical;
}
string Pacient::getNumePacient() const {
    return nume;
}