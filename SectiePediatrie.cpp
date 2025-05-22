#include "SectiePediatrie.h"
#include "Medic.h"
#include <iostream>
#include <vector>

SectiePediatrie::SectiePediatrie() {}
SectiePediatrie::~SectiePediatrie() {}

void SectiePediatrie:: afisareSectie(){
        std::cout << "Sectia Pediatrie" << std::endl;
}

void SectiePediatrie:: getMediciPediatrie() const {
        for(auto&medic : mediciSectiePediatrie){
            std::cout<<medic.getNumeMedic()<<std::endl;
        }
    }

void  SectiePediatrie:: adaugaMedicSectiePediatrie(const Medic& medic){
    mediciSectiePediatrie.push_back(medic);
} 