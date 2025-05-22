#ifndef CONSULTATIE_H
#define CONSULTATIE_H

#include "Pacient.h"
class Medic;

class Consultatie {
private:
    Pacient* pacient;
    Medic* medic;
    std::string data;
    std::string diagnostic;

public:
    Consultatie(Pacient* p, Medic* m, std::string d, std::string diag);
    ~Consultatie();
    void afisareDetalii();
    
    Medic* getMedic() const;
    Pacient* getPacient() const;
    std::string getData() const;
};

#endif // CONSULTATIE_H