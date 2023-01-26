#pragma once
#include "Carte.h"


//********************Structures et variables necessaires*****************//
class DeException {
private:
    std::string info;
public:
    DeException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
};
//********************Structures et variables necessaires*****************//

//****************class De*******************//
class De {
private:
    unsigned int min;
    unsigned int max;
public:
    De(unsigned int m, unsigned int M) : min(m), max(M) {}
    unsigned int getMin() const { return min; }
    unsigned int getMax() const { return max; }
    unsigned int lancerDe() const;
};
//****************class De*******************//

//****************Fonctions supplementaires******************//
std::ostream& operator<<(std::ostream& f, const De& d);
//****************Fonctions supplementaires******************//
