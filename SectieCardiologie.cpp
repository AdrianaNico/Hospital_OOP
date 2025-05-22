#include "SectieCardiologie.h"
#include <iostream>
#include <vector>

void SectieCardiologie:: afisareSectie(){
        std::cout << "Sectia Cardiologie" << std::endl;
}

void SectieCardiologie::adaugaMedicSectieCardiologie(const Medic& medic){
    mediciSectieCardiologie.push_back(medic);
}
void SectieCardiologie:: getMediciCardiologie() const {
        for(auto&medic : mediciSectieCardiologie){
            std::cout<<medic.getNumeMedic()<<std::endl;
        }
    }