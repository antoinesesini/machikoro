//
// Created by Antoine Sesini on 08/12/2022.
//

#ifndef MINIVILLES_JEUPLATEAU_H
#define MINIVILLES_JEUPLATEAU_H
#include "Jeu.h"
#include "Plateau.h"
#include "fonctions.h"



//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuPlateau----------//
class JeuPlateau : public Jeu {
//classe abstraite
protected:
    Plateau* plateau;
    

public:
    //CONSTRUCTEUR ET DESTRUCTEUR
    JeuPlateau(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA) : Jeu(nbJoueurs, nomJoueurs, IA) { plateau = nullptr; }
    ~JeuPlateau();

    //imperatif d'initialise plateau
    void init(std::vector<Carte*>& cartes);
    void init(std::vector<Carte*>& cartes, Pioche& pioche);


    //Methodes agissant sur le plateau a l'echelle du jeu
    Paquet& getPaquetByNomPlateau(std::string& nom) const override { return plateau->getPaquetByNom(nom); }
    std::vector<Paquet*> getAllPaquetsPlateau() const override { return plateau->getAllPaquets(); }
    unsigned int getNbPaquetsPlateau() const override { return plateau->getNbPaquets(); }
    std::vector<Paquet*> getPaquetsNonVidesPlateau() const override { return plateau->getPaquetsNonVides(); }
    Carte* retirerCartePlateau(std::string& nom) override { return plateau->retirerCarte(nom); }
    void afficherPlateau() const  override { plateau->afficherPlateau(); }
    void ajouterCartePlateau(Carte* carte) const  override { plateau->ajouterCarte(carte); }
    unsigned int getNbMonuments() const override { return plateau->getNbMonuments(); }

};
//------------Classe JeuPlateau----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUPLATEAU_H
