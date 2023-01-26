//
// Created by Antoine Sesini on 29/11/2022.
//
#include "Joueur.h"


//****************class Joueur*******************//




//Constructeurs et destructeurs//
//ILS SONT TOUS DEJA DEFINIS DE BASE
//Constructeurs et destructeurs//



//Methods de service//
void Joueur::ajouterCarte(Carte* carte) {
    if (carte != nullptr) {
        cartes.ajouterCarte(carte);
        ferme.push_back(false);
    }
    else
        throw JoueurException("La carte a ajouter n'existe pas !");
}
Carte* Joueur::retirerCarte(Carte* carte) {
    std::vector<Carte*> Cartes = cartes.getContener();
    if (carte != nullptr) {
        //cartes.retirerCarte(carte);
        auto itferme = ferme.begin();
        auto it = Cartes.begin();
        while (it != Cartes.end() && *it != carte) {
            it++;
            itferme++;
        }
        if (it != Cartes.end()) {
            cartes.retirerCarte(carte);
            ferme.erase(itferme);
        }
    }
        
    else
        throw JoueurException("La carte a retirer n'existe pas !");
    return carte;
}

Carte* Joueur::retirerCarte(std::string& nom) {
    std::vector<Carte*> Cartes = cartes.getContener();
    auto itferme = ferme.begin();
    auto it = Cartes.begin();
    Carte* result = nullptr;
    while (it != Cartes.end() && (*it)->getNom() != nom) {
        it++;
        itferme++;
    }
    if (it != Cartes.end()) {
        result = (*it);
        cartes.retirerCarte(nom);
        ferme.erase(itferme);
    }
    return result;

}



void Joueur::fermerOuvrirEtablissement(std::string& nom, bool fermer) {
    std::vector<Carte*> Cartes = cartes.getContener();
    auto itferme = ferme.begin();
    auto it = Cartes.begin();
    bool terminer = false;
    Carte* result = nullptr;
    while (it != Cartes.end() && terminer==false) {
        if ((*it)->getNom() == nom && (*itferme) != fermer) {
            (*itferme) = fermer;
            terminer = true;
        }      
        it++;
        itferme++;
    }
}

void Joueur::fermerOuvrirEtablissement(Carte* carte, bool fermer) {
    if (carte != nullptr) {
        std::vector<Carte*> Cartes = cartes.getContener();
        auto itferme = ferme.begin();
        
        auto it = Cartes.begin();
        
        while (it != Cartes.end() && *it != carte) {
            it++;
           itferme++;
        }
        
        if (it != Cartes.end()) {
            (*itferme) = fermer;
        }
        
    }
    else
        throw JoueurException("La carte a retirer n'existe pas !");
}

int Joueur::fermerOuvrirEtablissement(Type type, bool fermer) {
    int nbFerme = 0;
    auto itferme = ferme.begin();
    std::vector<Carte*> Cartes = cartes.getContener();
    for (auto carte : Cartes) {
        if (carte->getType() == type && *itferme != fermer) {
            *itferme = fermer;
            nbFerme++;
        }
    }
    return nbFerme;
}

bool Joueur::isFermer(std::string& nom) {
    std::vector<Carte*> Cartes = cartes.getContener();
    auto itferme = ferme.begin();
    auto it = Cartes.begin();
    Carte* result = nullptr;
    while (it != Cartes.end() && (*it)->getNom() != nom) {
        it++;
        itferme++;
    }
    if (it != Cartes.end()) {
        return *itferme;
    }
    else
        throw JoueurException("Erreur la carte rechercher n'est pas dans la paquet");
}

bool Joueur::isFermer(Carte* carte) {
    std::vector<Carte*> Cartes = cartes.getContener();
    if (carte != nullptr) {
        auto itferme = ferme.begin();
        auto it = Cartes.begin();
        while (it != Cartes.end() && *it != carte) {
            it++;
            itferme++;
        }
        if (it != Cartes.end()) {
            return *itferme;
        }
        else
            throw JoueurException("Erreur la carte rechercher n'est pas dans la paquet");
    }
    else
        throw JoueurException("La carte a retirer n'existe pas !");
}



void Joueur::afficherCartes() {
    std::cout << "/**********Affichage Paquet**********/\n";
    int i = 1;
    auto it = ferme.begin();
    for (auto carte : cartes.getContener()) {
        std::cout << "Carte n." << i;
        std::cout << *carte;
        i++;
        if (*it)
            std::cout << "Ferme\n";
        else
            std::cout << "Ouvert\n";
        std::cout << "\n";
        it++;
    }
    std::cout << "/**********Paquet Affiche**********/\n";



}

//Methods de service//


//****************class Joueur*******************//




//********************Fonctions supplementaires**************************//
std::ostream& operator<<(std::ostream& f, const Joueur& joueur) {
    f << "**-> PSEUDONYME : " << joueur.getPseudo() << "\n";
    f << "**-> IA         : " << ((joueur.getIa()) ? ("OUI") : ("NON")) << "\n";
    f << "**-> PAQUET     : " << joueur.getPaquet().getNbCartes() << " CARTE(S)\n";
    f << "**-> MONEY      : " << joueur.getMoney() << "\n";
    f << "**-> NB DE DES  : " << joueur.getDes() << "\n";

    return f;
}
//********************Fonctions supplementaires**************************//

