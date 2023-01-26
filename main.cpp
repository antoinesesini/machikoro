#include "Carte.h"
#include "Paquet.h"
#include "Plateau.h"
#include "Joueur.h"
#include "Jeu.h"
#include "Effet.h"
#include "EffetMarina.h"
#include "EffetGreenValley.h"
#include "JeuClassique.h"
#include "fonctions.h"
#include "JeuGreenValley.h"
#include "Controleur.h"
#include "JeuPlateau.h"
#include <QApplication>
#include "VueCarte.h"
#include "VuePartie.h"
#include "VueParametre.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "VueJoueurs.h"

//using namespace std;

int main(int argc, char* argv[]) {
	/*
	//srand((unsigned)time(NULL));
	//test de vecteurs
    //std::vector<int> vect = { 1, 3 };
    //std::cout << vect[1] << "\n";

    std::cout << "test des types d'enum" << "\n";
	//test des types d'enumeration
	try {
		printCouleurs();
		printTypes();
	}
	catch (CarteException& e) {
        std::cout << e.getInfo() << "\n";
	}

    std::cout << "test des cartes" << "\n";
	//test des cartes
	//Effet effet;
    //std::cout << effet.getDescription() << "\n";
	//Carte c1(effet, Couleur::bleu, 2, vect, "Champ de ble", Type::champ);
    //std::cout << c1;

    std::vector<Carte*> cartes = fonctions::cartesEditionClassique();
	for (auto n : cartes) {
        std::cout << *n << "\n";
	}

    std::cout << "test des paquets" << "\n";
	//test des paquets
	Paquet paquet;
	for (auto n : cartes) {
		paquet.ajouterCarte(n);
	}

    std::vector<Carte*> cartas;
	try {
		cartas = paquet.getCarteActive(9);
	}
	catch (PaquetException& e) {
        std::cout << e.getInfo() << "\n";
	}
	for (auto n : cartas) {
        std::cout << *n << "\n";
	}


    std::cout << "test de de" << "\n";
	//test du de
	//seed permettant de faire des resultats vraiment aleatoire (on peut pas le mettre dans lancerDe() j'ai tester)


	De de(1, 6);
    std::cout << de;
	int random;
	for (size_t i = 0; i < 6; i++) {
		random = de.lancerDe();
        std::cout << random << "\n";
	}

    std::cout << "test de Pioche" << "\n";
	int nb_joueurs = 4;
	Pioche pioche(cartes, nb_joueurs);
    std::cout << "affichage pioche debut" << "\n";
    std::cout << pioche << "\n";
	Carte* c1 = pioche.piocher();
    std::cout << "c1 :" << *c1 << "\n";
    std::cout << "affichage pioche apres avoir piocher" << "\n";
    std::cout << pioche << "\n";

	Pioche pioche2(cartes, 4);
	try {
		Plateau plateau(cartes);
		plateau.afficherPlateau();
        std::string str = "Antoine";
		Paquet paquettest;
		Joueur player(str, 0, paquettest, 0, 1);
		player.ajouterCarte(cartes[9]);
        std::cout << "\n" << player << "\n";
        std::cout << player.getPaquet();

        std::string str1 = "Fromagerie";
        std::cout << *(player.retirerCarte(str1));
        std::cout << "\n" << player << "\n";
        std::cout << player.getPaquet();
	}
	catch (PaquetException& e) {
        std::cout << e.getInfo() << "\n";
	}
	//test des Effets Classique
	Paquet paquetAntoine;
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[1]);
	Paquet paquetMatthieu;
	paquetMatthieu.ajouterCarte(cartes[0]);
	paquetMatthieu.ajouterCarte(cartes[1]);
	Paquet paquetHarry;
	paquetHarry.ajouterCarte(cartes[7]);
	//paquetHarry.ajouterCarte(cartes[0]);
	//paquetMatthieu.ajouterCarte(cartes[1]);
	Paquet paquetMathieu;
	paquetMathieu.ajouterCarte(cartes[1]);
	paquetMathieu.ajouterCarte(cartes[0]);
	Joueur player1("Antoine", 0, paquetAntoine, 0, 1);
	Joueur player2("Matthieu", 0, paquetMatthieu, 2, 1);
	Joueur player3("Harry", 0, paquetHarry, 10, 1);
	Joueur player4("Mathieu", 0, paquetMathieu, 0, 1);
    std::vector <Joueur*> joueurs = { &player1, &player2 , &player3 ,&player4 };
    std::string chaine = "test";

    std::cout << "___________test Recevoir____________" << "\n";
	//recevoir fonctionne
	Effet* effetRecevoir = new Effet(chaine, 2, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
	effetRecevoir->runEffect(&player1);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";

    std::cout << "___________test voler____________" << "\n";
	//voler
	Effet* effetvoler = new Effet(chaine, 3, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";
	effetvoler->runEffect(&player1, &player2);
	effetvoler->runEffect(&player2, &player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";

    std::cout << "___________test voler tout le monde____________" << "\n";
	//voler
	Effet* effetvolertout = new Effet(chaine, 2, false, false, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";
    std::cout << player4 << "\n";

	effetvolertout->runEffect(&player1, joueurs);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";
    std::cout << player4 << "\n";

	int pos = fonctions::recupPosition(&player4, joueurs);
    std::cout << "position de joueur :" << pos << "\n";

	//Test de choisir carte
	int cpt = 1;
	for (auto n : cartes) {
        std::cout << "Carte n" << cpt << ":" << *n << "\n";
		cpt++;
	}
	Carte* c2 = fonctions::choisirCarte(cartes);
    std::cout << *c2;*/

	/*
	//echanger test fonctionne
    std::cout << "___________test echnager carte____________" << "\n";
	Effet* effetEchanger = new Effet(chaine, 5, false, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player1.getPaquet() << "\n\n";
    std::cout << player2 << "\n";
    std::cout << player2.getPaquet() << "\n\n";
    std::cout << player3 << "\n";
    std::cout << player3.getPaquet() << "\n\n";
    std::cout << player4 << "\n";
    std::cout << player4.getPaquet() << "\n\n";

	effetEchanger->runEffect(&player1, joueurs);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player1.getPaquet() << "\n\n";
    std::cout << player2 << "\n";
    std::cout << player2.getPaquet() << "\n\n";
    std::cout << player3 << "\n";
    std::cout << player3.getPaquet() << "\n\n";
    std::cout << player4 << "\n";
    std::cout << player4.getPaquet() << "\n\n";
	*/

	/*
    std::cout << "___________voler avec choix____________" << "\n";
	//voler avec choix
	Effet* effetvolerChoix = new Effet(chaine, 5, false, true, false, false, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";
    std::cout << player4 << "\n";

	effetvolerChoix->runEffect(&player1, joueurs);

    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";
    std::cout << player4 << "\n";

    std::cout << "___________recevoir en fonction d'un type____________" << "\n";
	//recevoir en fct d un type
	Effet* recevoirType = new Effet(chaine, 2, false, false, false, false, true, false, Type::champ);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";
    std::cout << player4 << "\n";

	recevoirType->runEffect(&player1);
    std::cout << recevoirType;
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
    std::cout << player3 << "\n";
    std::cout << player4 << "\n";

    std::cout << "___________Active gare____________" << "\n";
	//mettre deux des a quelqun
	Effet* gare = new EffetClassique(chaine, 0, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";

	gare->runEffect(&player1);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
	*/

	/*
	* //test des effets de EffetMarina
    std::vector<Carte*> cartes = fonctions::cartesEditionClassique();
    std::vector<int> v={};
    std::string porto = "Port";
	Carte* port = new Carte(new Effet("C'est le port"), Couleur::monument, 0, v, porto, Type::tour);
    std::string chmp = "Champ de fleurs";
	Carte* ChampDeFleurs = new Carte(new Effet("C'est le champ de fleurs"), Couleur::bleu, 0, v, chmp, Type::champ);
	int cpt = 0;
	for (auto carte : cartes) {
        std::cout << "Carte " << cpt << "\n";
        std::cout << *carte << "\n";
		cpt++;
	}


	Paquet paquetAntoine;
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[2]);
	paquetAntoine.ajouterCarte(port);
	paquetAntoine.ajouterCarte(ChampDeFleurs);
	paquetAntoine.ajouterCarte(ChampDeFleurs);
	Paquet paquetMatthieu;
	paquetMatthieu.ajouterCarte(cartes[0]);
	paquetMatthieu.ajouterCarte(cartes[2]);
	paquetMatthieu.ajouterCarte(port);
	Paquet paquetHarry;
	paquetHarry.ajouterCarte(cartes[0]);
	paquetHarry.ajouterCarte(cartes[2]);
	paquetHarry.ajouterCarte(cartes[3]);
	Paquet paquetMathieu;
	paquetMathieu.ajouterCarte(cartes[2]);
	paquetMathieu.ajouterCarte(cartes[0]);
	Joueur player1("Antoine", 0, paquetAntoine, 0, 1);
	Joueur player2("Matthieu", 0, paquetMatthieu, 2, 1);
	Joueur player3("Harry", 0, paquetHarry, 10, 1);
	Joueur player4("Mathieu", 0, paquetMathieu, 0, 1);
    std::vector <Joueur*> joueurs = { &player1, &player2 , &player3 ,&player4 };
    std::string chaine = "test";

    std::cout << "___________test Recevoir avec port____________" << "\n";
	//recevoir fonctionne
	Effet* effetRecevoir = new EffetMarina(chaine, 1, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetRecevoir->runEffect(&player1);
	effetRecevoir->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";


    std::cout << "___________test Recevoir pour chaque champ de fleur____________" << "\n";
	//recevoir fonctionne
	Effet* effetRecevoirChamp = new EffetMarina(chaine, 1, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetRecevoirChamp->runEffect(&player1);
	effetRecevoirChamp->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";

    std::cout << "___________test voler avec port____________" << "\n";
	//recevoir fonctionne
	Effet* effetVoler = new EffetMarina(chaine, 5, false, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetVoler->runEffect(&player1, &player3);
	effetVoler->runEffect(&player3, &player1);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";

    std::cout << "___________test maison edition____________" << "\n";
	//recevoir fonctionne
	Effet* effetMaison = new EffetMarina(chaine, 5, false, false, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetMaison->runEffect(&player1, joueurs);
	effetMaison->runEffect(&player3, joueurs);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	*/

	/*
	//test des Effets de GreenValley
    std::vector<Carte*> cartes = fonctions::cartesEditionClassique();
    std::vector<int> v = {};
    std::string vignobl = "Vignoble";
	Carte* vignoble = new Carte(new Effet("C'est le vignoble"), Couleur::bleu, 0, v, vignobl, Type::champ);
    std::string cava = "Cave a vin";
	Carte* CaveAVin = new Carte(new Effet("C'est la cave"), Couleur::vert, 0, v, cava, Type::magasin);
    std::string hdv = "Hotel de Ville";
	Carte* HotelDeVille = new Carte(new Effet("C'est l'hdv"), Couleur::monument, 0, v, hdv, Type::tour);
    std::string sei = "Salle d'exposition internationale";
	Carte* SalleDExpo = new Carte(new Effet("C'est la salle"), Couleur::violet, 0, v, sei, Type::tour);
	int cpt = 0;
	for (auto carte : cartes) {
        std::cout << "Carte " << cpt << "\n";
        std::cout << *carte << "\n";
		cpt++;
	}


	Paquet paquetAntoine;
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[2]);
	paquetAntoine.ajouterCarte(cartes[6]);
	paquetAntoine.ajouterCarte(cartes[16]);
	paquetAntoine.ajouterCarte(cartes[18]);
	paquetAntoine.ajouterCarte(cartes[17]);
	paquetAntoine.ajouterCarte(SalleDExpo);
	paquetAntoine.ajouterCarte(vignoble);
	paquetAntoine.ajouterCarte(vignoble);
	paquetAntoine.ajouterCarte(CaveAVin);
	paquetAntoine.ajouterCarte(HotelDeVille);
	//paquetAntoine.ajouterCarte(port);
	//paquetAntoine.ajouterCarte(ChampDeFleurs);
	//paquetAntoine.ajouterCarte(ChampDeFleurs);
	Paquet paquetMatthieu;
	paquetMatthieu.ajouterCarte(cartes[0]);
	paquetMatthieu.ajouterCarte(cartes[2]);
	//paquetMatthieu.ajouterCarte(port);
	Paquet paquetHarry;
	paquetHarry.ajouterCarte(cartes[0]);
	paquetHarry.ajouterCarte(cartes[2]);
	paquetHarry.ajouterCarte(cartes[3]);
	paquetHarry.ajouterCarte(CaveAVin);
	paquetHarry.ajouterCarte(HotelDeVille);
	Paquet paquetMathieu;
	paquetMathieu.ajouterCarte(cartes[2]);
	paquetMathieu.ajouterCarte(cartes[0]);
	Joueur player1("Antoine", 0, paquetAntoine, 0, 1);
	Joueur player2("Matthieu", 0, paquetMatthieu, 2, 1);
	Joueur player3("Harry", 0, paquetHarry, 10, 1);
	Joueur player4("Mathieu", 0, paquetMathieu, 0, 1);
    std::vector <Joueur*> joueurs = { &player1, &player2 , &player3 ,&player4 };
    std::string chaine = "test";

    std::cout << "___________test Recevoir avec moins de 2 monuments____________" << "\n";
	Effet* effetRecevoir = new EffetGreenValley(chaine, 2,true,false,false,2);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetRecevoir->runEffect(&player1);
	effetRecevoir->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
    std::cout << "___________test donner carte et recevoir____________" << "\n";
	Effet* effetDonner= new EffetGreenValley(chaine, 2, false, false, false, 0, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetDonner->runEffect(&player1);
	effetDonner->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	*/
	/*
    std::cout << "___________test payer piece____________" << "\n";
	Effet* effetPayer = new EffetGreenValley(chaine, 2, false, false, false, 0, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetPayer->runEffect(&player1);
	effetPayer->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";

    std::cout << "___________test recevoir pou chaque vignoble puis fermer cave a vin____________" << "\n";
	Effet* effetVignoble = new EffetGreenValley(chaine, 2, false, false, false, 0, false, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
	player1.afficherCartes();
    std::cout << player3 << "\n";
	player3.afficherCartes();
	effetVignoble->runEffect(&player1);
	effetVignoble->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
	player1.afficherCartes();
    std::cout << player3 << "\n";
	player3.afficherCartes();
	*/
	/*
    std::cout << "___________Demolir monument puis recevoir____________" << "\n";
	Effet* effetDemo = new EffetGreenValley(chaine, 2, false, false, false, 0, false, false,false,true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
	player1.afficherCartes();
    std::cout << player3 << "\n";
	player3.afficherCartes();
	effetDemo->runEffect(&player1);
	effetDemo->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
	player1.afficherCartes();
    std::cout << player3 << "\n";
	player3.afficherCartes();
	*/
	/*
    std::cout << "___________test pour chaque type de carte detenu par tous les joueurs recevoir pieces____________" << "\n";
	Effet* effetPour = new EffetGreenValley(chaine, 2, false, false, false, 0, false, false, false, false,true,false,false,false,false,false,false,false,false,false,false,Type::champ);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetPour->runEffect(&player1);
	effetPour->runEffect(&player3);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	*/
	/*
    std::cout << "___________voler avec plus de 2 monuments____________" << "\n";
	Effet* effetVoler = new EffetGreenValley(chaine, 2, false, true, false, 2);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";

    std::cout << player3 << "\n";
	effetVoler->runEffect(&player1, &player3);
	effetVoler->runEffect(&player3, &player1);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";



    std::cout << "___________voler tout plus de 3 monuments____________" << "\n";
	Effet* effetTout = new EffetGreenValley(chaine, 2, false, false, true, 3);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
	player1.afficherCartes();
    std::cout << player3 << "\n";
	effetTout->runEffect(&player1, &player3);
	effetTout->runEffect(&player3, &player1);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";


	Controleur::getControleur().getJeu()->afficherPlateau();

    std::cout << "___________activer autre batiment____________" << "\n";
	Effet* effetAutre = new EffetGreenValley(chaine, 0, false, false, false, 0,false,false,false,false,false,false,false,false,true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
	player1.afficherCartes();
    std::cout << player3 << "\n";
	effetAutre->runEffect(&player1, joueurs);
	effetAutre->runEffect(&player3, joueurs);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
	player1.afficherCartes();
    std::cout << player3 << "\n";
	Controleur::getControleur().getJeu()->afficherPlateau();


	player1.ajouterInvestissement(5);
    std::cout << "___________test de Investissemenbt____________" << "\n";
	Effet* effetInvest = new EffetGreenValley(chaine, 1, false,false,false,0,false,false,false,false,false,false,false,true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetInvest->runEffect(&player1, joueurs);
	effetInvest->runEffect(&player3, joueurs);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";

	player1.ajouterInvestissement(5);
    std::cout << "___________test de equilibrer____________" << "\n";
	Effet* effetEquilibre = new EffetGreenValley(chaine, 0, false, false, false, 0, false, false, false, false, false, true);
    std::cout << "___________Joueur avant effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	effetEquilibre->runEffect(&player1, joueurs);
	player1.changerMoney(5);
	effetEquilibre->runEffect(&player3, joueurs);
    std::cout << "___________Joueur apres effet____________" << "\n";
    std::cout << player1 << "\n";
    std::cout << player3 << "\n";
	*/


	/*
	//test des effets des cartes avec le jeu
	int cpt = 0;
	for (auto carte : cartes) {
        std::cout << "Carte " << cpt<< "\n";
        std::cout << *carte << "\n";
		cpt++;
	}

	JeuClassique::getJeu().changerMoneyJoueur(1, 100);
    std::vector<Joueur*> joueurs= JeuClassique::getJeu().getJoueursList();
	//+1 piece j1 a 3
	cartes[0]->runEffect(joueurs[0]);
    std::cout << JeuClassique::getJeu().getJoueur(0);
    std::cout << JeuClassique::getJeu().getJoueur(0).getPaquet();
    std::cout << JeuClassique::getJeu().getJoueur(1);
    std::cout << JeuClassique::getJeu().getJoueur(1).getPaquet();

	//echanger une carte donner deux champs a j1 donc deux boulangerie a j2
	cartes[7]->runEffect(joueurs[0],joueurs);
    std::cout << JeuClassique::getJeu().getJoueur(0);
    std::cout << JeuClassique::getJeu().getJoueur(0).getPaquet();
    std::cout << JeuClassique::getJeu().getJoueur(1);
    std::cout << JeuClassique::getJeu().getJoueur(1).getPaquet();

	//+2 pour chaque ferme piece j1 a 7
	cartes[14]->runEffect(joueurs[0]);
    std::cout << JeuClassique::getJeu().getJoueur(0);
    std::cout << JeuClassique::getJeu().getJoueur(1);

	//+1 vole donc j2 99 et j1 8
	cartes[3]->runEffect(joueurs[0], joueurs[1]);
    std::cout << JeuClassique::getJeu().getJoueur(0);
    std::cout << JeuClassique::getJeu().getJoueur(1);

	//+2 de chaque joueur donc j2 97 et j1 10
	cartes[6]->runEffect(joueurs[0],joueurs);
    std::cout << JeuClassique::getJeu().getJoueur(0);
    std::cout << JeuClassique::getJeu().getJoueur(1);

	//+5 vole en choisissant le joueur joueur donc j2 92 et j1 15
	cartes[8]->runEffect(joueurs[0],joueurs);
    std::cout << JeuClassique::getJeu().getJoueur(0);
    std::cout << JeuClassique::getJeu().getJoueur(1);

	*/

	//test de ajouterCarte de Plateau
	/*
    std::vector<Carte*> cartes = fonctions::cartesEditionClassique();
	int cpt = 0;
	for (auto carte : cartes) {
        std::cout << "Carte " << cpt << "\n";
        std::cout << *carte << "\n";
		cpt++;
	}
	Pioche pioche2(cartes, 4);
	try {
		Plateau plateau(cartes,pioche2);
        std::cout << "------------plateau initial------------ " << "\n";
		plateau.afficherPlateau();
        std::string str = "Antoine";
		Paquet paquettest;
		Joueur player(str, 0, paquettest, 0, 1);
		player.ajouterCarte(cartes[9]);
        std::string gare = "Gare";
		plateau.retirerCarte(gare);
		plateau.retirerCarte(gare);
		plateau.retirerCarte(gare);
		//plateau.retirerCarte(gare);
        std::cout << "------------plateau apres suppression de 3 gare------------ " << "\n";
		plateau.afficherPlateau();
		plateau.ajouterCarte(cartes[15]);
        std::cout << "------------plateau apres rajout de gare------------ " << "\n";
		plateau.afficherPlateau();
		plateau.retirerCarte(gare);
		plateau.retirerCarte(gare);
        std::cout << "------------plateau sans gare------------ " << "\n";
		plateau.afficherPlateau();
        std::cout << "------------plateau ajout d'une gare------------ " << "\n";
		plateau.ajouterCarte(cartes[15]);
		plateau.afficherPlateau();
        std::cout << "------------plateau ajout d'une autre carte------------ " << "\n";

        std::vector<int> v;
        std::string name = "Test";
		plateau.ajouterCarte(new Carte(new Effet("test"),Couleur::violet,1,v,name,Type::tour));
		plateau.afficherPlateau();
	}
	catch (PaquetException& e) {
        std::cout << e.getInfo() << "\n";
	}
	*/

	/*
	//test de l'implementation des etablissements ferme


    std::vector<int> v = {};
    std::string porto = "Port";
	Carte* port = new Carte(new Effet("C'est le port"), Couleur::monument, 0, v, porto, Type::tour);
    std::string chmp = "Champ de fleurs";
	Carte* ChampDeFleurs = new Carte(new Effet("C'est le champ de fleurs"), Couleur::bleu, 0, v, chmp, Type::champ);
	int cpt = 0;
	for (auto carte : cartes) {
        std::cout << "Carte " << cpt << "\n";
        std::cout << *carte << "\n";
		cpt++;
	}


	Paquet paquetAntoine;
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[2]);
	paquetAntoine.ajouterCarte(port);
	paquetAntoine.ajouterCarte(ChampDeFleurs);
	paquetAntoine.ajouterCarte(ChampDeFleurs);

	Joueur player1("Antoine", 0, paquetAntoine, 0, 1);
	player1.afficherCartes();
	player1.affichageTemp();

	player1.fermerOuvrirEtablissement(cartes[0], true);
	player1.fermerOuvrirEtablissement(porto, true);

	player1.afficherCartes();
	player1.affichageTemp();

    std::cout << "\n\n";
    std::cout << player1.isFermer(cartes[0]) << "\n";
    std::cout << player1.isFermer(chmp) << "\n";

	player1.retirerCarte(cartes[2]);
	player1.afficherCartes();
	player1.affichageTemp();
    std::cout << "\n\n";
    std::cout << player1.getInvestissement() << "\n";
	player1.ajouterInvestissement(2);
    std::cout << player1.getInvestissement() << "\n";

	*/
	/*
	//test de jeuClassique
	//srand((unsigned)time(NULL));
	JeuClassique::getJeu().afficherJeu();
    std::cout << JeuClassique::getJeu().getJoueur(0).getPaquet();
	JeuClassique::getJeu().changerMoneyJoueur(0, 2);
    std::cout << JeuClassique::getJeu().getJoueur(0);
    std::cout << JeuClassique::getJeu().lancerDe();
	JeuClassique::getJeu().afficherPlateau();
    std::vector<Carte*> cartes = JeuClassique::getJeu().getCartes();
    for (auto carte : cartes) std::cout << *carte << "\n";
	JeuClassique::libererJeu();
	*/



	/*
	for (auto type : Types)
        std::cout << type << "\n";
    std::cout << fonctions::choisirType();
	*/
	/*
	//test de jeuMarina
	//srand((unsignedMarinatime(NULL));
	JeuMarina::getJeu().afficherJeu();
    std::cout << JeuMarina::getJeu().getJoueur(0).getPaquet();
	JeuMarina::getJeu().changerMoneyJoueur(0, 2);
    std::cout << JeuMarina::getJeu().getJoueur(0);
    std::cout << JeuMarina::getJeu().lancerDe();
    std::vector<Carte*> cartes2 = JeuMarina::getJeu().getCartes();
    for (auto carte : cartes2) std::cout << *carte << "\n";
	JeuMarina::libererJeu();
	*/
	/*
	//test de jeuGreenValley
	//srand((unsigned)time(NULL));
	JeuGreenValley::getJeu().afficherJeu();
    std::cout << JeuGreenValley::getJeu().getJoueur(0).getPaquet();
	JeuGreenValley::getJeu().changerMoneyJoueur(0, 2);
    std::cout << JeuGreenValley::getJeu().getJoueur(0);
    //std::cout << JeuGreenValley::getJeu().lancerDe();
    std::cout << JeuGreenValley::getJeu().getPseudoJoueur(0);
	JeuGreenValley::getJeu().afficherPlateau();
    std::vector<Carte*> cartes3 = JeuGreenValley::getJeu().getCartes();
    for (auto carte : cartes3) std::cout << *carte << "\n";
	JeuGreenValley::libererJeu();
	*/
	/*
	JeuDeluxe::getJeu().afficherJeu();
    std::cout << JeuDeluxe::getJeu().getJoueur(0).getPaquet();
	JeuDeluxe::getJeu().changerMoneyJoueur(0, 2);
    std::cout << JeuDeluxe::getJeu().getJoueur(0);
    //std::cout << JeuGreenValley::getJeu().lancerDe();
    std::cout << JeuDeluxe::getJeu().getPseudoJoueur(0);
	JeuDeluxe::getJeu().afficherPlateau();
    std::vector<Carte*> cartes3 = JeuDeluxe::getJeu().getCartes();
	int i = 0;
    for (auto carte : cartes3) std::cout <<"Carte n" << i << "\n" << *carte << "\n";
	JeuDeluxe::libererJeu();
	*/


	/*
	for (auto n : cartes) {
		delete n;
	}
	*/
/*
	try {
		srand((unsigned)time(NULL));

		fonctions::screenInit();
		Controleur::getControleur().runPartie();
		fonctions::screenStop();
		return 0;
	}
	catch (PaquetException& e) {
        std::cout << e.getInfo() << "\n";
	}
    */
    //std::vector<Carte*> cartes = fonctions::cartesEditionClassique();
    QApplication app(argc, argv); //Création de l'app
    /*
    QWidget fenetre;
    fenetre.setFixedSize(1200, 600);
    fenetre.setWindowTitle("test");

    VueCarte* ok = new VueCarte(cartes[18],&fenetre);
    ok->move(10,10);
    fenetre.show();
    */


        VuePartie* partie= new VuePartie; //Création de la vue de la partie
        partie->show(); //On la montre



    return app.exec();
}




