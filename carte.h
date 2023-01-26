#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <cstdlib>
//#include "Effet.h"
#include <vector>
#include <algorithm>
//using namespace std;

class Effet;
class Joueur;

//*---------------------Classe pour les exceptions---------------------*//

class CarteException {
public:
    CarteException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};

//*---------------------Classe pour les exceptions---------------------*//

//*---------------------Enumerations de Type et Couleur---------------------*//

// class d'enumeration
enum class Couleur { bleu, vert, rouge, violet, monument };
enum class Type { champ, ferme, cafe, magasin, tour, industrie, ressource, marche, bateau, entreprise };

// conversion en string
std::string toString(Couleur c);
std::string toQtColor(Couleur c);
std::string toString(Type t);

// ecriture d'une caracteristique sur un flux ostream
std::ostream& operator<<(std::ostream& f, Couleur c);
std::ostream& operator<<(std::ostream& f, Type t);

// listes contenant les valeurs possibles pour chacune des caracteristiques
extern std::initializer_list<Couleur> Couleurs;
extern std::initializer_list<Type> Types;

// affichage des valeurs possibles pour chaque caracteristiques
void printCouleurs(std::ostream& f = std::cout);
void printTypes(std::ostream& f = std::cout);
//*---------------------Enumerations de Type et Couleur---------------------*//



//*---------------------Classe Carte---------------------*//

class Carte {
private:
	Effet* effet;
	Couleur couleur;
	unsigned int prix;
    std::vector<int> activation;
    std::string nom;
	Type type;
	Carte(const Carte&) = delete;
	Carte operator=(const Carte&) = delete;
public:
    Carte(Effet* effet, Couleur couleur, unsigned int prix, std::vector<int> activation, std::string nom, Type type) : effet(effet),
		couleur(couleur), prix(prix), activation(activation), nom(nom), type(type) {}
	~Carte() = default;
	Couleur getCouleur() const { return couleur; }
	Effet* getEffet() const;
	unsigned int getPrix() const { return prix; }
    std::vector<int> getActivation() const { return activation; }
    std::string getNom() const { return nom; }
	Type getType() const { return type; }
	bool isActivable(int checkValue) const;

    std::string runEffect(Joueur* j1);
    std::string runEffect(Joueur* j1, Joueur* j2);
    std::string runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur);
};
std::ostream& operator<<(std::ostream& f, const Carte& c);

//*---------------------Classe Carte---------------------*//
