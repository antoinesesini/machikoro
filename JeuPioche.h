//
// Created by Antoine Sesini on 08/12/2022.
//

#ifndef MINIVILLES_JEUPIOCHE_H
#define MINIVILLES_JEUPIOCHE_H
#include "JeuPlateau.h"
#include "Pioche.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuPioche----------//
class JeuPioche : public JeuPlateau {
protected:
    Pioche* pioche;
public:
    //Constructeur et Destructeur//
    JeuPioche(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA) : JeuPlateau(nbJoueurs, nomJoueurs, IA) {}
    ~JeuPioche() { delete pioche;}
    void init(std::vector<Carte*> cartes);

};
//------------Classe JeuPioche----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUPIOCHE_H
