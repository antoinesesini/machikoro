//
// Created by Antoine Sesini on 29/11/2022.
//
#ifndef MINIVILLES_JOUEUR_H
#define MINIVILLES_JOUEUR_H
#include <string>
#include "Paquet.h"


//********************Structures et variables necessaires*****************//
class JoueurException {
public:
    JoueurException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};
//********************Structures et variables necessaires*****************//


//****************class Joueur*******************//
class Joueur {
private:
    std::string pseudo;
    bool ia;
    Paquet cartes;
    std::vector<bool> ferme;
    unsigned int money;
    unsigned int des;
    unsigned int investissement;

public:
    //Constructeurs et destructeurs//
    Joueur() = delete;
    Joueur(std::string pseudo, bool ia, Paquet& c, unsigned int argent, unsigned int des, unsigned int investissement = 0) :
        pseudo(pseudo), ia(ia), cartes(c), money(argent), des(des), investissement(investissement) {
        for (auto carte : c.getContener()) {
            ferme.push_back(false);
        }
    }
    Joueur(const Joueur&) = delete;
    Joueur& operator=(const Joueur&) = delete;
    ~Joueur() = default;
    //Constructeurs et destructeurs//




    //Methods de service//
    std::string getPseudo() const { return pseudo; }
    bool getIa() const { return ia; }
    const Paquet& getPaquet() const { return cartes; }
    unsigned int getMoney() const { return money; }
    unsigned int getDes() const { return des; }
    int getInvestissement() const { return investissement; }
    std::vector<bool> getToutFerme() const{ return ferme; }
    bool isFermer(Carte* c);
    bool isFermer(std::string& nom);

    void ajouterCarte(Carte* carte); //Ajoute une carte dans le paquet du joueur
    Carte* retirerCarte(Carte* c); //Retire une carte dans le paquet du joueur et la retourne sous forme de pointeur
    Carte* retirerCarte(std::string& nom);
    void fermerOuvrirEtablissement(Carte* c, bool fermer);
    void fermerOuvrirEtablissement(std::string& nom, bool fermer);
    int fermerOuvrirEtablissement(Type type, bool fermer);

    void afficherCartes();

    void ajouterInvestissement(unsigned int nb) { investissement += nb; }
    void changerMoney(int n) { money = n; }
    void changerDes(int n) { des = n; }
    //Methodes de service//




    void affichageTemp() {
        for (auto fer : ferme) {
            std::cout << fer << "\n";
        }

    }
};
//****************class Joueur*******************//


//********************Fonctions supplementaires**************************//
std::ostream& operator<<(std::ostream& f, const Joueur& joueur);
//********************Fonctions supplementaires**************************//



#endif //MINIVILLES_JOUEUR_H
