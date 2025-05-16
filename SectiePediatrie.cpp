#include "SectiePediatrie.h"
#include <iostream>
#include <vector>

void SectiePediatrie:: afisareSectie(){
        std::cout << "Sectia Pediatrie" << std::endl;
}

void adaugaMedicSectiePediatreie(const Medic& medic){
    mediciSectiePediatrie.push_back(medic);
}