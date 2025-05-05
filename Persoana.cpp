#include "Persoana.h"
#include <iostream>

Persoana::Persoana(std::string n, int v, std::string c) : nume(n), varsta(v), CNP(c) {}
std::string Persoana:: getCNP() {
    return CNP;
} 