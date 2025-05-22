#ifndef SPITAL_H
#define SPITAL_H

#include "medic.h"
#include "pacient.h"
#include "consultatie.h"
#include "persoana.h"
#include "reteta.h"
#include "sectie.h"
class SectieChirurgie;
class SectieCardiologie;
class SectiePediatrie;
#include <vector>
#include <string>
#include <iostream>

class Spital {
private:
    std::vector<Medic> m_medici;
    std::vector<Pacient> m_pacienti;
    std::vector<Consultatie> m_consultatii;
    std::vector<Reteta> m_retete;
    std::vector<SectieChirurgie*> m_sectie_chirurgie;
    std::vector<SectieCardiologie*> m_sectie_cardiologie;
    std::vector<SectiePediatrie*> m_sectie_pediatrie;
public:
    Spital() = default;
    ~Spital();

    void AdaugaMedic(Medic m);
    void AdaugaPacient(Pacient p);
    void AdaugaConsultatie(Consultatie c);
    void AdaugaReteta(Reteta r);
    void AfisareConsultatii();
    bool ExistaConsultatie(std::string numeMedic, std::string numePacient);

    std::vector<Medic>& GetMedici();
    std::vector<Consultatie>& GetConsultatii();
    std::vector<Reteta>& GetRetete();
    Pacient* CautaPacient(std::string nume);
    Medic* CautaMedic(std::string nume);
};

#endif // SPITAL_H
