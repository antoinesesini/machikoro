#include "JeuPlateau.h"
#include "JeuClassique.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//

//------------Classe JeuPlateau----------//
//Constructeur et Destructeur//
void JeuPlateau::init(std::vector<Carte*>& cartes) {
    // CREATION DU PLATEAU
    plateau = new Plateau(cartes, nbJoueurs);
    if (!plateau) { throw JeuException("Attention ! allocation de plateau echouee"); }
}

void JeuPlateau::init(std::vector<Carte*>& cartes,Pioche& pioche) {
    // CREATION DU PLATEAU
    plateau = new Plateau(cartes, pioche, nbJoueurs);
    if (!plateau) { throw JeuException("Attention ! allocation de plateau echouee"); }
}


JeuPlateau::~JeuPlateau() {
    delete plateau;
}

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//

//------------Classe JeuPlateau----------//
