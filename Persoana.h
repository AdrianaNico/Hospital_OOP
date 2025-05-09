#ifndef PERSOANA_H
#define PERSOANA_H
#include <string>
#include <vector>


class Medic;
class Consultatie;

class Persoana {
protected:
    std::string nume;
    int varsta;
    std::string CNP;

public:
    Persoana(std::string n, int v,std:: string c);
    virtual void afisareDetalii() = 0;
    virtual void afisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) = 0;

    std::string getCNP(); 
};

#endif // PERSOANA_H