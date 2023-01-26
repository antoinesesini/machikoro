#include "Carte.h"
#include "Effet.h"
#include "Paquet.h"
#include "De.h"
#include "Pioche.h"
#include "Plateau.h"
#include "Joueur.h"
#include "fonctions.h"
#include <vector>
#include "EffetGreenValley.h"
//#include "unistd.h"
#include <unistd.h>>
#include <QMessageBox>
#include <QTextEdit>
#include "Controleur.h"
#include "VuePartie.h"

std::vector<Carte*> fonctions::cartesEditionClassique() {
    std::vector<int> v = {  };
    std::vector<int> v1 = { 1 };
    std::vector<int> v2 = { 2 };
    std::vector<int> v2_3 = { 2, 3 };
    std::vector<int> v3 = { 3 };
    std::vector<int> v4 = { 4 };
    std::vector<int> v5 = { 5 };
    std::vector<int> v6 = { 6 };
    std::vector<int> v7 = { 7 };
    std::vector<int> v8 = { 8 };
    std::vector<int> v9 = { 9 };
    std::vector<int> v9_10 = { 9, 10 };
    std::vector<int> v10 = { 10 };
    std::vector<int> v11_12 = { 11, 12 };

    std::vector<Carte*> vect;
    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 1, v1, "Champs de ble", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 1, v2, "Ferme", Type::ferme));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 3, v5, "Foret", Type::ressource));

    vect.push_back(new Carte(new Effet("Recevez 5 pieces de la banque", 5, true),
        Couleur::bleu, 6, v9, "Mine", Type::ressource));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::bleu, 3, v10, "Verger", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::vert, 1, v2_3, "Boulangerie", Type::magasin));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::vert, 2, v4, "Superette", Type::magasin));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque pour chaque etablissement de type ferme que vous possedez", 3, false, false, false, false, true, false, Type::ferme),
        Couleur::vert, 5, v7, "Fromagerie", Type::industrie));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque pour chaque etablissement de type ressource que vous possedez", 3, false, false, false, false, true, false, Type::ressource),
        Couleur::vert, 3, v8, "Fabrique de meubles", Type::industrie));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la banque pour chaque etablissement de type champ que vous possedez", 2, false, false, false, false, true, false, Type::champ),
        Couleur::vert, 2, v11_12, "Marche de fruits et legumes", Type::marche));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces du joueur qui a lance les des", 1, false, true),
        Couleur::rouge, 2, v3, "Cafe", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces du joueur qui a lance les des", 2, false, true),
        Couleur::rouge, 3, v9_10, "Restaurant", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la part de chaque autre joueur", 2, false, false, false, true),
        Couleur::violet, 6, v6, "Stade", Type::tour));
/*
    vect.push_back(new Carte(new Effet("Recevez 5 pieces du joueur de votre choix", 5, false, true, false, false, false, true),
        Couleur::violet, 7, v6, "Chaine de television", Type::tour));

    vect.push_back(new Carte(new Effet("Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type tour", 0, false, false, true),
        Couleur::violet, 8, v6, "Centre d'affaires", Type::tour));
*/
    vect.push_back(new Carte(new EffetClassique("Vous pouvez lancer deux des", 0, true),
        Couleur::monument, 4, v, "Gare", Type::tour));

    vect.push_back(new Carte(new Effet("Vos etablissements de type cafe et magasin rapportent une piece de plus"),
        Couleur::monument, 10, v, "Centre commercial", Type::tour));

    vect.push_back(new Carte(new Effet("Une fois par tour, vous pouvez choisir de relancer vos des"),
        Couleur::monument, 22, v, "Tour radio", Type::tour)); //a voir

    vect.push_back(new Carte(new Effet("Si votre jet de des est un double, rejouez un tour apres celui-ci"),
        Couleur::monument, 16, v, "Parc d'attractions", Type::tour));

    return vect;
}

std::vector<Carte*> fonctions::cartesEditionMarina() {
    std::vector<int> v = {  };
    std::vector<int> v1 = { 1 };
    std::vector<int> v4 = { 4 };
    std::vector<int> v6 = { 6 };
    std::vector<int> v7 = { 7 };
    std::vector<int> v8 = { 8 };
    std::vector<int> v8_9 = { 8, 9 };
    std::vector<int> v12_13 = { 12, 13 };
    std::vector<int> v12_13_14 = { 12, 13, 14 };

    std::vector<Carte*> vect;

    vect.push_back(new Carte(new Effet("Recevez 1 piece de la banque", 1, true),
        Couleur::bleu, 2, v4, "Champ de fleurs", Type::champ));

    vect.push_back(new Carte(new EffetMarina("Si vous avez le Port, recevez 3 pieces de la banque", 3, true),
        Couleur::bleu, 2, v8, "Petit bateau de peche", Type::bateau));
/*
    vect.push_back(new Carte(new EffetMarina("Le joueur dont c'est le tour lance 2 des.Si vous avez le Port, recevez de la banque autant de pieces que le total des 2 des", 0, true),
        Couleur::bleu, 5, v12_13_14, "Chalutier", Type::bateau));
*/
    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la banque pour chaque etablissement de type cafe que vous possedez", 2, false, false, false, false, true, false, Type::cafe),
        Couleur::vert, 2, v12_13, "Halle de marche", Type::industrie));

    vect.push_back(new Carte(new EffetMarina("Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez", 1, false, true),
        Couleur::vert, 1, v6, "Fleuriste", Type::magasin));

    vect.push_back(new Carte(new EffetMarina("Si vous avez le Port, recevez 3 pieces du joueur qui a fait le lancer de des", 0, false, false, true),
        Couleur::rouge, 4, v1, "Sushi bar", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 1 piece du joueur qui a fait le lancer de des", 0, false, true),
        Couleur::rouge, 1, v7, "Pizzeria", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 1 piece du joueur qui a fait le lancer de des", 0, false, true),
        Couleur::rouge, 1, v8, "Moonster burger", Type::cafe));

    vect.push_back(new Carte(new EffetMarina("Recevez 1 piece de chaque joueur pour chaque etablissement de type cafe et magasin qu'il possede.", 0, false, false, false, true),
        Couleur::violet, 5, v7, "Maison d'edition", Type::tour));

    vect.push_back(new Carte(new EffetMarina("Recevez la moitie (arrondie a l'inferieur) des pieces de chaque joueur qui en possede 10 ou plus", 0, false, false, false, false, true),
        Couleur::violet, 4, v8_9, "Centre des impots", Type::tour));

    vect.push_back(new Carte(new Effet("Avant de construire un etablissement ou un monument, si vous n'avez pas de pieces, recevez 1 piece de la banque", 1, true),
        Couleur::monument, 0, v, "Hotel de Ville", Type::tour));

    vect.push_back(new Carte(new Effet("Si le resultat de votre jet de des est de 10 ou plus, vous pouvez ajouter 2 au resultat"), Couleur::monument,
        2, v, "Port", Type::tour));//a voir

    vect.push_back(new Carte(new Effet("Si vous n'avez rien construit pendant votre tour, recevez 10 pieces de la banque", 10, true),
        Couleur::monument, 30, v, "Aeroport", Type::tour));

    return vect;
}

std::vector<Carte*> fonctions::cartesEditionGreenValley() {
    std::vector<int> v2 = { 2 };
    std::vector<int> v3_4 = { 3,4 };
    //std::vector<int> v4 = { 4 };
    std::vector<int> v5 = { 5 };
    std::vector<int> v5_6 = { 5,6 };
    std::vector<int> v7 = { 7 };
    //std::vector<int> v8 = { 8 };
    std::vector<int> v9 = { 9 };
    //std::vector<int> v9_10 = { 9,10 };
    //std::vector<int> v10 = { 10 };
    std::vector<int> v11 = { 11 };
    std::vector<int> v11_12_13 = { 11,12,13 };
    std::vector<int> v12_13_14 = { 12,13,14 };

    std::vector<Carte*> vect;
    vect.push_back(new Carte(new EffetGreenValley("Si vous avez moins de 2 monuments, recevez 1 piece de la banque", 1, true, false, false, 2),
        Couleur::bleu, 2, v3_4, "Champ de mais", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::bleu, 3, v7, "Vignoble", Type::champ));

    vect.push_back(new Carte(new EffetGreenValley("Si vous avez moins de 2 monuments, recevez 2 piece de la banque", 2, true, false, false, 2),
        Couleur::vert, 0, v2, "Epicerie", Type::magasin));
/*
    vect.push_back(new Carte(new EffetGreenValley("Vous devez donner une carte de type non-tour a un autre joueur et recevez 4 pieces de la banque", 4, false, false, false, 0, true),
        Couleur::vert, 2, v2, "Entreprise de demenagement", Type::entreprise));
*/
    vect.push_back(new Carte(new EffetGreenValley("Recevez 5 pieces a la construction. Quand cette carte est active, payez 2 pieces a la banque", 2, false, false, false, 0, false, true),
        Couleur::vert, 0, v5_6, "Banque de minivilles", Type::entreprise));

    vect.push_back(new Carte(new EffetGreenValley("Recevez 6 pieces pour chaque champ de raisin en votre possession, puis fermer cette etablissement", 6, false, false, false, 0, false, false, true),
        Couleur::vert, 3, v9, "Cave a vin", Type::industrie));
/*
    vect.push_back(new Carte(new EffetGreenValley("Si possible, vous devez demolir l'un de vos monuments (hors hotel de ville). Recevez alors 8 pieces de la banque", 8, false, false, false, 0, false, false, false, true),
        Couleur::vert, 2, v4, "Entreprise de travaux publics", Type::entreprise));
*/
    vect.push_back(new Carte(new EffetGreenValley("Recevez 1 pieces pour tous les etablissements de type cafe de tous les joueurs", 1, false, false, false, 0, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, Type::cafe),
        Couleur::vert, 5, v11, "Moonster soda", Type::industrie));
    //la traduction est bizarre

    vect.push_back(new Carte(new EffetGreenValley("Si le joueur ayant lancer les des a au moins 2 monuments (hors hotel de ville), recevez 5 pieces de sa part", 5, false, true, false, 2),
        Couleur::rouge, 3, v5, "Restaurant 5 etoiles", Type::cafe));

    vect.push_back(new Carte(new EffetGreenValley("Si le joueur qui a obtenu ce nombre a au moins 3 monuments construits (hors hotel de ville), recuperez toutes ses pieces.", 0, false, false, true, 3),
        Couleur::rouge, 4, v12_13_14, "Club prive", Type::cafe));

    vect.push_back(new Carte(new EffetGreenValley("Redistribuez les pieces equitablement entre tous les joueurs. S'il y a une quantite inegale de pieces, prenez des pieces a la banque pour combler la difference.", 0, false, false, false, 0, false, false, false, false, false, true),
        Couleur::violet, 3, v11_12_13, "Parc", Type::tour));
/*
    vect.push_back(new Carte(new EffetGreenValley("Choisissez un etablissement de type non-tour. Tous les batiments de ce type sont ferme pour renovation. Recevez une piece de chaque joueur pour chaque etablissement ferme", 1, false, false, false, 0, false, false, false, false, false, false, true),
        Couleur::violet, 4, v8, "Entreprise de renovation", Type::tour));

    vect.push_back(new Carte(new EffetGreenValley("A votre tour, vous pouvez placer une piece sur cette carte. Quand l'etablissement est active, recevez le total investit par tous les joueurs", 0, false, false, false, 0, false, false, false, false, false, false, false, true),
        Couleur::violet, 1, v10, "Tech Startup", Type::tour));

    vect.push_back(new Carte(new EffetGreenValley("Vous pouvez choisir d'activer un autre etablissement (bleu ou vert) qu vous possedez. Si vous le faites, renvoyez cette carte au marche", 0, false, false, false, 0, false, false, false, false, false, false, false, false, true),
        Couleur::violet, 7, v10, "Salle d'exposition internationale", Type::tour));
    */
    return vect;

}

int fonctions::recupPositionJoueur(Joueur* j1, std::vector<Joueur*> vectJoueur) {

    auto it = find(vectJoueur.begin(), vectJoueur.end(), j1);
    if (it != vectJoueur.end())
        return(it - vectJoueur.begin());
    else
        return -1;
}

int fonctions::recupPositionCarte(std::string& nom, std::vector <Carte*> cartes) {
    auto it = cartes.begin();
    while (it != cartes.end()) {
        if ((*it)->getNom() == nom) return it - cartes.begin();
        ++it;
    }
    return -1;
}

Joueur* fonctions::choisirJoueur(Joueur* j, std::vector<Joueur*> vectJoueur) {
    std::cout << "\n" << "Choisissez un joueur de" << " 1 a " << vectJoueur.size() - 1 << "\n";
    int choix;
    while (!(std::cin >> choix) || choix < 1 || choix >(vectJoueur.size() - 1)) {
        std::cout << "Erreur veuillez choisir de nouveau" << "\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    choix -= 1;
    int position = fonctions::recupPositionJoueur(j, vectJoueur);
    if (choix >= position)
        choix += 1;
    return vectJoueur.at(choix);
}

Carte* fonctions::choisirCarte(std::vector <Carte*> cartes) {
    bool terminer = false;
    int choix;
    std::cout << "Choisissez une carte de" << " 1 a " << cartes.size() << "\n";
    while (!(std::cin >> choix) || choix < 1 || choix > cartes.size()) {
        std::cout << "Erreur veuillez choisir de nouveau" << "\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    return cartes.at(choix - 1);
}

Type fonctions::choisirType() {
    int i = 1;
    int choix;
    std::cout << "Choisissez un type de 1 a " << Types.size() << "\n";
    while (!(std::cin >> choix) || choix < 1 || choix >Types.size()) {
        std::cout << "Erreur veuillez choisir de nouveau" << "\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    choix--;
    //auto it = find(Types.begin(), Types.end(), choix);
    return *(Types.begin() + choix);
}

Carte* fonctions::choisirMonumentSauf(Joueur* j, std::string& nom) {
    std::vector<Carte*> monuments = j->getPaquet().getCarteCouleur(Couleur::monument);
    std::cout << "\n" << "Choisissez un monument de" << " 1 a " << monuments.size() - 1 << "\n";
    int choix;
    while (!(std::cin >> choix) || choix < 1 || choix >(monuments.size() - 1)) {
        std::cout << "Erreur veuillez choisir de nouveau" << "\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    choix -= 1;

    int position = fonctions::recupPositionCarte(nom, monuments);
    if (position != -1 && choix >= position)
        choix += 1;
    return monuments.at(choix);
}

Carte* fonctions::choisirCarteVioletteSauf(Joueur* j, std::string& nom) {
    std::vector<Carte*> violettes = j->getPaquet().getCarteCouleur(Couleur::violet);
    std::cout << "\n" << "Choisissez une carte violette de" << " 1 a " << violettes.size() - 1 << "\n";
    int choix;
    while (!(std::cin >> choix) || choix < 1 || choix >(violettes.size() - 1)) {
        std::cout << "Erreur veuillez choisir de nouveau" << "\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    choix -= 1;

    int position = fonctions::recupPositionCarte(nom, violettes);
    if (position != -1 && choix >= position)
        choix += 1;
    return violettes.at(choix);
}

/*void print_machi_koro()
{
    std::cout << "\n\n\n\n";
    const char* machi_koro_pattern[] =
    {
            "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -",
            "|                                                                                                                   |",
            "|          #   #     #####     #####     #   #     #####               #   #     #####     #####     #####          |",
            "|          ## ##     #   #     #         #   #       #                 #  #      #   #     #   #     #   #          |",
            "|          # # #     #####     #         #####       #                 ####      #   #     ####      #   #          |",
            "|          #   #     #   #     #         #   #       #                 #  #      #   #     #  #      #   #          |",
            "|          #   #     #   #     #####     #   #     #####               #   #     #####     #   #     #####          |",
            "|                                                                                                                   |",
            "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
    };
    for (int i = 0; i < 9; i++)
        std::cout << machi_koro_pattern[i] << endl;
    std::cout << "\n          Made with 💙BY Antoine SESINI, Matthieu PERETTE, Harry BROUDEHOUX and Mathieu BOUSQUET";
    std::cout << "\n\n\n\n";
}*/


void print_machi_koro() {
    std::cout << "\n\n\n\n" << R"(
 MMMMMMMM               MMMMMMMM               AAA                   CCCCCCCCCCCCCHHHHHHHHH     HHHHHHHHHIIIIIIIIII
M:::::::M             M:::::::M              A:::A                 CCC::::::::::::CH:::::::H     H:::::::HI::::::::I
M::::::::M           M::::::::M             A:::::A              CC:::::::::::::::CH:::::::H     H:::::::HI::::::::I
M:::::::::M         M:::::::::M            A:::::::A            C:::::CCCCCCCC::::CHH::::::H     H::::::HHII::::::II
M::::::::::M       M::::::::::M           A:::::::::A          C:::::C       CCCCCC  H:::::H     H:::::H    I::::I
M:::::::::::M     M:::::::::::M          A:::::A:::::A        C:::::C                H:::::H     H:::::H    I::::I
M:::::::M::::M   M::::M:::::::M         A:::::A A:::::A       C:::::C                H::::::HHHHH::::::H    I::::I
M::::::M M::::M M::::M M::::::M        A:::::A   A:::::A      C:::::C                H:::::::::::::::::H    I::::I
M::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A     C:::::C                H:::::::::::::::::H    I::::I
M::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A    C:::::C                H::::::HHHHH::::::H    I::::I
M::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A   C:::::C                H:::::H     H:::::H    I::::I
M::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A   C:::::C       CCCCCC  H:::::H     H:::::H    I::::I
M::::::M               M::::::M   A:::::A             A:::::A   C:::::CCCCCCCC::::CHH::::::H     H::::::HHII::::::II
M::::::M               M::::::M  A:::::A               A:::::A   CC:::::::::::::::CH:::::::H     H:::::::HI::::::::I
M::::::M               M::::::M A:::::A                 A:::::A    CCC::::::::::::CH:::::::H     H:::::::HI::::::::I
MMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAA      CCCCCCCCCCCCCHHHHHHHHH     HHHHHHHHHIIIIIIIIII

                         KKKKKKKKK    KKKKKKK     OOOOOOOOO     RRRRRRRRRRRRRRRRR        OOOOOOOOO
                         K:::::::K    K:::::K   OO:::::::::OO   R::::::::::::::::R     OO:::::::::OO
                         K:::::::K    K:::::K OO:::::::::::::OO R::::::RRRRRR:::::R  OO:::::::::::::OO
                         K:::::::K   K::::::KO:::::::OOO:::::::ORR:::::R     R:::::RO:::::::OOO:::::::O
                         KK::::::K  K:::::KKKO::::::O   O::::::O  R::::R     R:::::RO::::::O   O::::::O
                           K:::::K K:::::K   O:::::O     O:::::O  R::::R     R:::::RO:::::O     O:::::O
                           K::::::K:::::K    O:::::O     O:::::O  R::::RRRRRR:::::R O:::::O     O:::::O
                           K:::::::::::K     O:::::O     O:::::O  R:::::::::::::RR  O:::::O     O:::::O
                           K:::::::::::K     O:::::O     O:::::O  R::::RRRRRR:::::R O:::::O     O:::::O
                           K::::::K:::::K    O:::::O     O:::::O  R::::R     R:::::RO:::::O     O:::::O
                           K:::::K K:::::K   O:::::O     O:::::O  R::::R     R:::::RO:::::O     O:::::O
                         KK::::::K  K:::::KKKO::::::O   O::::::O  R::::R     R:::::RO::::::O   O::::::O
                         K:::::::K   K::::::KO:::::::OOO:::::::ORR:::::R     R:::::RO:::::::OOO:::::::O
                         K:::::::K    K:::::K OO:::::::::::::OO R::::::R     R:::::R OO:::::::::::::OO
                         K:::::::K    K:::::K   OO:::::::::OO   R::::::R     R:::::R   OO:::::::::OO
                         KKKKKKKKK    KKKKKKK     OOOOOOOOO     RRRRRRRR     RRRRRRR     OOOOOOOOO
)" << '\n';
}

void fonctions::screenInit() {
    print_machi_koro();
}

void fonctions::screenStop() {
    print_machi_koro();
}



unsigned int fonctions::lancementDes(Joueur* currentJoueur, bool& doubleDes) {
    //Verifier si carte gare alors proposer 1 ou 2 des
    //Sinon proposer de lancer juste
    //Lancer le nombre de des choisi
    //Mettre un peu de suspense et d'attente
    //Additionner
    //Si le joueur a la carte tour radio alors afficher l'addition et proposer de relancer 1 fois
    //Sinon afficher l'addition simplement
    //retourner l'addition
    unsigned int addition = 0;
    if (!currentJoueur) throw ControleurException("La carte a retirer n'existe pas !");
    std::string carte;
    std::string carte2 = "Parc d'attractions";
    bool aParcAttractions = currentJoueur->getPaquet().is_In(carte2);
    std::string choix;
    int choix2 = 0;
    std::vector<unsigned int> historique;
    std::vector<unsigned int>::iterator finder;





    if (currentJoueur->getDes() == 1) //Si le joueur n'a pas la carte Gare
    {
        std::cout << "\n\n" << "Entrez L puis ENTREE pour lancer le des...\n";
        while (!(std::cin >> choix) || choix != "L") {
            std::cout << "Entrez L puis ENTREE pour lancer le des...\n";
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        addition = Controleur::getControleur().getJeu()->lancerDe();
    }
    else //Si le joueur a la carte gare (ou toute autre carte qui lui a permis d'augmenter son nombre de des), on lui propose de lancer 1 ou 2 ou getDes des
    {
        std::cout << "\n\n" << "Combien de des desirez vous lancer ? Vous en avez " << currentJoueur->getDes() << " :\n";
        while (!(std::cin >> choix2) || choix2<1 || choix2>currentJoueur->getDes()) {
            std::cout << "Erreur ! Votre choix doit etre compris entre 1 et " << currentJoueur->getDes() << "\n";
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        std::cout << "\n\n" << "Entrez L puis ENTREE pour lancer le(s) des...\n";
        while (!(std::cin >> choix) || choix != "L") {
            std::cout << "Entrez L puis ENTREE pour lancer le des...\n";
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        for (int i = 0; i != choix2; i++) //On lance le nombre de des choisi
        {
            unsigned int result = Controleur::getControleur().getJeu()->lancerDe();
            finder = find(historique.begin(), historique.end(), result);
            if (finder != historique.end() && aParcAttractions)
                doubleDes = true;
            historique.push_back(result);
            addition += result;
        }
    }
    std::cout << "SCORE OBTENU : " << addition << std::endl;
    std::cout << ((doubleDes && aParcAttractions) ? "Vous avez fait un double !\n" : "");
    carte = "Tour radio";
    std::string choix3;
    if (currentJoueur->getPaquet().is_In(carte)) //Si le joueur a la tour radio alors on lui propose de rejouer, sinon on arrete et on renvoie le score
    {
        std::cout << "\n\n" << "Voulez vous relancer le(s) des ? (Oui/Non)\n";
        while (!(std::cin >> choix3) || (choix3 != "Oui" && choix3 != "Non")) {
            std::cout << "Erreur ! Votre choix doit etre 'Oui' ou 'Non' !\n";
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        if (choix3 == "Oui")
        {
            addition = 0;
            std::cout << "\n\n" << "Entrez L puis ENTREE pour lancer le des...\n";
            while (!(std::cin >> choix) || choix != "L") {
                std::cout << "Entrez L puis ENTREE pour lancer le des...\n";
                std::cin.clear();
                std::cin.ignore(255, '\n');
            }
            if (currentJoueur->getDes() == 1)
            {
                addition = Controleur::getControleur().getJeu()->lancerDe();
            }
            else
            {
                for (int i = 0; i != choix2; i++) //On lance le nombre de des choisi
                {
                    unsigned int result = Controleur::getControleur().getJeu()->lancerDe();
                    finder = find(historique.begin(), historique.end(), result);
                    if (finder != historique.end() && aParcAttractions)
                        doubleDes = true;
                    historique.push_back(result);
                    addition += result;
                }
            }
            std::cout << "SCORE OBTENU : " << addition;
            std::cout << ((doubleDes && aParcAttractions) ? "Vous avez fait un double !\n" : "");
        }
    }
    return addition;
}




std::vector<Carte*> fonctions::getCartesActivables(std::vector<Carte*>& vecteur, int desResult) {
    //retourne toutes les cartes activables avec desResult
    std::vector<Carte*> result;
    std::vector<Carte*>::iterator it;
    for (it = vecteur.begin();it != vecteur.end();it++) //Pour chaque carte dans le vecteur donne, on regarde si la carte est activable avec desResult
    {
        if (it.operator*()->isActivable(desResult))
        {
            result.push_back(*it); //Si la carte est activable, on la push
        }
    }
    return result;
}





void fonctions::interpretation(Joueur* currentJoueur, unsigned int& desResult) { //interprete le resultat du de et active les cartes de la bonne maniere
    //pour les cartes rouges : faire le tour des joueurs dans le sens inverse de ordre et pour chaque joueur, on prendre ses cartes rouges activables et on les active
    //pour les cartes bleues : faire le tour des joueurs dans le sens ordre courant et pour chaque joueur, on recupere ses cartes bleues activables et on les active
    //pour les cartes vertes : le joueur courant subit une recherche de cartesActivables sur ses cartes de couleur verte et les cartes activables sont activees
    //pour les cartes violettes : le joueur courant subit une recherche de cartesActivables sur ses cartes de couleur violette et les cartes activables sont activees




    std::vector<Joueur*>::iterator it;
    std::vector<Joueur*> joueursList = Controleur::getControleur().getJeu()->getJoueursList();
    it = find(joueursList.begin(), joueursList.end(), currentJoueur);
    int place = -1;
    if (it == joueursList.end())
    {
        throw ControleurException("Joueur impossible a indexer !");
    }
    else //On recupere sa place relative
    {
        place = it - joueursList.begin();
    }
    int nbJoueurs = Controleur::getControleur().getJeu()->getNbJoueurs();
    bool sens = Controleur::getControleur().getSens();
    std::vector<Carte*> beforeFiltre;
    int i;





    //cartes rouges
    if (sens) //Si on est dans le sens horaire, on part dans le sens antihoraire a partir du joueur en cours
    {
        i = place - 1;
        if (i < 0) i += nbJoueurs;
        //On ne run que pour les autres joueurs et non le courant
        while (i != place)
        {
            //operations sur les cartes rouges du joueur i
            beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::rouge);
            for (auto j : getCartesActivables(beforeFiltre, desResult))
            {
                std::cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)), currentJoueur);
            }
            i--;
            if (i < 0) i += nbJoueurs;
        }
    }
    else //Sinon l'inverse
    {
        i = place + 1;
        if (i > nbJoueurs - 1) i -= nbJoueurs;
        //On ne run que pour les autres joueurs et non le courant
        while (i != place)
        {
            //operations sur les cartes rouges du joueur i
            beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::rouge);
            for (auto j : getCartesActivables(beforeFiltre, desResult))
            {
                std::cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)), currentJoueur);
            }
            i++;
            if (i > nbJoueurs - 1) i -= nbJoueurs;
        }
    }




    //cartes bleues
    if (sens)
    {
        i = place + 1;
        if (i > nbJoueurs - 1) i -= nbJoueurs;
        //On run pour tous les autres joueurs
        while (i != place)
        {
            //operations sur les cartes bleues du joueur i
            beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
            for (auto j : getCartesActivables(beforeFiltre, desResult))
            {
                std::cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
            }
            i++;
            if (i > nbJoueurs - 1) i -= nbJoueurs;
        }
        //On run aussi pour notre joueur courant
        beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
        for (auto j : getCartesActivables(beforeFiltre, desResult))
        {
            std::cout << j->getNom() << "\n";
            j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
        }
    }
    else
    {
        i = place - 1;
        if (i < 0) i += nbJoueurs;
        //On run pour tous les autres joueurs
        while (i != place)
        {
            //operations sur les cartes bleues du joueur i
            beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
            for (auto j : getCartesActivables(beforeFiltre, desResult))
            {
                std::cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
            }
            i--;
            if (i < 0) i += nbJoueurs;
        }
        //On run aussi pour notre joueur courant
        beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
        for (auto j : getCartesActivables(beforeFiltre, desResult))
        {
            std::cout << j->getNom() << "\n";
            j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
        }
    }





    //cartes vertes
    beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(place).getPaquet().getCarteCouleur(Couleur::vert);
    for (auto j : getCartesActivables(beforeFiltre, desResult))
    {
        std::cout << j->getNom() << "\n";
        j->runEffect(currentJoueur);
    }


    //cartes violettes
    beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(place).getPaquet().getCarteCouleur(Couleur::violet);
    for (auto j : getCartesActivables(beforeFiltre, desResult))
    {
        std::cout << j->getNom() << "\n";
        j->runEffect(currentJoueur, Controleur::getControleur().getJeu()->getJoueursList());
    }
}

std::vector<Carte*> fonctions::affichageCartesAchetables(Joueur* currentJoueur) {
    std::vector<Carte*> result;
    int cpt = 1;
    std::cout << "\n//********AFFICHAGE CARTES ACHETABLES********//\n";
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    unsigned int budget = currentJoueur->getMoney();
    for (auto p : Controleur::getControleur().getJeu()->getPaquetsNonVidesPlateau())
    {
        Carte* current = &(p->getCarte(0));
        std::string currentName = current->getNom();
        if (current->getPrix() <= budget && !((current->getCouleur() == Couleur::monument || current->getCouleur() == Couleur::violet) && (currentJoueur->getPaquet().is_In(currentName))))
        {
            result.push_back(current);
            std::cout << "| " << cpt << " | NOMBRE RESTANT : " << p->getNbCartes() << " | Nom : " << current->getNom() << " | Couleur : " << current->getCouleur() << " | ";
            std::cout << "Activation : ";
            if (current->getCouleur() != Couleur::monument)
            {
                for (auto i : current->getActivation())
                    std::cout << i << " ";
            }
            std::cout << "| Type : " << current->getType() << " | Prix : " << current->getPrix() << " |" << std::endl;
            cpt++;

        }
    }
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\n";


    return result;
}

int fonctions::transfert(Joueur* currentJoueur) {
    return 0;
}


void fonctions::buyingManager(Joueur* currentJoueur) {
    //Avec le budget du joueur, buyingManager gere les entrees sorties permettant l'achat des etablissements
    //Il se charge ensuite d'effectuer le transfert des cartes depuis le plateau vers le paquet du joueur (faire attention aux editions hasardeuses : des transferts dans l'autre sens sont possibles)
    //ATTENTION QUAND ON ACHETE GARE ON AUGMENTE SIMPLEMENT LE GETDES DU JOUEUR


    //Affichage des cartes achetables par le joueur et numerotation de celles ci
    //Entree de la carte a acheter
    //Transfert : attention, si le joueur achete une carte dont le nom est Gare alors on incremente le nombre de des du joueur
    //Affichage d'un recapitualif de l'achat


    //AFFICHAGE
    std::vector<Carte*> cartesAchetables = affichageCartesAchetables(currentJoueur);

    if (!cartesAchetables.empty())
    {
        //ENTREE DE LA CARTE A ACHETER
        std::cout << "\n\n" << "Veuillez entrer le numero de la carte que vous desirez acheter dans la liste ci dessus (POUR PASSER VOTRE TOUR ENTREZ 0) :\n";
        int choix;
        while (!(std::cin >> choix) || choix<0 || choix>cartesAchetables.size()) {
            std::cout << "Veuillez entrer une valeur entre 0 et " << cartesAchetables.size() << "!\n";
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        if (choix != 0)
        {
            std::string carteSelected = cartesAchetables[choix - 1]->getNom();
            if (carteSelected == "Gare")
                currentJoueur->changerDes(2);
            //TRANSFERT
            Carte* carteTransfered = Controleur::getControleur().getJeu()->retirerCartePlateau(carteSelected);
            currentJoueur->ajouterCarte(carteTransfered);
            currentJoueur->changerMoney(currentJoueur->getMoney() - carteTransfered->getPrix());

            //RECAP TRANSFERT
            std::cout << "RECAPITULATIF : " << currentJoueur->getPseudo() << " vient d'acheter " << carteSelected << std::endl;
        }
    }
    else
        std::cout << "\nLe joueur ne peut acheter aucune carte !\n";

}



std::vector<Carte*> fonctions::getCartesForBudget(Joueur* currentJoueur){
    unsigned int budget=currentJoueur->getMoney();
    std::vector<Carte*> result;
    if (budget>0)
    {
        for (auto p : Controleur::getControleur().getJeu()->getPaquetsNonVidesPlateau())
        {
            if (p->getCarte(0).getPrix()<=budget && !((p->getCarte(0).getCouleur()==Couleur::monument || p->getCarte(0).getCouleur()==Couleur::violet) && currentJoueur->getPaquet().is_In(&p->getCarte(0))))
                result.push_back(&p->getCarte(0));
        }
    }
    return result;
}
