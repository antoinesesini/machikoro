#pragma once

#include <vector>
#include <iostream>
#include "Effet.h"
#include "EffetMarina.h"
#include "Carte.h"
class Joueur;


class EffetGreenValley : public EffetMarina {
private:
	bool recevoirAvecMoinsDeNMonuments;
	bool volerAvecPlusDeNMonuments;
	bool volerToutAvecPlusDeNMonuments;
	int nMonuments;
	bool donnerCarteEtRecevoir;
	bool payerPieces;
	bool recevoirPieceChaqueVignoblePuisFermer;
	bool demolirMonumentPuisRecevoir;
	bool pourChaqueTypePourTousLesJoueursRecevoir;
	bool equilibrePieces;
	bool renovation;
	bool recevoirInvestissement;
	bool activeAutre;


public:
    EffetGreenValley(std::string description, unsigned int piecesEnJeu = 0, bool recevoirAvecMoinsDeNMonuments = false,
		bool volerAvecPlusDeNMonuments = false,	bool volerToutAvecPlusDeNMonuments= false,
		int nMonuments = 0, bool donnerCarteEtRecevoir = false, bool payerPieces = false, 
		bool recevoirPieceChaqueVignoblePuisFermer = false, bool demolirMonumentPuisRecevoir = false,
		bool pourChaqueTypePourTousLesJoueursRecevoir = false, bool equilibrePieces = false,
		bool renovation = false, bool recevoirInvestissement = false, bool activeAutre = false, bool recevoirPieces = false,
		bool volePieces = false, bool echangeCarte = false, bool volePiecesChaqueJoueur = false,
		bool recevoirPiecesNbEtablissement = false, bool choixJoueur = false, Type typeConcerne = Type::champ,
		bool gare = false, bool recevoirAvecPort = false,
		bool recevoirPieceChaqueChampDeFleurs = false, bool volerAvecPort = false,
		bool maisonEdition = false, bool tax = false) : recevoirAvecMoinsDeNMonuments(recevoirAvecMoinsDeNMonuments),
		volerAvecPlusDeNMonuments(volerAvecPlusDeNMonuments), 
		volerToutAvecPlusDeNMonuments(volerToutAvecPlusDeNMonuments),
		nMonuments(nMonuments), donnerCarteEtRecevoir(donnerCarteEtRecevoir), payerPieces(payerPieces),
		recevoirPieceChaqueVignoblePuisFermer(recevoirPieceChaqueVignoblePuisFermer),
		demolirMonumentPuisRecevoir(demolirMonumentPuisRecevoir),
		pourChaqueTypePourTousLesJoueursRecevoir(pourChaqueTypePourTousLesJoueursRecevoir),
		equilibrePieces(equilibrePieces), renovation(renovation),
		recevoirInvestissement(recevoirInvestissement), activeAutre(activeAutre),
		EffetMarina(description, piecesEnJeu, recevoirAvecPort, recevoirPieceChaqueChampDeFleurs,
			volerAvecPort, maisonEdition, tax, recevoirPieces, volePieces, echangeCarte,
			volePiecesChaqueJoueur, recevoirPiecesNbEtablissement, choixJoueur, typeConcerne,
			 gare  ) {}
	~EffetGreenValley() = default;



    std::string runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur) override;
    std::string runEffect(Joueur* j1) override;
    std::string runEffect(Joueur* j1, Joueur* j2) override;
	void donnerCarte(Joueur* j1);
	int demolir(Joueur* j1);
    std::string equilibrerPieces(std::vector<Joueur*> joueurs);
    int activerAutre(Joueur* j, std::vector<Joueur*> joueurs);
};

//****************class Effet*******************//

//********************Fonctions supplementaires**************************//
std::ostream& operator<<(std::ostream& f, const Effet& e);
//********************Fonctions supplementaires**************************//
