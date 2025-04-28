#include <iostream>
#include "Spital.h"

int main() {
    Spital spital;
    
    Medic medic1("Dr. Popescu", 45, "1234567890123", "Cardiolog");
    Medic medic2("Dr. Ionescu", 30, "4567890234565", "Dermatolog");

    Pacient pacient1("Ion Popescu", 30, "1112233445566");
    Pacient pacient2("Maria Ionescu", 25, "2233445566778");
    
    spital.adaugaMedic(medic1);
    spital.adaugaPacient(pacient1);
    
    spital.adaugaConsultatie(&pacient1, &medic1, "2025-03-20", "Control cardiologic");
    
    spital.afisareConsultatii();
    medic2.afisareDetalii();
    return 0;
}
