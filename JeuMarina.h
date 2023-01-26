//
// Created by Antoine Sesini on 03/12/2022.
//
#pragma once
#ifndef MINIVILLES_JEUMARINA_H
#define MINIVILLES_JEUMARINA_H
#include "JeuPioche.h"
#include "Plateau.h"
#include "Pioche.h"
#include "Carte.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuMarina----------//
class JeuMarina : public JeuPioche {
private:
    //std::vector<Carte*> cartes;

    //Constructeur et Destructeur//

    JeuMarina(const JeuMarina& j) = delete;
    JeuMarina& operator=(const JeuMarina& j) = delete;
    //Constructeur et Destructeur//

/*
    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler {
        JeuMarina* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;
*/
public:
    /*
    static JeuMarina& getJeu();
    static void libererJeu();
*/
    ~JeuMarina();
    //Methodes agissant sur les cartes a l'echelle du jeu
    JeuMarina(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA);
    std::vector<Carte*> getCartes() const override { return cartes; }
};
//------------Classe JeuMarina----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//

#endif //MINIVILLES_JEUMARINA_H
