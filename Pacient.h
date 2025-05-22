#ifndef PACIENT_H
#define PACIENT_H

#include "persoana.h"
#include <iostream>
#include <vector>

class Medic; // Forward declaration

class Pacient : public Persoana {
private:
    std::vector<std::string> m_istoric_medical;

public:
    Pacient();
    Pacient(std::string nume, int varsta, std::string cnp);
    ~Pacient();
    
    void AdaugaConsultatie(std::string diagnostic);
    void AfisareDetalii() override;
    
    void AdaugaIstoricMedical(const std::string& istoric);
    std::vector<std::string> GetIstoricMedical();

    void AfisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) override;

    std::string GetNumePacient() const;

    friend std::ostream& operator<<(std::ostream& out, const Pacient& pacient);
};

#endif // PACIENT_H
