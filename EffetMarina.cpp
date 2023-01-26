#include "Effet.h"
#include "EffetMarina.h"
#include "Joueur.h"
#include "fonctions.h"



std::string EffetMarina::runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur) {
	
	if (maisonEdition) {
        //std::cout << "\n" << "------------Recevoir une piece de chaque joueur pour chaque carte de type cafe et magasin------------" << "\n";
		for (auto joueur : vectJoueur) {
			if (joueur != j1) {
				int nbCafe = joueur->getPaquet().getCarteType(Type::cafe).size();
				int nbMagasin = joueur->getPaquet().getCarteType(Type::magasin).size();
                std::cout << "nb cafe " << nbCafe << "\n";
                std::cout << "nb magasin " << nbMagasin << "\n";
				if (nbCafe > 0 || nbMagasin > 0)
                    return volerPieces(j1, joueur, nbCafe+nbMagasin);
			}
		}	
	}
	if (tax) {
        //std::cout << "\n" << "------------Voler la moitie des pieces de chaque joueur ayant plus de 10 pieces------------" << "\n";
		for (auto joueur : vectJoueur) {
			if (joueur != j1) {
				int argentJoueur = joueur->getMoney();
				if (argentJoueur >= 10) {
                    return volerPieces(j1, joueur, argentJoueur/2);
				}
					

			}
		}
        return"";
	}
    std::string retour = EffetClassique::runEffect(j1, vectJoueur);
	return retour;
}

std::string EffetMarina::runEffect(Joueur* j1, Joueur* j2) {

	if (volerAvecPort) {
		//cas ou j1 prend de l'argent a j2
        //std::cout << "\n" << "------------Voler des Pieces si le joueur a un port------------" << "\n";
        std::string port = "Port";
		if (j1->getPaquet().is_In(port)) {
            //std::cout << "dans le if \n";
            return volerPieces(j1, j2, piecesEnJeu);
        }
        return "";
	}
    std::string retour = EffetClassique::runEffect(j1, j2);
	return retour;
}

std::string EffetMarina::runEffect(Joueur* j1) {
	if (recevoirAvecPort) {
        //std::cout << "\n" << "------------Recevoir des pieces si le joueur a le port------------" << "\n";
        std::string port = "Port";
		if (j1->getPaquet().is_In(port))
            return ajouterPieces(j1, piecesEnJeu);
        return "";
	}
	if (recevoirPieceChaqueChampDeFleurs) {
        //std::cout << "\n" << "------------Recevoir des pieces nb champ de fleurs------------" << "\n";
        std::string champDeFleurs = "Champ de fleurs";
		int nbChampDeFleurs = j1->getPaquet().getCarteNom(champDeFleurs).size();
        //std::cout << "nb champ de fleurs " << nbChampDeFleurs << "\n";
		if (nbChampDeFleurs>0)
            return ajouterPieces(j1, nbChampDeFleurs*piecesEnJeu);
        return "";
	}
    std::string retour = EffetClassique::runEffect(j1);
	return retour;
}
//****************class EffetClassique*******************//
