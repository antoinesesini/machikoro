//
// Created by Antoine Sesini on 03/12/2022.
//
#pragma once
#ifndef MINIVILLES_JEUDELUXE_H
#define MINIVILLES_JEUDELUXE_H
#include "JeuPioche.h"
#include "Carte.h"
#include "fonctions.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuDeluxe----------//
class JeuDeluxe : public JeuPioche {
private:
    //std::vector<Carte*> cartes;

    //Contructeur et Destructeur//




    JeuDeluxe(const JeuDeluxe& j) = delete;
    JeuDeluxe& operator=(const JeuDeluxe& j) = delete;
    //Constructeur et Destructeur//

/*
    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler {
        JeuDeluxe* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;
*/


public:
    ~JeuDeluxe();
    /*
    static JeuDeluxe& getJeu();
    static void libererJeu();
    */
    JeuDeluxe(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA);
    //Methodes agissant sur les cartes a l'echelle du jeu
    std::vector<Carte*> getCartes() const override { return cartes; }
};
//------------Classe JeuDeluxe----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUDELUXE_H

