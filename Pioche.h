#pragma once
#include "Paquet.h"

//****************class Pioche*******************//

class Pioche : public Paquet {
public:
	Carte* piocher();
    Pioche(std::vector<Carte*> cartes, int nb_joueurs);
	Pioche() { Paquet(); }
};

//****************class Pioche*******************//

//****************Fonctions supplementaires******************//
std::ostream& operator<<(std::ostream& f, const Pioche& p);
//****************Fonctions supplementaires******************//
