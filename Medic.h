#ifndef MEDIC_H
#define MEDIC_H

#include "Persoana.h"
#include "Pacient.h"
#include "Consultatie.h"
#include <string>
#include <iostream>
#include <vector>


class Medic : public Persoana {
private:
std::string specializare;
std::vector<Pacient*> pacienti;  // Folosim vector de pointeri la Pacient

public:
    Medic(std::string n, int v, std::string c, std::string s);
    ~Medic();
    void adaugaPacient(Pacient* pacient);

    void afisareDetalii() override;
    void afisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) override;
    std::string getNumeMedic() const;
    std::string getSpecializare() const;
};

#endif // MEDIC_H
