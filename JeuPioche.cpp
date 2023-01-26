#include"JeuPioche.h"

//------------Classe JeuPioche----------//
void JeuPioche::init(std::vector<Carte*> cartes) {
    pioche = new Pioche(cartes, nbJoueurs);
    JeuPlateau::init(cartes, *pioche);
}
//------------Classe JeuPioche----------//
