#ifndef CONSULTATIE_H
#define CONSULTATIE_H

#include "pacient.h"
class Medic;

class Consultatie {
private:
    Pacient* m_pacient;
    Medic* m_medic;
    std::string m_data;
    std::string m_diagnostic;

public:
    Consultatie(Pacient* p, Medic* m, std::string d, std::string diag);
    ~Consultatie();
    void AfisareDetalii();
    
    Medic* GetMedic() const;
    Pacient* GetPacient() const;
    std::string GetData() const;
};

#endif // CONSULTATIE_H