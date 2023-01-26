#include "Effet.h"
#include "JeuClassique.h"
#include "EffetGreenValley.h"
#include "Joueur.h"
#include "fonctions.h"
#include "Controleur.h"


void EffetGreenValley::donnerCarte(Joueur* j1) {
    std::vector <Joueur*> vectJoueur = Controleur::getControleur().getJeu()->getJoueursList();
	if (j1->getPaquet().getCarteType(Type::tour).size() != j1->getPaquet().getContener().size()) {
        std::cout << "Vous devez donner une carte" << "\n";
		bool terminer = false;
		int position = fonctions::recupPositionJoueur(j1, vectJoueur);
		int cpt = 1;
		//potentiel erreurs si vect joueur vide ou s'il y a des paquets vides

		for (auto n : vectJoueur)
			if (j1 != n) {
                std::cout << "Joueur n " << cpt << *n << "\n";
				cpt++;
			}
		Joueur* jChoisi = nullptr;
		while (!terminer) {
			jChoisi = fonctions::choisirJoueur(j1, vectJoueur);
			if (jChoisi->getPaquet().getCarteType(Type::tour).size() != jChoisi->getPaquet().getContener().size())
				terminer = true;
			else
                std::cout << "Erreur " << jChoisi->getPseudo() << " n'a pas de carte a echanger";
		}


		Paquet paquetJ1 = j1->getPaquet();


        std::cout << "\n" << paquetJ1 << "\n";
        std::cout << "Attention vous ne pouvez pas choisir une carte de type Tour" << "\n";
        std::cout << "Choisissez la carte que vous souhaitez donner" << "\n";
		Carte* cJ1 = nullptr;
		terminer = false;
		while (!terminer) {
			cJ1 = fonctions::choisirCarte(paquetJ1.getContener());
			if (cJ1->getType() != Type::tour)
				terminer = true;
			else
                std::cout << "Erreur la carte choisi est de type tour" << "\n";
		}

		jChoisi->ajouterCarte(cJ1);
		j1->retirerCarte(cJ1);

		//cout << "\n" << "----------resume-------------" << "\n";
        std::cout << j1->getPseudo() << " a donner la carte " << cJ1->getNom()
			<< " a " << jChoisi->getPseudo() << "\n";
	}
	else
        std::cout << "Activation de l'effet impossible " << j1->getPseudo() << " n'a pas de carte a echanger" << "\n";
}

std::string EffetGreenValley::equilibrerPieces(std::vector<Joueur*> joueurs) {
	int ToutesLesPieces = 0;
	for (auto joueur : joueurs) {
		ToutesLesPieces += joueur->getMoney();
		joueur->changerMoney(0);
	}
	int division = ToutesLesPieces / joueurs.size();
	if (division * joueurs.size() < ToutesLesPieces)
		division++;
	for (auto joueur : joueurs)
		joueur->changerMoney(division);

	//resume
    return "Tous les joueurs possedent maintenant " + std::to_string( division) + " piece(s)\n";
}

int EffetGreenValley::activerAutre(Joueur* j, std::vector<Joueur*> joueurs) {
    std::cout << "Souhaitez vous activez un autre etablissement bleu ou vert que vous possedez ? (Oui/Non)\n";
    std::string choix1;
    while (!(std::cin >> choix1) || (choix1 != "Oui" && choix1 != "Non" && choix1 != "oui" && choix1 != "non")) {
        std::cout << "Erreur ! Input invalide.\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
	}
	if (choix1 == "Oui" || choix1 == "oui") {
        std::vector<Carte*> cartes = j->getPaquet().getCarteCouleur(Couleur::bleu);
        std::vector<Carte*> cartesVert = j->getPaquet().getCarteCouleur(Couleur::vert);
		cartes.insert(cartes.end(), cartesVert.begin(), cartesVert.end());

		int i = 1;
		for (auto carte : cartes) {
            std::cout << "Carte n" << i;
            std::cout << *carte << "\n";
			i++;
		}

		Carte* carteChoisi = fonctions::choisirCarte(cartes);
		carteChoisi->runEffect(j);
        std::cout << "L'effet de " << carteChoisi->getNom() << " a ete active\n";
		return 0;
	}
	return -1;
}

int EffetGreenValley::demolir(Joueur* j1) {
    std::vector <Carte*> monuments = j1->getPaquet().getCarteCouleur(Couleur::monument);
	int nbMonuments=monuments.size();
    std::string hdv = "Hotel de Ville";
	int nbHdv=j1->getPaquet().getCarteNom(hdv).size();
	if (nbMonuments == nbHdv) {
        std::cout << "impossible de detruire un monument" << "\n";
		return -1;
	}
    std::string hotel = "Hotel de Ville";
	int i = 1;
	for (auto monument : monuments) {
		if (monument->getNom() != hdv)
            std::cout << "Carte n" << i << *monument << "\n";
		i++;
	}

	Carte* choix = fonctions::choisirMonumentSauf(j1,hotel);
	j1->retirerCarte(choix);
	Controleur::getControleur().getJeu()->ajouterCartePlateau(choix);
    std::cout << choix->getNom() << " a ete demoli " << "\n";
	return 0;
}

std::string EffetGreenValley::runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur) {
	if (equilibrePieces) {
        return equilibrerPieces(vectJoueur);
	}
	if (renovation) {
		int nbFerme = 0;
		int i = 1;
		for (auto type : Types)
		{
            std::cout << "Type n" << i << " : " << "type" << "\n";
		}
		Type type = fonctions::choisirType();
		for (auto joueur : vectJoueur) {
			nbFerme += joueur->fermerOuvrirEtablissement(type, true);
		}
		ajouterPieces(j1, nbFerme * piecesEnJeu);
        std::cout << "Et a ferme les etablisssements de type " << type << "\n";
	}

	if (recevoirInvestissement) {
		for (auto joueur : vectJoueur) {
			if (joueur != j1)
				volerPieces(j1, joueur, j1->getInvestissement());
		}

        return "";
	}
	if (activeAutre) {
        std::string expo = "Salle d'exposition internationale";
        std::vector<Carte*> cartes=j1->getPaquet().getCarteNom(expo);
		if (activerAutre(j1, vectJoueur) == 0)
		{
			j1->retirerCarte(cartes.at(0));
			Controleur::getControleur().getJeu()->ajouterCartePlateau(cartes.at(0));
            std::cout << expo << " a ete retourne au marche " << "\n";
		}
        return "";
	}
    std::string retour = EffetMarina::runEffect(j1, vectJoueur);
	return retour;
}

std::string EffetGreenValley::runEffect(Joueur* j1, Joueur* j2) {
	if (volerAvecPlusDeNMonuments) {
		if (getNbmonumentSaufHotelDeVille(j1) >= nMonuments)
            return volerPieces(j1, j2, piecesEnJeu);
        return "";
	}
	if (volerToutAvecPlusDeNMonuments) {
		if (getNbmonumentSaufHotelDeVille(j2) >= nMonuments)
            return volerPieces(j1, j2, j2->getMoney());
        return "";
	}
    std::string retour = EffetMarina::runEffect(j1, j2);
	return retour;
}

std::string EffetGreenValley::runEffect(Joueur* j1) {
	if (recevoirAvecMoinsDeNMonuments) {
		if (getNbmonumentSaufHotelDeVille(j1) < nMonuments)
            return ajouterPieces(j1, piecesEnJeu);
        return "";
	}

	if (donnerCarteEtRecevoir) {
		donnerCarte(j1);
        ajouterPieces(j1, piecesEnJeu);
        return "";
	}

	if (payerPieces) {
        return enleverPieces(j1, piecesEnJeu);
        return "";
	}

	if (recevoirPieceChaqueVignoblePuisFermer) {
        std::string vignoble = "Vignoble";
        std::string caveAVin = "Cave a vin";
		int nbVignobles = j1->getPaquet().getCarteNom(vignoble).size();
		j1->fermerOuvrirEtablissement(caveAVin, true);
        return ajouterPieces(j1, nbVignobles*piecesEnJeu);
        return "";
	}

	if (demolirMonumentPuisRecevoir) {
		if (demolir(j1)==0)
            return ajouterPieces(j1, piecesEnJeu);
        return "";
	}
	
	if (pourChaqueTypePourTousLesJoueursRecevoir) {
        std::vector<Joueur*> joueurs = Controleur::getControleur().getJeu()->getJoueursList();
		int nbType=0;
		for (auto joueur : joueurs) {
			nbType+=joueur->getPaquet().getCarteType(typeConcerne).size();
		}
        return ajouterPieces(j1, piecesEnJeu*nbType);
        return "";
	}

    std::string retour = EffetMarina::runEffect(j1);
	return retour;
}
//****************class EffetClassique*******************//
