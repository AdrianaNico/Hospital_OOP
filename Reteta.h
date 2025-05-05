#ifndef RETETA_H
#define RETETA_H

#include <string>
#include <vector>
#include "Medic.h"
#include "Pacient.h"

struct Reteta {
    static int nrReteta;

    int id;
    Pacient* pacient;
    Medic* medic;
    std::vector<std::string> medicamente;

    Reteta(Pacient* p, Medic* m, const std::vector<std::string>& meds);
    void afisareReteta() const;
    void adaugaMedicament(const std::string& med);
    const std::vector<std::string>& getMedicamente() const;
};

#endif // RETETA_H
 