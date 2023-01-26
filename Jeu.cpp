//
// Created by Harry Broudehoux on 29/11/2022.
//

#include "Jeu.h"
#include <iostream>
#include <cmath>
#include <QMessageBox>
//using namespace std;



//**--------------------Classe Jeu---------------------**//
//-----------------------Constructeurs et destructeur-----------------------//
Jeu::Jeu(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA) {
/*
    //-----------On demande a l'utilisateur combien de joueurs
    unsigned int nb = 0;
    std::cout << "Veuillez entrer le nombre de joueurs pour cette partie :\n";
    while (!(std::cin >> nb) || nb < 2) {
        std::cout << "Erreur ! Nombre invalide.\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    */
    Jeu::nbJoueurs = nbJoueurs;

    //-----------Variable permettant d'initialiser les joueurs de jeu
    //std::string p;
    //bool Ia;
    //std::string art;
    unsigned int money = 3;
    unsigned int des = 1;

    Paquet paquet;
    //QMessageBox* message = new QMessageBox();
    //---------------L'utilisateur rentre les infos des joueurs
    for (int i = 0; i < nbJoueurs; i++) {
/*
        std::cout << "\n\n";
        std::cout << "Pseudo du " << (i + 1) << ((i == 0) ? "er joueur :" : "eme joueur : \n");
        std::cin >> p;

        std::cout << "\nEst ce une IA? (Oui/Non)\n";
        std::cin >> art;

        Ia = (art == "Oui" || art == "oui");
*/
        //message->setText(QString::fromUtf8(nomJoueurs[i]));
        //message->exec();
        //message->setText("Test");
        //message->exec();
        //----------------creation du joueur
        joueurs.push_back(new Joueur(nomJoueurs[i], IA[i], paquet, money, des));
    }

    //delete message;
    //-----------initialisation du de
    unsigned int min=1;
    unsigned int max=6;
/*
    std::cout << "Valeur minimale du de?\n";
    while (!(std::cin >> min) || min < 1) {
        std::cout << "Erreur ! Valeur invalide.\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }


    std::cout << "Valeur maximale du de?\n";
    while (!(std::cin >> max) || max < 1 || max < min) {
        std::cout << "Erreur ! Valeur invalide.\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    */
    Jeu::de = new De(min, max);


}


Jeu::~Jeu() {
    for (auto j : joueurs) {
        delete j;
    }
    delete de;
} 
//**-----------------------Constructeur et destructeur-----------------------**//



Joueur& Jeu::getJoueur(size_t i) const {
    if (i > nbJoueurs) throw JeuException("Le joueur n'existe pas");
    return *joueurs[i];
}

void Jeu::retirerJoueur(Joueur* j){
    auto position = std::find(joueurs.begin(), joueurs.end(), j);
    if (position != joueurs.end()) // == myVector.end() means the element was not found
        joueurs.erase(position);
}

void Jeu::ajouterCarteJoueur(size_t i, Carte* carte) {
    if (i > nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->ajouterCarte(carte);
}
Carte* Jeu::retirerCarteJoueur(size_t i, Carte* c) {
    if (i > nbJoueurs) throw JeuException("Le joueur n'existe pas");
    return joueurs[i]->retirerCarte(c);
}
Carte* Jeu::retirerCarteJoueur(size_t i, std::string& nom) {
    if (i > nbJoueurs) throw JeuException("Le joueur n'existe pas");
    return joueurs[i]->retirerCarte(nom);
}

void Jeu::changerMoneyJoueur(size_t i, int n) {
    if (i > nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->changerMoney(n);
}
void Jeu::changerDesJoueur(size_t i, int n) {
    if (i > nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->changerDes(n);
}

void Jeu::afficherJeu() {
    std::cout << "\n";
    if (joueurs.size() == 0) throw JeuException("Aucun joueur, rien a afficher");
    std::vector<Joueur*>::iterator it;
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    for (it = joueurs.begin(); it != joueurs.end(); it++)
    {
        std::cout << "| Pseudo : " << it.operator*()->getPseudo() << " | IA : " << ((it.operator*()->getIa()) ? "Oui" : "Non") << " | Nombre de cartes : " << it.operator*()->getPaquet().getNbCartes() << " | Porte-monnaie : " << it.operator*()->getMoney() << "| Nombre de des : " << it.operator*()->getDes() << " |" << std::endl;
    }
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\n";
}



//**--------------------Classe Jeu---------------------**//


//----------------------Fonctions supplementaires-------------------------//
//**------------------Fonctions supplementaires-------------------------**//
