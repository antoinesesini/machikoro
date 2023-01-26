//
// Created by Antoine Sesini on 08/12/2022.
//
#pragma once
#ifndef MINIVILLES_CONTROLEUR_H
#define MINIVILLES_CONTROLEUR_H
#include "Jeu.h"
#include "JeuClassique.h"
#include "JeuMarina.h"
#include "JeuGreenValley.h"
#include "JeuDeluxe.h"

//Structures et classes necessaires a la classe principale//
class ControleurException {
public:
    ControleurException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};


enum class Edition { Classique, Marina, GreenValley, Deluxe };
extern std::initializer_list<Edition> Editions;
//Structures et classes necessaires a la classe principale//
Edition toEdition(std::string s);
std::string toString(Edition e);



class Controleur {
private:
    //attributs//
    bool sens; //Si sens horaire -> =true sinon =false
    Edition edition;
    Jeu* jeu; //a voir si on garde ca sous cette forme
    //attributs//

    //constructeurs et destructeurs//
    Controleur(Edition edition, bool sens, int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA);
    ~Controleur();
    Controleur(const Controleur& controleur) = delete;
    const Controleur& operator=(const Controleur& controleur) = delete;
    //constructeurs et destructeurs//

    //gestion singleton
    struct Handler {
        Controleur* controleur;
        Handler() : controleur(nullptr) {}
        ~Handler() { libererControleur(); }
    };
    static Handler handler;
    //gestion singleton

public:
    //methodes publiques//
    static Controleur& getControleur();
    static Controleur& createInstance(Edition edition, bool sens, int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA);
    static void libererControleur();


    Jeu* getJeu() const { return jeu; }
    int runPartie();
    void afficherJeu();
    int runTour(Joueur* currentJoueur, bool& termine, bool& doubleDes);
    bool getSens() const { return sens; }
    //methodes publiques//
};




//Autres fonctions non membres//
//Autres fonctions non membres//

#endif //MINIVILLES_CONTROLEUR_H
