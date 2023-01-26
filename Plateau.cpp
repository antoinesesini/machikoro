//
// Created by Antoine Sesini on 26/11/2022.
//

#include "Plateau.h"
#include "Controleur.h"


//****************class Plateau*******************//


//**************Structure***************//
Plateau::Plateau(std::vector<Carte*> cartesJeu, unsigned int nbJoueurs) {
    if (cartesJeu.empty())
    {
        throw PlateauException("Creation de Plateau impossible, aucune carte n'est fournie");
    }
    /*Regle :
     * On fait des paquets de 6 partout
     * Paquets de nb joueurs violettes
     * Paquets de nb joueurs monuments
     * */
    nb_monuments = 0;
    int i = 0;
    for (auto c : cartesJeu)
    {
        Paquet* newPaquet = new Paquet;
        if (c->getCouleur() == Couleur::monument || c->getCouleur() == Couleur::violet)
        {
            if (c->getCouleur() == Couleur::monument)
            {
                nb_monuments++;
            }
            for (i = 0; i < nbJoueurs; i++)
            {
                newPaquet->ajouterCarte(c);
            }
        }
        else
        {
            for (i = 0; i < 6; i++)
            {
                newPaquet->ajouterCarte(c);
            }
        }
        cartes.push_back(newPaquet);
    }
}


Plateau::Plateau(std::vector<Carte*>& cartesJeu, Pioche& p, unsigned int nbJoueurs) : pioche(p) {
    if (cartesJeu.empty())
    {
        throw PlateauException("Creation de Plateau impossible, aucune carte n'est fournie");
    }
    if (p.getContener().empty())
    {
        throw PlateauException("Creation de Plateau impossible, aucune carte n'est fournie dans la pioche");
    }
    remplirPlateau(true); //remplir plateau ne gere que le maintient des paquets de cartes achetables mais pas les monuments

    //on doit donc ajouter les monuments avec cartesJeu
    nb_monuments = 0;
    int i = 0;
    for (auto c : cartesJeu)
    {
        if (c->getCouleur() == Couleur::monument)
        {
            nb_monuments++;
            Paquet* newPaquet = new Paquet;
            for (i = 0; i < nbJoueurs; i++)
            {
                newPaquet->ajouterCarte(c);
            }
            cartes.push_back(newPaquet);
        }
    }
}

Plateau::~Plateau() {
    for (auto p : cartes)
        delete p;
}
//**************Structure***************//


//Espace de definition des get et autres methodes d'utilisation//
Paquet& Plateau::getPaquetByNom(std::string& nom) const {
    for (auto p : cartes)
        if (p->getNbCartes() != 0 && p->getCarte(0).getNom() == nom) //Si la premiere carte du paquet a le nom "nom"
        {
            return *p;
        }
}

std::vector<Paquet*> Plateau::getAllPaquets() const {
    return cartes;
}

std::vector<Paquet*> Plateau::getPaquetsNonVides() const {
    std::vector<Paquet*> result;
    for (auto p : cartes)
        if (p->getNbCartes() != 0)
        {
            result.push_back(p);
        }
    return result;
}

unsigned int Plateau::getNbPaquets() const {
    return cartes.size();
}

void Plateau::ajouterCarte(Carte* carte) {

    //cas ou l'on ajoute un monument 
    // on souhaite l'ajouter au paquet avec les meme monument ou s'il y en a pas on l'ajoute a un paquet vide
    if (carte->getCouleur() == Couleur::monument)
    {
        bool ajouter = false;
        Paquet* paquetVide = nullptr;
        auto it = cartes.begin();
        while (it != cartes.end() && ajouter == false)
        {
            if ((*it)->getNbCartes() != 0 && (*it)->getCarte(0).getNom() == carte->getNom() && ajouter == false)
            {
                (*it)->ajouterCarte(carte);
                ajouter = true;
                std::cout << *(*it);
            }
            if ((*it)->getNbCartes() == 0)
            {
                paquetVide = *it;
            }
            it++;
        }
        if (paquetVide == nullptr && ajouter == false)
            throw PlateauException("Erreur il y a un probleme de disponibilite des paquets vides pour les monuments");

        if (ajouter == false)
        {
            paquetVide->ajouterCarte(carte);
        }


    }
    //cas ou on ajoute une autre carte on souhaite l'ajouter dans le paquet avec la meme carte ou rajouter un paquet s'il n'y a pas de paquet avec cette carte
    else
    {
        bool ajouter = false;
        auto it = cartes.begin();
        while (it != cartes.end() && ajouter == false)
        {
            if ((*it)->getNbCartes() != 0 && (*it)->getCarte(0).getNom() == carte->getNom() && ajouter == false)
            {
                (*it)->ajouterCarte(carte);
                ajouter = true;
            }
            it++;
        }

        if (ajouter == false)
        {
            Paquet* newPaquet = new Paquet; //creation
            newPaquet->ajouterCarte(carte); //ajout de la carte
            cartes.push_back(newPaquet); //push dans le contener de paquets du plateau
        }

    }

}


Carte* Plateau::retirerCarte(std::string& nom) { //le but est de parvenir a retirer des cartes par nom
    //Si l'utilisateur choisit de recuperer une carte depuis le paquet nomme
    //Alors on enleve la carte (method retirerCarte())
    //Si le paquet dans lequel on pioche devient vide -> on le supprime puis :
    //Si on a remplir = true alors on rerempli
    //Sinon on ne fait rien
    //On la retourne

    //Ici on saisie une carte a prendre
    Paquet* paquet = &getPaquetByNom(nom); //ici on imagine que cette fonction est appelee apres que l'on ait affiche les paquets non vides du plateau et saisi une carte sur le plateau
    Couleur couleur = paquet->getCarte(0).getCouleur();
    if (paquet == nullptr) {
        throw PlateauException("La carte est demandee dans un paquet inexistant");
    }
    Carte* carte = paquet->retirerCarte();
    if (carte == nullptr) {
        throw PlateauException("La carte n'a pas ete retiree");
    }

    //Dans le cas ou c'est un monument qui est retire on souhaite garder le paquet vide pour eviter de remplir le plateau
    if (paquet->getNbCartes() == 0 && couleur != Couleur::monument) {
        std::vector<Paquet*>::iterator it;
        it = find(cartes.begin(), cartes.end(), paquet);
        if (it != cartes.end())
            cartes.erase(it); //On enleve le paquet vide de notre plateau
        delete paquet;
    }
    remplirPlateau(false);
    return carte;

}


void Plateau::remplirPlateau(bool firstCall) { //Cette fonction est appelee lorsque retirerCarte se retrouve avec un paquetvide et la necessite de remplir
    //On va piocher et creer des paquets jusqu'a ce que cartes.size==10;
    //A noter : une pioche est un paquet dans lequel on met 6 cartes de chaque + nbJoueurs cartes violettes : on ne met pas les monuments
    if (pioche.getNbCartes() > 0) // si il reste des cartes dans la pioche
    {


        while (cartes.size() < 10 && firstCall || cartes.size() < (10 + nb_monuments) && !firstCall) {
            Carte* carte = pioche.piocher();
            bool added = false;
            //Si il existe un paquet deja cree pour l'accueillir -> on l'insere
            //Sinon on creer un paquet puis on l'insere
            for (auto p : cartes) {
                if (p->is_In(carte)) {
                    p->ajouterCarte(carte);
                    added = true;
                    break;
                }
            }
            if (!added) {//Si on a pas trouve un paquet dans lequel inserer la carte, on le creer et on l'insere
                Paquet* newPaquet = new Paquet; //creation
                newPaquet->ajouterCarte(carte); //ajout de la carte
                cartes.push_back(newPaquet); //push dans le contener de paquets du plateau
            }
        }
        //En sortie, on a un plateau avec une size==10 ou size==14 selon l'appel
    }
}


void Plateau::afficherPlateau() const {
    std::cout << "\n";
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    for (auto p : cartes)
    {
        if (!p->getContener().empty())
        {
            Carte* current = &(p->getCarte(0));
            std::cout << "| NOMBRE RESTANT : " << p->getNbCartes() << " | Nom : " << current->getNom() << " | Couleur : " << current->getCouleur() << " | ";
            std::cout << "Activation : ";
            if (current->getCouleur() != Couleur::monument)
            {
                for (auto i : current->getActivation())
                    std::cout << i << " ";
            }
            std::cout << "| Type : " << current->getType() << " | Prix : " << current->getPrix() << " |" << std::endl;
        }
    }
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

    std::cout << "\n";
}

//Espace de definition des get et autres methodes d'utilisation//






//****************class Plateau*******************//


std::ostream& operator<<(std::ostream& f, const Plateau& p) {
    p.afficherPlateau();
    return f;
}
