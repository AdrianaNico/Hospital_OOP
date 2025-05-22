#ifndef SECTIEPEDIATRIE_H
#define SECTIEPEDIATRIE_H

#include "Sectie.h"
#include "Medic.h"
#include <iostream>
#include <vector>

class SectiePediatrie: public Sectie {
public:
    SectiePediatrie() {}
    ~SectiePediatrie() {}
    void afisareSectie() override;
    void adaugaMedicSectiePediatrie(const Medic& medic);
    void getMediciPediatrie() const;

private:
    std::vector<Medic> mediciSectiePediatrie;

};

#endif