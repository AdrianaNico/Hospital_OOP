#include "Persoana.h"
#include <iostream>
#include <cctype> // Pentru std::isdigit
#include <string>
Persoana::Persoana(std::string n, int v, std::string c) : nume(n), varsta(v), CNP(c) {}

Persoana::Persoana() : nume("Necunoscut"), varsta(0), CNP("0000000000000") {}
Persoana::~Persoana() {}
std::string Persoana::getCNP() {
    return CNP;
}
bool Persoana::isValidCNP(const std::string& cnp){
    if(cnp.length() != 13){
        return false;
    }
    if(!(cnp[0] == '1' || cnp[0] == '2' || cnp[0] == '5' || cnp[0] == '6')){
        return false;
    }
    for(auto& cifra : cnp){
        if(!isdigit(cifra)){
            return false;
        }
    }
    return true;
}


