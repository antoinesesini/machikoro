//
// Created by Antoine Sesini on 26/11/2022.
//
#pragma once
#ifndef MINIVILLES_PLATEAU_H
#define MINIVILLES_PLATEAU_H

#include "Paquet.h"
#include "Pioche.h"


//********************Structures et variables necessaires*****************//
class PlateauException {
private:
    std::string info;
public:
    PlateauException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
};
//********************Structures et variables necessaires*****************//


//****************class Plateau*******************//
class Plateau {
private:
    std::vector<Paquet*> cartes;
    Pioche pioche;
    unsigned int nb_monuments;
public:
    //Constructeur avec dispatch normal : on identifie les cartes et on les pointe 6 fois dans chaque Paquet (sauf exception)
    explicit Plateau(std::vector<Carte*> cartesJeu, unsigned int nbJoueurs); //cartesJeu=toutes les cartes de l'edition ne necessitant pas de pioche et de distribution speciale
    //Constructeur avec un dispatch anormal : on utilise la pioche pour faire des tirages
    Plateau(std::vector<Carte*>& cartesJeu, Pioche& p, unsigned int nbJoueurs);
    Plateau(const Plateau&) = delete;
    Plateau operator=(const Plateau&) = delete;
    ~Plateau();




    //Espace de definition des get et autres methodes d'utilisation//
    Paquet& getPaquetByNom(std::string& nom) const;
    std::vector<Paquet*> getAllPaquets() const;
    unsigned int getNbPaquets() const;
    std::vector<Paquet*> getPaquetsNonVides() const;
    Carte* retirerCarte(std::string& nom);
    void ajouterCarte(Carte* carte);
    void remplirPlateau(bool firstCall);
    void afficherPlateau() const;
    unsigned int getNbMonuments() const { return nb_monuments; }

    //Espace de definition des get et autres methodes d'utilisation//


};
//****************class Plateau*******************//


//****************Fonctions supplementaires******************//
std::ostream& operator<<(std::ostream& f, const Plateau& p);
//****************Fonctions supplementaires******************//


#endif //MINIVILLES_PLATEAU_H
