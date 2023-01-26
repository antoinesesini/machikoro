//
// Created by Antoine Sesini on 03/12/2022.
//
#include "JeuDeluxe.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuDeluxe----------//

//Contructeur et Destructeur//
JeuDeluxe::JeuDeluxe(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA) : JeuPioche(nbJoueurs, nomJoueurs, IA) {
    // CREATION DES CARTES DELUXE
    cartes = fonctions::cartesEditionClassique();
    std::vector<Carte*> cartesGreenValley = fonctions::cartesEditionGreenValley();
    cartes.insert(cartes.end(), cartesGreenValley.begin(), cartesGreenValley.end());
    std::vector<Carte*> cartesMarina = fonctions::cartesEditionMarina();
    cartes.insert(cartes.end(), cartesMarina.begin(), cartesMarina.end());

    // CREATION DE LA PIOCHE ET DU PLATEAU
    JeuPioche::init(cartes);

    // AJOUT DES CARTES DE DEPARTS A TOUS LES JOUEURS
    std::string nomCarteDepart1 = "Champs de ble";
    Carte* carteDepart1 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart1](Carte* c) {return c->getNom() == nomCarteDepart1; }));
    std::string nomCarteDepart2 = "Boulangerie";
    Carte* carteDepart2 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart2](Carte* c) {return c->getNom() == nomCarteDepart2; }));
    std::string nomCarteDepart3 = "Hotel de Ville";
    Carte* carteDepart3 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart3](Carte* c) {return c->getNom() == nomCarteDepart3; }));
    if (!carteDepart1 || !carteDepart2 || !carteDepart3) { throw JeuException("Attention ! les cartes de depart n'ont pu etre selectionnees"); }
    std::vector<Joueur*> playerList = getJoueursList();
    for (auto j : playerList)
    {
        j->ajouterCarte(carteDepart1);
        j->ajouterCarte(carteDepart2);
        j->ajouterCarte(carteDepart3);
    }
}

JeuDeluxe::~JeuDeluxe() {
    std::vector<Carte*>::iterator it;
    for (it = cartes.begin(); it != cartes.end(); it++) //Destruction des cartes et des effets
    {
        delete (*it)->getEffet();
        delete* it;
    }
}

/*
JeuDeluxe& JeuDeluxe::getJeu() {
    if (handler.jeu == nullptr)
        handler.jeu = new JeuDeluxe;
    return *handler.jeu;
}

void JeuDeluxe::libererJeu()
{
    delete handler.jeu;
    handler.jeu = nullptr;
}

JeuDeluxe::Handler JeuDeluxe::handler = Handler();
*/
//------------Classe JeuDeluxe----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//
