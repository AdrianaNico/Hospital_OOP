#ifndef PACIENT_H
#define PACIENT_H

#include "Persoana.h"
#include <iostream>
#include <vector>

class Medic; // Forward declaration pentru a evita includerea ciclică

class Pacient : public Persoana {
private:
std::vector<std::string> istoricMedical;

public: 
    Pacient();
    Pacient(std::string n, int v, std::string c);
    ~Pacient();
    void adaugaConsultatie(std::string diagnostic);

    void afisareDetalii() override;

    void adaugaIstoricMedical(const std:: string& i);
    std::vector<std::string> getIstoricMedical();

    void afisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) override;
 
    std::string getNumePacient() const;

};

#endif // PACIENT_H
