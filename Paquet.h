#pragma once
#ifndef MINIVILLES_PAQUET_H
#define MINIVILLES_PAQUET_H
#include "Carte.h"

//********************Structures et variables necessaires*****************//
class PaquetException {
private:
    std::string info;
public:
    PaquetException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
};
//********************Structures et variables necessaires*****************//



//****************class Paquet*******************//
class Paquet {
private:
    std::vector<Carte*> cartes;
public:
    Paquet() = default;
    virtual ~Paquet() = default;
    Paquet(const Paquet& p) = default;
    Paquet& operator=(const Paquet&) = delete; //On ne doit pas pouvoir creer un paquet par affectation

    unsigned int getNbCartes() const { return cartes.size(); }
    bool is_In(Carte*) const;
    bool is_In(std::string& nom) const;
    void ajouterCarte(Carte* c) { cartes.push_back(c); }
    //int getNb
    Carte* retirerCarte(std::string& nom);
    Carte* retirerCarte(Carte* c); //retirer la carte passe en parametre
    Carte* retirerCarte(); //retirer la derniere carte (sur le paquet)
    Carte& getCarte(size_t i) const { if (!cartes.empty())return *(cartes[i]); else throw PaquetException("Aucune carte contenue dans ce paquet"); } //a voir si on garde/change
    std::vector<Carte*> getContener() const { return cartes; } //retourne le conteneur entier de cartes
    std::vector<Carte*> getCarteCouleur(Couleur couleur) const;
    std::vector<Carte*> getCarteType(Type type) const;
    std::vector<Carte*> getCarteActive(int activateur) const;
    std::vector<Carte*> getCarteNom(std::string& nom) const;
};
//****************class Paquet*******************//



//****************Fonctions supplementaires******************//
std::ostream& operator<<(std::ostream& f, const Paquet& p); //Fonction d'affichage d'un paquet
//****************Fonctions supplementaires******************//

#endif //MINIVILLES_PAQUET_H
