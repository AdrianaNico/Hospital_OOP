#include "consultatie.h"
#include "medic.h"
#include "spital.h"
#include <iostream>

 
Consultatie::Consultatie(Pacient* p, Medic* m, std::string d, std::string diag)
    : m_pacient(p), m_medic(m), m_data(d), m_diagnostic(diag) {}

Consultatie::~Consultatie() {}

void Consultatie::AfisareDetalii() {
    std::cout << "Consultatie: " << m_data << ", Diagnosticul: " << m_diagnostic
         << ", Medic: " << m_medic->GetNumeMedic() << "\n";
}

Medic* Consultatie::GetMedic() const {
    return m_medic;
}

Pacient* Consultatie::GetPacient() const {
    return m_pacient;
}

std::string Consultatie::GetData() const {
    return m_data;
}