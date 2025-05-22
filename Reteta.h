#ifndef RETETA_H
#define RETETA_H

#include <string>
#include <vector>
#include "medic.h"
#include "pacient.h"

struct Reteta {
    static int m_nr_reteta;

    int m_id;
    Pacient* m_pacient;
    Medic* m_medic;
    std::vector<std::string> m_medicamente;

    Reteta(Pacient* p, Medic* m, const std::vector<std::string>& meds);
    ~Reteta();

    void AfisareReteta() const;
    void AdaugaMedicament(const std::string& med);
    const std::vector<std::string>& GetMedicamente() const;
    Pacient* GetPacient() const;
};

#endif // RETETA_H
