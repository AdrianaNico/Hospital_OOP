#include "SectieCardiologie.h"
#include <iostream>
#include <vector>

void SectieCardiologie:: afisareSectie(){
        std::cout << "Sectia Cardiologie" << std::endl;
}

void adaugaMedicSectieCardiologie(const Medic& medic){
    mediciSectieCardiologie.push_back(medic);
}