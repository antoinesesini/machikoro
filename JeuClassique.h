//
// Created by Antoine Sesini on 03/12/2022.
//
#pragma once
#ifndef MINIVILLES_JEUCLASSIQUE_H
#define MINIVILLES_JEUCLASSIQUE_H
#include "JeuPlateau.h"
#include "Plateau.h"
#include "Pioche.h"
#include "Carte.h"
#include "fonctions.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuClassique----------//
class JeuClassique : public JeuPlateau {
private:


    //Constructeur et Destructeur//

    JeuClassique(const JeuClassique& j) = delete;
    JeuClassique& operator=(const JeuClassique& j) = delete;
    //Constructeur et Destructeur//


/*
    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler {
        JeuClassique* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;
*/
public:
    //static JeuClassique& getJeu();
    //static void libererJeu();
    ~JeuClassique();
    JeuClassique(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA);
    //Methodes agissant sur les cartes a l'echelle du jeu
    std::vector<Carte*> getCartes() const override { return cartes; }

    //Methodes agissant sur le plateau a l'echelle du jeu
    Plateau* getPlateau() const { return plateau; }

};
//------------Classe JeuClassique----------//





//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//

#endif //MINIVILLES_JEUCLASSIQUE_H
