//
// Created by Harry Broudehoux on 29/11/2022.
//

#ifndef MINIVILLES_JEU_H
#define MINIVILLES_JEU_H

#include "Joueur.h"
#include "De.h"


//-----------------------Exception--------------------------//
class JeuException {
public:
    JeuException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};
//**---------------------Exception----------------------**//




//----------------------Classe Jeu------------------------//
class Jeu {
protected:
    //Liste des attributs//
    std::vector<Joueur*> joueurs;
    unsigned int nbJoueurs;
    De* de;
    //Liste des attributs//
public:
    //Constructeur et Destructeur//
    Jeu(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA);
    virtual ~Jeu();
    Jeu(const Jeu& j) = delete;
    Jeu& operator=(const Jeu& j) = delete;
    std::vector<Carte*> cartes;
    //Constructeur et Destructeur//


    //Methodes agissant sur les joueurs a l'echelle du jeu

    const std::vector<Joueur*>& getJoueursList() const { return joueurs; }
    unsigned int getNbJoueurs() const { return nbJoueurs; }
    Joueur& getJoueur(size_t i) const; //Renvoie un joueur
    void retirerJoueur(Joueur* j);
    //**Fonctions sur un joueur particulier**//
    std::string getPseudoJoueur(size_t i) const { return getJoueur(i).getPseudo(); }
    bool getIaJoueur(size_t i) const { return getJoueur(i).getIa(); }
    const Paquet& getCartesJoueur(size_t i) const { return getJoueur(i).getPaquet(); }
    unsigned int getMoneyJoueur(size_t i) const { return getJoueur(i).getMoney(); }
    unsigned int getDesJoueur(size_t i) const { return getJoueur(i).getDes(); }
    void ajouterCarteJoueur(size_t i, Carte* carte);
    Carte* retirerCarteJoueur(size_t i, Carte* c);
    Carte* retirerCarteJoueur(size_t i, std::string& nom);
    void changerMoneyJoueur(size_t i, int n);
    void changerDesJoueur(size_t i, int n);
    //**Fonctions sur un joueur particulier**//


    //Methodes agissant sur le de a l'echelle du jeu
    unsigned int lancerDe() const { return de->lancerDe(); }





    //methodes virtuels pures

    //Methodes agissant sur les cartes a l'echelle du jeu
    virtual std::vector<Carte*> getCartes() const = 0;

    //Methodes agissant sur le plateau a l'echelle du jeu
    //virtual Plateau* getPlateau() = 0;
    virtual Paquet& getPaquetByNomPlateau(std::string& nom) const = 0;
    virtual std::vector<Paquet*> getAllPaquetsPlateau() const = 0;
    virtual unsigned int getNbPaquetsPlateau() const = 0;
    virtual std::vector<Paquet*> getPaquetsNonVidesPlateau() const = 0;
    virtual Carte* retirerCartePlateau(std::string& nom) = 0;
    virtual void afficherPlateau() const = 0;
    virtual void ajouterCartePlateau(Carte* carte) const = 0;
    virtual unsigned int getNbMonuments() const = 0;
    //Methodes supplementaires
    void afficherJeu();
};
//**--------------------Classe Jeu---------------------**//




//----------------------Fonctions supplementaires-------------------------//
//**------------------Fonctions supplementaires-------------------------**//

#endif //MINIVILLES_JEU_H
