#include "Persoana.h"
#include <iostream>

Persoana::Persoana(string n, int v, string c) : nume(n), varsta(v), CNP(c) {}
string Persoana:: getCNP() {
    return CNP;
} 