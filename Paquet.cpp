#include "Paquet.h"
#include <vector>
//****************class Paquet*******************//

bool Paquet::is_In(Carte* c) const {
    return (find(cartes.begin(), cartes.end(), c) != cartes.end());
}

bool Paquet::is_In(std::string& nom) const {
    return (find_if(cartes.begin(), cartes.end(), [&nom](Carte* c) {return c->getNom() == nom; }) != cartes.end());
}



Carte* Paquet::retirerCarte(std::string& nom) {
    if (cartes.empty())
    {
        throw PaquetException("Ce paquet ne contient aucune carte");
    }
    else {
        std::vector<Carte*>::iterator it;
        //On retrouve la carte dont le nom est "nom"
        it = find_if(cartes.begin(), cartes.end(), [&nom](Carte* c) {return c->getNom() == nom; });


        Carte* result = nullptr;
        if (it != cartes.end()) //si la carte a ete trouvee, on l'efface
        {
            result = (*it);
            cartes.erase(it);
        }
        else
        {
            throw PaquetException("Cette carte n'est pas dans le paquet !");
        }
        return result;
    }
}

Carte* Paquet::retirerCarte(Carte* c) {
    if (cartes.empty())
    {
        throw PaquetException("Ce paquet ne contient aucune carte");
    }
    else {
        std::vector<Carte*>::iterator it; //on creer un iterateur fait pour travailler dans un vecteur de pointeurs de Carte
        it = find(cartes.begin(), cartes.end(), c); //on lui affecte l'index de la carte

        Carte* result = nullptr;
        if (it != cartes.end()) //si la carte a ete trouvee, on l'efface
        {
            result = (*it);
            cartes.erase(it);
        }
        return result;
    }
}

Carte* Paquet::retirerCarte() {
    Carte* carte = cartes.back();
    cartes.pop_back();
    return carte;
}


std::vector<Carte*> Paquet::getCarteCouleur(Couleur couleur)const {
    if (!cartes.empty())
    {
        std::vector<Carte*> result;
        for (auto c : cartes)
        {
            if (c->getCouleur() == couleur)
                result.push_back(c);
        }
        return result;
    }
    else
        throw PaquetException("Ce paquet ne contient aucune carte");
}

std::vector<Carte*> Paquet::getCarteType(Type type) const {
    if (!cartes.empty())
    {
        std::vector<Carte*> result;
        for (auto c : cartes)
        {
            if (c->getType() == type)
                result.push_back(c);
        }
        return result;
    }
    else
        throw PaquetException("Ce paquet ne contient aucune carte");
}

std::vector<Carte*> Paquet::getCarteActive(int activateur) const{
    if (activateur == 0)
    {
        throw PaquetException("Activateur 0 non existant");
    }
    else
    {
        if (!cartes.empty())
        {
            std::vector<Carte*> result;
            for (auto c : cartes)
                for (auto a : c->getActivation())
                    if (a == activateur)
                    {
                        result.push_back(c);
                        break;
                    }
            return result;
        }
        else
            throw PaquetException("Ce paquet ne contient aucune carte");
    }
}

std::vector<Carte*> Paquet::getCarteNom(std::string& nom) const {
    if (!cartes.empty())
    {
        std::vector<Carte*> result;
        for (auto c : cartes)
        {
            if (c->getNom() == nom)
                result.push_back(c);
        }
        return result;
    }
    else
        throw PaquetException("Ce paquet ne contient aucune carte");
}
//****************class Paquet*******************//





//****************Fonctions supplementaires******************//
std::ostream& operator<<(std::ostream& f, const Paquet& p) {
    f << "/**********Affichage Paquet**********/\n";
    int i = 1;
    std::vector<Carte*>cartes = p.getContener();
    for (auto c : cartes)
    {
        f << "Carte n." << i;
        f << *c << "\n";
        i++;
    }
    f << "/**********Paquet Affiche**********/\n";
    return f;
}
//****************Fonctions supplementaires******************//



