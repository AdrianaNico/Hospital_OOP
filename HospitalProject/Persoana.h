#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
using namespace std;

class Persoana {
protected:
    string nume;
    int varsta;
    string CNP;

public:
    Persoana(string n, int v, string c) : nume(n), varsta(v), CNP(c) {}
    virtual void afisareDetalii() = 0; // Metoda virtuală pură
    string getNume() const { return nume; }
    string getCNP() const { return CNP; }
};

#endif // PERSOANA_H