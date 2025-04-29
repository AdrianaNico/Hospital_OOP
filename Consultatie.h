#ifndef CONSULTATIE_H
#define CONSULTATIE_H

#include "Pacient.h"
class Medic; 

class Consultatie {
private:
    Pacient* pacient;
    Medic* medic;
    string data;
    string diagnostic; 

public: 
Consultatie(Pacient* p, Medic* m, string d, string diag);


    void afisareDetalii();

    Medic* getMedic() const;
    Pacient* getPacient() const;
    string getData() const;

    


};

#endif // CONSULTATIE_H
