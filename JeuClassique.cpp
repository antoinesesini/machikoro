//
// Created by Antoine Sesini on 03/12/2022.
//
#include "JeuClassique.h"
#include <vector>
#include <QMessageBox>
//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuClassique----------//

//Constructeur et Destructeur//
JeuClassique::JeuClassique(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA) : JeuPlateau(nbJoueurs, nomJoueurs, IA) {
    //Ensuite, pas besoin d'appeler le constructeur sans argument, la partie Jeu de JeuClassique est appelee directement
    Jeu::cartes=fonctions::cartesEditionClassique();
    init(cartes);
    std::string nomCarteDepart1 = "Champs de ble";
    Carte* carteDepart1 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart1](Carte* c) {return c->getNom() == nomCarteDepart1; }));
    std::string nomCarteDepart2 = "Boulangerie";
    Carte* carteDepart2 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart2](Carte* c) {return c->getNom() == nomCarteDepart2; }));
    if (!carteDepart1 || !carteDepart2) { throw JeuException("Attention ! les cartes de depart n'ont pu etre selectionnees"); }
    std::vector<Joueur*> playerList = getJoueursList();
    for (auto j : playerList)
    {
        j->ajouterCarte(carteDepart1);
        j->ajouterCarte(carteDepart2);
    }

}
JeuClassique::~JeuClassique() {
    //On detruit les cartes crees par fonctions::cartesEditionClassique()
    //Pas besoin de detruire le plateau, sa destruction est automatique
    std::vector<Carte*>::iterator it;
    for (it = cartes.begin(); it != cartes.end(); it++)//Destruction des cartes
    {
        delete (*it)->getEffet();
        delete* it;
    }

}

/*

JeuClassique& JeuClassique::getJeu() {
    if (handler.jeu == nullptr)
        handler.jeu = new JeuClassique;
    return *handler.jeu;
}

void JeuClassique::libererJeu()
{
    delete handler.jeu;
    handler.jeu = nullptr;
}

JeuClassique::Handler JeuClassique::handler = Handler();
*/
//------------Classe JeuClassique----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//
