#ifndef MEDIC_H
#define MEDIC_H

#include "persoana.h"
#include "pacient.h"
#include "consultatie.h"
#include <string>
#include <iostream>
#include <vector>


class Medic : public Persoana {
private:
    std::string m_specializare;
    std::vector<Pacient*> m_pacienti;  // Folosim vector de pointeri la Pacient

public:
    Medic(std::string n, int v, std::string c, std::string s);
    ~Medic();
    void AdaugaPacient(Pacient* pacient);

    void AfisareDetalii() override;
    void AfisareConsultatii(const std::vector<Consultatie>& consultatii, Medic* medic) override;
    std::string GetNumeMedic() const;
    std::string GetSpecializare() const;
};

#endif // MEDIC_H