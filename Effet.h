#pragma once
#ifndef EFFET_H
#define EFFET_H
#include <vector>
#include <iostream>
#include "Carte.h"

//using namespace std;
class Joueur;


class EffetException {
public:
    EffetException(const std::string& i) :info(i) {}
    std::string getInfo() const { return info; }
private:
    std::string info;
};

class Effet {
protected:
	//bool ferme;
    std::string description;
	unsigned int piecesEnJeu;
	bool recevoirPieces;
	bool volePieces;
	bool echangeCarte;
	bool volePiecesChaqueJoueur;
	bool recevoirPiecesNbEtablissement;
	Type typeConcerne;
	bool choixJoueur;
public:
    std::string getDescription() const { return description; }

    Effet(std::string description, unsigned int piecesEnJeu = 0, bool recevoirPieces = false, bool volePieces = false,
		bool echangeCarte = false, bool volePiecesChaqueJoueur = false, bool recevoirPiecesNbEtablissement = false,
		bool choixJoueur = false, Type typeConcerne = Type::champ) :
		description(description), piecesEnJeu(piecesEnJeu), recevoirPieces(recevoirPieces),
		volePieces(volePieces), echangeCarte(echangeCarte),
		volePiecesChaqueJoueur(volePiecesChaqueJoueur),
		recevoirPiecesNbEtablissement(recevoirPiecesNbEtablissement),
		choixJoueur(choixJoueur), typeConcerne(typeConcerne) {}
	virtual ~Effet() = default;

	void changerPiecesEnJeu(unsigned int n) { piecesEnJeu = n; }
	void ajouterPiecesEnJeu(unsigned int n) { piecesEnJeu += n; }
	void enleverPiecesEnJeu(unsigned int n) { piecesEnJeu -= n; }

    virtual std::string runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur);
    virtual std::string runEffect(Joueur* j1);
    virtual std::string runEffect(Joueur* j1, Joueur* j2);
    std::string enleverPieces(Joueur* j, int nbPieces);
    std::string ajouterPieces(Joueur* j, int nbPieces);
    std::string volerPieces(Joueur* j1, Joueur* j2, unsigned int pieces);//vole le nombre de pieces de j2 pour le donner a j1
    int echangerCarte(Joueur* j1, std::vector<Joueur*> vectJoueur);
	int getNbmonumentSaufHotelDeVille(Joueur* j);
};

class EffetClassique : public Effet {
protected:
	bool gare;
public:
    EffetClassique(std::string description, unsigned int piecesEnJeu = 0, bool gare = false, bool recevoirPieces = false,
		bool volePieces = false, bool echangeCarte = false, bool volePiecesChaqueJoueur = false,
		bool recevoirPiecesNbEtablissement = false, bool choixJoueur = false, Type typeConcerne = Type::champ)
		: gare(gare),
		Effet(description, piecesEnJeu, recevoirPieces, volePieces, echangeCarte, volePiecesChaqueJoueur, recevoirPiecesNbEtablissement, choixJoueur, typeConcerne) {}
	~EffetClassique() = default;

    std::string runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur) override;
    std::string runEffect(Joueur* j1) override;
    std::string runEffect(Joueur* j1, Joueur* j2) override;

};

//****************class Effet*******************//

//********************Fonctions supplementaires**************************//
std::ostream& operator<<(std::ostream& f, const Effet& e);
//********************Fonctions supplementaires**************************//


#endif 
