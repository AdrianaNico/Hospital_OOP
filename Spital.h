#ifndef SPITAL_H
#define SPITAL_H

#include "Medic.h"
#include "Pacient.h"
#include "Consultatie.h"
#include "Persoana.h"
#include "Reteta.h"
#include "Sectie.h"
class SectieChirurgie;
class SectieCardiologie;
class SectiePediatrie;
#include <vector>
#include <string>
#include <iostream>

class Spital {
private:
    std::vector<Medic> medici;
    std::vector<Pacient> pacienti;
    std::vector<Consultatie> consultatii;
    std::vector<Reteta> retete;
    std::vector<SectieChirurgie*> sectieChirurgie;
    std::vector<SectieCardiologie*> sectieCardiologie;
    std::vector<SectiePediatrie*> sectiePediatrie;
public:
    void adaugaMedic(Medic m);
    void adaugaPacient(Pacient p);
    void adaugaConsultatie(Consultatie c);
    void adaugaReteta(Reteta r);
    void afisareConsultatii();
    bool ExistaConsultatie(std::string numeMedic, std::string numePacient);

    std::vector<Medic>& getMedici();
    std::vector<Consultatie>& getConsultatii();
    std::vector<Reteta>& getRetete();
    Pacient* cautaPacient(std::string nume);
    Medic* cautaMedic(std::string nume);


};

#endif // SPITAL_H
