#ifndef CONSULTATIE_H
#define CONSULTATIE_H

#include "Pacient.h"
#include "Reteta.h" 
class Medic;

class Consultatie {
private:
    Pacient* pacient;
    Medic* medic;
    string data;
    string diagnostic;
    Reteta reteta; 

public: 
Consultatie(Pacient* p, Medic* m, string d, string diag, const Reteta& r);


    void afisareDetalii();

    Medic* getMedic() const //cu const pt ca valoarea sa nu se schimbe
    { 
        return medic; 
    }
    Pacient* getPacient() const 
    { 
        return pacient; 
    }
    string getData() const 
    { 
        return data; 
    }
    Reteta& getReteta() {
        return reteta;
    }
    


};

#endif // CONSULTATIE_H
