#ifndef PERSOANA_H
#define PERSOANA_H
#include <string>
#include <vector>
using namespace std;

class Medic;
class Consultatie;

class Persoana {
protected:
    string nume;
    int varsta;
    string CNP;

public:
    Persoana(string n, int v, string c) : nume(n), varsta(v), CNP(c) {}
    virtual void afisareDetalii() = 0;
    virtual void afisareConsultatii(const vector<Consultatie>& consultatii, Medic* medic) = 0;

    string getCNP() const { return CNP; }
};

#endif // PERSOANA_H