#include "persoana.h"
#include <iostream>
#include <cctype>
#include <string>

Persoana::Persoana(std::string nume, int varsta, std::string cnp)
    : m_nume(nume), m_varsta(varsta), m_cnp(cnp) {}

Persoana::Persoana() : m_nume("Necunoscut"), m_varsta(0), m_cnp("0000000000000") {}

Persoana::~Persoana() {}

std::string Persoana::GetCnp() {
    return m_cnp;
}

bool Persoana::IsValidCnp(const std::string& cnp) {
    if (cnp.length() != 13) {
        return false;
    }
    if (!(cnp[0] == '1' || cnp[0] == '2' || cnp[0] == '5' || cnp[0] == '6')) {
        return false;
    }
    for (auto& cifra : cnp) {
        if (!isdigit(cifra)) {
            return false;
        }
    }
    return true;
}
