#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>
#include <vector>

class Medic;
class Consultatie;

class Persoana {
protected:
    std::string m_nume;
    int m_varsta;
    std::string m_cnp;

public:
    Persoana(std::string nume, int varsta, std::string cnp);
    Persoana();
    virtual ~Persoana();

    virtual void AfisareDetalii() = 0;
    virtual void AfisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) = 0;

    static bool IsValidCnp(const std::string& cnp);
    std::string GetCnp();
};

#endif // PERSOANA_H
