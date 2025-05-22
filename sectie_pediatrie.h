#ifndef SECTIE_PEDIATRIE_H
#define SECTIE_PEDIATRIE_H

#include "sectie.h"
#include "medic.h"
#include <iostream>
#include <vector>

class SectiePediatrie : public Sectie {
public:
    SectiePediatrie();
    ~SectiePediatrie() override;

    void AfisareSectie() override;
    void AdaugaMedicSectiePediatrie(const Medic& medic);
    void GetMediciPediatrie() const;

private:
    std::vector<Medic> m_medici_sectie_pediatrie;
};

#endif // SECTIE_PEDIATRIE_H
