#pragma once

#include <vector>
#include <iostream>
#include "Effet.h"
#include "Carte.h"
//using namespace std;
class Joueur;


class EffetMarina : public EffetClassique {
protected:
	bool recevoirAvecPort;
	bool recevoirPieceChaqueChampDeFleurs;
	bool volerAvecPort;
	bool maisonEdition;
	bool tax;


public:
    EffetMarina(std::string description, unsigned int piecesEnJeu = 0, bool recevoirAvecPort = false,
		 bool recevoirPieceChaqueChampDeFleurs = false, bool volerAvecPort = false,
		bool maisonEdition = false, bool tax = false, bool recevoirPieces = false,
		bool volePieces = false, bool echangeCarte = false, bool volePiecesChaqueJoueur = false,
		bool recevoirPiecesNbEtablissement = false, bool choixJoueur = false, Type typeConcerne = Type::champ,
		bool gare = false) : recevoirAvecPort(recevoirAvecPort),
		recevoirPieceChaqueChampDeFleurs(recevoirPieceChaqueChampDeFleurs), volerAvecPort(volerAvecPort),
		maisonEdition(maisonEdition), tax(tax),
		EffetClassique(description, piecesEnJeu, gare, recevoirPieces, volePieces, echangeCarte, volePiecesChaqueJoueur, recevoirPiecesNbEtablissement, choixJoueur, typeConcerne) {}
	~EffetMarina() = default;


	
    std::string runEffect (Joueur* j1, std::vector<Joueur*> vectJoueur) override;
    std::string runEffect(Joueur* j1) override;
    std::string runEffect(Joueur* j1, Joueur* j2) override;

};

//****************class Effet*******************//

//********************Fonctions supplementaires**************************//
std::ostream& operator<<(std::ostream& f, const Effet& e);
//********************Fonctions supplementaires**************************//


