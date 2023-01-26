#include "Pioche.h"


//****************class Pioche*******************//

Carte* Pioche::piocher() {
	unsigned int nb_cartes = getNbCartes();
	//random entre 0 et le nombre de carte - 1
	unsigned int random = rand() % (nb_cartes);
	Carte& c = getCarte(random);
	return retirerCarte(&c);

}

Pioche::Pioche(std::vector<Carte*> cartes, int nb_joueurs) {
	Paquet();
	for (auto c : cartes) {
		if (c->getCouleur() == Couleur::violet)
			for (size_t i = 0; i < nb_joueurs; i++)
				ajouterCarte(c);//cartes violettes il y en a une par joueur
		else if (c->getCouleur() != Couleur::monument)
			for (size_t i = 0; i < 6; i++)
				ajouterCarte(c);//autres cartes sauf les monuments il y en a 6 de chaque
	}
}

//****************class Pioche*******************//


//****************Fonctions supplementaires******************//

std::ostream& operator<<(std::ostream& f, const Pioche& p)
{
	f << "/**********Affichage Pioche**********/\n";
	int i = 1;
    std::vector<Carte*>cartes = p.getContener();
	for (auto c : cartes)
	{
		f << "Carte n." << i;
		f << *c << "\n";
		i++;
	}
	f << "/**********Pioche Affiche**********/\n";
	return f;
}

//****************Fonctions supplementaires******************//
