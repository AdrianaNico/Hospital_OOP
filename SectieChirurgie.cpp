#include "SectieChirurgie.h"
#include <iostream>
#include <vector>

void SectieChirurgie:: afisareSectie(){
        std::cout << "Sectia Chirurgie" << std::endl;
}

void adaugaMedicSectieChirurgie(const Medic& medic){
    mediciSectieChirurgie.push_back(medic);
}