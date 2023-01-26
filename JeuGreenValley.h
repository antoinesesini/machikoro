//
// Created by Antoine Sesini on 08/12/2022.
//

#ifndef MINIVILLES_JEUGREENVALLEY_H
#define MINIVILLES_JEUGREENVALLEY_H
#include "JeuPioche.h"
#include "Carte.h"
#include "fonctions.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuGreenValley----------//
class JeuGreenValley : public JeuPioche {
private:
    //std::vector<Carte*> cartes;

    //Constructeur et Destructeur//



    JeuGreenValley(const JeuGreenValley& j) = delete;
    JeuGreenValley& operator=(const JeuGreenValley& j) = delete;
    //Constructeur et Destructeur//


    //Structure et definition d'un Handler permettant de faire un getJeu
    /*
    struct Handler {
        JeuGreenValley* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;


*/

public:
    JeuGreenValley(int nbJoueurs, std::vector<std::string> nomJoueurs, std::vector<bool> IA);
    ~JeuGreenValley();
    /*
    static JeuGreenValley& getJeu();
    static void libererJeu();
*/
    //Methodes agissant sur les cartes a l'echelle du jeu
    std::vector<Carte*> getCartes() const { return cartes; }

};
//------------Classe JeuGreenValley----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUGREENVALLEY_H
