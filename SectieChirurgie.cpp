#include "SectieChirurgie.h"
#include <iostream>
#include <vector>

void SectieChirurgie:: afisareSectie(){
        std::cout << "Sectia Chirurgie" << std::endl;
}

void SectieChirurgie:: adaugaMedicSectieChirurgie(const Medic& medic){
    mediciSectieChirurgie.push_back(medic);
} 

void SectieChirurgie:: getMediciChirurgie() const {
        std::cout<< "Medici sectia chirurgie: \n";
        for(auto&medic : mediciSectieChirurgie){
            std::cout<<medic.getNumeMedic()<<std::endl;
        }
    }