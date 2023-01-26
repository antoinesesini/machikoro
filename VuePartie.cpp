#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QTextEdit>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>
#include <QScrollBar>
#include <QThread>
#include <unistd.h>
//#include <unistd.h>
#include "Controleur.h"
#include "VueCarte.h"
#include "VuePartie.h"
#include "VueParametre.h"
#include "Plateau.h"
#include "VuePlateau.h"
#include "VueJoueurs.h"
#include "Carte.h"
#include <algorithm>
//#include "combinaison.h"


VuePartie::VuePartie(QWidget *parent) : QWidget(parent)
{
   setWindowTitle("Minivilles !"); // modifier le titre de la fenêtre
   layout = new QGridLayout; //Creation du layout principal
   param = new VueParametre(); //Création de la vue parametre
   layout->addWidget(param,0,0);
   setLayout(layout);
   connect(param,SIGNAL(parametreClicked(VueParametre*)),this,SLOT(parametreClique(VueParametre*)));
}

void VuePartie::parametreClique(VueParametre* v)
{
    vpj = new VueParametreJoueur(v->getEdition(), v->getSens(), v->getNbJoueurs());
    v->hide();
    layout->removeWidget(v);
    layout->addWidget(vpj,0,0);
    setLayout(layout);
    update();
    connect(vpj,SIGNAL(parametreJoueurClicked(VueParametreJoueur*)),this,SLOT(parametreJoueurClique(VueParametreJoueur*)));
}

void VuePartie::parametreJoueurClique(VueParametreJoueur* v){
    v->hide();
    layout->removeWidget(v);
    std::string parcDattraction="Parc d'attractions";
    Controleur::createInstance(v->getEdition(), v->getSens(), v->getNbJoueurs(), v->getNomsJoueurs(), v->getIA());
    joueurActif=&Controleur::getControleur().getJeu()->getJoueur(0);
    plateau = new VuePlateau(joueurActif);
    layout->addWidget(plateau,0,0,1,4);
    joueurs= new VueJoueurs;
    layout->addWidget(joueurs,0,4,2,1);
    boutonInfo=new QPushButton;
    boutonInfo->setText(QString::fromUtf8("Informations"));
    layout->addWidget(boutonInfo, 1,4,1,1,Qt::AlignTop);
    connect(boutonInfo,SIGNAL(clicked()),this,SLOT(boutonInfoClique()));
    historique=new QTextEdit();
    historique->toPlainText();
    historique->setMaximumWidth(200);
    historique->setReadOnly(true);
    scrollBar= new QScrollBar;
    historique->addScrollBarWidget(scrollBar,Qt::AlignRight);
    layout->addWidget(historique,0,5,2,1);
    secondLayout= new QGridLayout;
    layout->addLayout(secondLayout,1,0,1,4);
    //on fait ensuite jouer les IA consécutives
    while (joueurActif->getIa()){
        historique->append("C'est au tour de " + QString::fromUtf8(joueurActif->getPseudo()));
        QTdebutTour(joueurActif);
        QTsilenceLIAJoue(joueurActif);
        QTfinTour(joueurActif);
        if (!doubleDe || !joueurActif->getPaquet().is_In(parcDattraction))
            joueurActif=QTprochainJoueur(joueurActif);
        historique->append("*******************************");
    }
    historique->append("C'est au tour de " + QString::fromUtf8(joueurActif->getPseudo()));
    QTdebutTour(joueurActif);
    de=new QComboBox();
    for (int i=0;i<joueurActif->getDes();i++){
        de->addItem(QString::number(i+1));
    }
    secondLayout->addWidget(de,0,2);
    nbDe=new QLabel("Nombre de de : ");
    secondLayout->addWidget(nbDe,0,1,1,1,Qt::AlignRight);
    bouton = new QPushButton("Lancer de");
    secondLayout->addWidget(bouton,0,0);
    boutonRelance = new QPushButton("Relancez de");
    secondLayout->addWidget(boutonRelance,0,3);
    boutonRelance->hide();
    boutonAjout = new QPushButton("Ajouter 2 aux des");
    secondLayout->addWidget(boutonAjout,0,4);
    boutonAjout->hide();

    connect(boutonRelance,SIGNAL(clicked()),this,SLOT(boutonRelanceClique()));
    connect(boutonAjout,SIGNAL(clicked()),this,SLOT(boutonAjoutClique()));
    connect(bouton,SIGNAL(clicked()),this,SLOT(boutonClique()));
    setLayout(layout);
    update();
    this->showMaximized();
}

void VuePartie::majPartie(){
    plateau->hide();
    layout->removeWidget(plateau);
    layout->removeWidget(joueurs);
    joueurs->hide();
    delete joueurs;
    delete plateau;
    delete de;
    plateau= new VuePlateau(joueurActif);
    joueurs= new VueJoueurs;
    layout->addWidget(joueurs,0,4,2,1);
    layout->addWidget(plateau,0,0,1,4);
    connect(plateau,SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
    de=new QComboBox();
    for (int i=0;i<joueurActif->getDes();i++){
        de->addItem(QString::number(i+1));
    }
    secondLayout->addWidget(de,0,2);
    setLayout(layout);
    update();
}

void VuePartie::boutonClique(){
    if(bouton->text()=="Lancer de"){
        bouton->setText("Continuer");
        QTlancementDes(joueurActif);
        std::string tourRadio= "Tour radio";
        if (joueurActif->getPaquet().is_In(tourRadio))
            boutonRelance->show();
        std::string port= "Port";
        if (resultatDe>=10 && joueurActif->getPaquet().is_In(port))
            boutonAjout->show();
        return;
    }
    if(bouton->text()=="Continuer"){
        bouton->setText("Fin du tour");
        boutonRelance->hide();
        boutonAjout->hide();
        QTinterpretation(joueurActif, resultatDe);
        majPartie();
        return;
    }
    if(bouton->text()=="Fin du tour"){
        historique->append("*******************************");
        std::string parcDattraction="Parc d'attractions";
        if(QTfinTour(joueurActif)==-1)
            exit(0);
        //changement de joueur
        if (!doubleDe || !joueurActif->getPaquet().is_In(parcDattraction))
            joueurActif=QTprochainJoueur(joueurActif);
        //on fait ensuite jouer les IAs consécutives
        while (joueurActif->getIa()){
            dejaAchete=false;
            historique->append("C'est au tour de " + QString::fromUtf8(joueurActif->getPseudo()));
            QTdebutTour(joueurActif);
            QTsilenceLIAJoue(joueurActif);
            if(QTfinTour(joueurActif)==-1)
                exit(0);
            if (!doubleDe || !joueurActif->getPaquet().is_In(parcDattraction))
            {
                joueurActif=QTprochainJoueur(joueurActif);
            }
            historique->append("*******************************");
        }
        historique->append("C'est au tour de " + QString::fromUtf8(joueurActif->getPseudo()));
        QTdebutTour(joueurActif);
        bouton->setText("Lancer de");
        //mise a jour de l'application
        majPartie();
        doubleDe=false;
        dejaAchete=false;
        return;
    }
}

void VuePartie::QTsilenceLIAJoue(Joueur* currentJoueur) {
    /*LE JEU D'UNE IA SE DECOMPOSE COMME SUIT :
                - ELLE CHOISIT LE NOMBRE DE DES SEULE
                - ELLE LANCE LES DES
                - LES DES SONT INTERPRETÉS
                - ELLE ACHETE UNE CARTE AU HASARD PARMI LES CARTES DONT ELLE A LE BUDGET (ELLE ACHETE A CHAQUE TOUR)
                - ELLE ATTEND 1 SECONDE
                - ELLE TERMINE SON TOUR
    */
    //ELLE CHOISIT LE NOMBRE DE DES SEULE
    //Opération effectuée dans la fonction QTlancementDes
    //ELLE LANCE LES DES
    QTlancementDes(joueurActif); //On lance les dès


    //RELANCE PAS RELANCE ?



    //ELLE INTERPRETE LE RESULTAT
    QTinterpretation(joueurActif, resultatDe); //On interprete le résultat



    //On achete une carte au hasard parmis les cartes achetables
    //L'achat des IAs est fait en fonction du VuePlateau des autres joueurs et non du plateau réel, ainsi, il faut que l'achats de l'IA fasse les modifications seul
    std::vector<Carte*> selectionAchetable=fonctions::getCartesForBudget(currentJoueur); //On sort une séléction des cartes achetables
    unsigned int selectIntervalle= selectionAchetable.size();
    unsigned int selector= rand() % selectIntervalle; //On génère un nombre au hasard pour choisir la carte
    QTbuyingManager(currentJoueur, selectionAchetable[selector]);//On achete la carte
    //QThread::sleep(1);
    //RAJOUTER DES SLEEP POUR EVITER LES CRASHS POUR EXECUTION GOURMANDES TROP RAPIDES ?
}



void VuePartie::boutonRelanceClique(){
        historique->append(QString::fromUtf8(joueurActif->getPseudo())+" relance les des ");
        QTlancementDes(joueurActif);
        boutonRelance->hide();
}

void VuePartie::boutonAjoutClique(){
        historique->append(QString::fromUtf8(joueurActif->getPseudo())+" ajoute 2 a ses des ");
        resultatDe+=2;
        boutonAjout->hide();
}

void VuePartie::carteClique(VueCarte *vc){
    if (!dejaAchete){
        QTbuyingManager(joueurActif, &vc->getCarte());
        majPartie();
    }else{
        QMessageBox* message = new QMessageBox();
        message->setText("Vous avez deja achete un batiment");
        message->exec();
        delete message;
    }
}

//le current joueur tente d'acheter la carte
void VuePartie::QTbuyingManager(Joueur* currentJoueur, Carte* carte) {
    if (carte->getPrix()<=currentJoueur->getMoney() && !((carte->getCouleur()==Couleur::monument || carte->getCouleur()==Couleur::violet) && currentJoueur->getPaquet().is_In(carte)))
    {
            std::string carteSelected = carte->getNom();
            if (carteSelected == "Gare")
                currentJoueur->changerDes(2);
            if (carteSelected == "Banque de minivilles"){
                currentJoueur->changerMoney(currentJoueur->getMoney()+5);
                historique->append(QString::fromUtf8(currentJoueur->getPseudo() + " a gagne 5 pieces"));
            }
            //TRANSFERT
            Carte* carteTransfered = Controleur::getControleur().getJeu()->retirerCartePlateau(carteSelected);
            currentJoueur->ajouterCarte(carteTransfered);
            currentJoueur->changerMoney(currentJoueur->getMoney() - carteTransfered->getPrix());

            //RECAP TRANSFERT
            historique->append(QString::fromUtf8(currentJoueur->getPseudo() + " vient d'acheter " + carteSelected));
            dejaAchete=true;
    }
    else
    {
            QMessageBox* message = new QMessageBox();
            message->setText("Vous n'avez pas l'argent pour acheter cette carte ou vous n'êtes pas en mesure de l'acheter pour d'autres raisons !");
            message->exec();
            delete message;
    }
}

//Le currentJoueur lance les dés en mettant donc a jour la variable
void VuePartie::QTlancementDes(Joueur* currentJoueur) {
    unsigned int addition = 0;
    std::string carte2 = "Parc d'attractions";
    bool aParcAttractions = currentJoueur->getPaquet().is_In(carte2);
    std::vector<unsigned int> historique;
    std::vector<unsigned int>::iterator finder;
    unsigned int nbDesChoisis;
    if (currentJoueur->getIa())
    {
        //Dans le cas ou le joueur est une IA, on établie le nombre de dès à lancer au hasard
        nbDesChoisis=(rand() % currentJoueur->getDes()) + 1;
    }
    else
    {
        //Sinon on le récupère dans le QCombobox de manière classique
        nbDesChoisis=de->currentIndex()+1;
    }

    for (unsigned int i = 0; i < nbDesChoisis; i++) //On lance le nombre de des choisi
    {
        unsigned int result = Controleur::getControleur().getJeu()->lancerDe();
        finder = std::find(historique.begin(), historique.end(), result);
        if (finder != historique.end() && aParcAttractions)
            this->doubleDe = true;
        historique.push_back(result);
        addition += result;
        this->historique->append(QString::fromUtf8("Résultat du dés : ")+QString::number(result));
    }

    this->historique->append("Score obtenu : " +QString::number(addition));
    this->resultatDe=addition;
    if (this->doubleDe && aParcAttractions) {
        this->historique->append("Vous avez fait un double !");
    }

}

//active les cartes selon le resultat
void VuePartie::QTinterpretation(Joueur* currentJoueur, int desResult) { //interprete le resultat du de et active les cartes de la bonne maniere
    //pour les cartes rouges : faire le tour des joueurs dans le sens inverse de ordre et pour chaque joueur, on prendre ses cartes rouges activables et on les active
    //pour les cartes bleues : faire le tour des joueurs dans le sens ordre courant et pour chaque joueur, on recupere ses cartes bleues activables et on les active
    //pour les cartes vertes : le joueur courant subit une recherche de cartesActivables sur ses cartes de couleur verte et les cartes activables sont activees
    //pour les cartes violettes : le joueur courant subit une recherche de cartesActivables sur ses cartes de couleur violette et les cartes activables sont activees




    std::vector<Joueur*>::iterator it;
    std::vector<Joueur*> joueursList = Controleur::getControleur().getJeu()->getJoueursList();
    it = std::find(joueursList.begin(), joueursList.end(), currentJoueur);
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
            for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
            {
                //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
                if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
                    Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
                else
                    historique->append(QString::fromUtf8(j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)), currentJoueur)));
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
            for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
            {
                //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
                if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
                    Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
                else
                    historique->append(QString::fromUtf8(j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)), currentJoueur)));
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
            for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
            {
                //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
                if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
                    Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
                else
                    historique->append(QString::fromUtf8(j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)))));
            }
            i++;
            if (i > nbJoueurs - 1) i -= nbJoueurs;
        }
        //On run aussi pour notre joueur courant
        beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
        for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
        {
            //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
            if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
                Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
            else
                historique->append(QString::fromUtf8(j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)))));
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
            for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
            {
                //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
                if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
                    Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
                else
                    historique->append(QString::fromUtf8(j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)))));
            }
            i--;
            if (i < 0) i += nbJoueurs;
        }
        //On run aussi pour notre joueur courant
        beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
        for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
        {
            //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
            if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
                Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
            else
                historique->append(QString::fromUtf8(j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)))));
        }
    }

    //cartes vertes
    beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(place).getPaquet().getCarteCouleur(Couleur::vert);
    for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
    {
        //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
        if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
            Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
        else
            historique->append(QString::fromUtf8(j->runEffect(currentJoueur)));
    }


    //cartes violettes
    beforeFiltre = Controleur::getControleur().getJeu()->getJoueur(place).getPaquet().getCarteCouleur(Couleur::violet);
    for (auto j : fonctions::getCartesActivables(beforeFiltre, desResult))
    {
        //historique->append(QString::fromUtf8("Activation de " + j->getNom()));
        if (Controleur::getControleur().getJeu()->getJoueur(i).isFermer(j))
            Controleur::getControleur().getJeu()->getJoueur(i).fermerOuvrirEtablissement(j, false);
        else
            historique->append(QString::fromUtf8(j->runEffect(currentJoueur, Controleur::getControleur().getJeu()->getJoueursList())));
    }
}

//retourn le prochain joueur
Joueur* VuePartie::QTprochainJoueur(Joueur* currentJoueur){
    std::vector<Joueur*>::iterator it;
    std::vector<Joueur*> joueursList = Controleur::getControleur().getJeu()->getJoueursList();
    it = std::find(joueursList.begin(), joueursList.end(), currentJoueur);
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
    int i;

    //cartes rouges
    if (sens) //Si on est dans le sens horaire, on prend le joueur suivant
    {
        i = place + 1;
        if (i > nbJoueurs - 1) i -= nbJoueurs;

    }
    else //Sinon on prend le joueur d'avant
    {
        i = place - 1;
        if (i < 0) i += nbJoueurs;
    }
    return joueursList[i];
}

void VuePartie::QTdebutTour(Joueur* currentJoueur){
    std::string hdv="Hotel de Ville";
    if (currentJoueur->getMoney()==0 && currentJoueur->getPaquet().is_In(hdv)){
        currentJoueur->changerMoney(1);
        historique->append(QString::fromUtf8(currentJoueur->getPseudo())+ " a gagne 1 piece");
    }
}

int VuePartie::QTfinTour(Joueur* currentJoueur){
    std::string aer="Aeroport";
    if (!dejaAchete && currentJoueur->getPaquet().is_In(aer)){
        currentJoueur->changerMoney(currentJoueur->getMoney()+10);
        historique->append(QString::fromUtf8(currentJoueur->getPseudo())+ " a gagne 10 pieces");
    }
    if (currentJoueur->getPaquet().getCarteCouleur(Couleur::monument).size()==Controleur::getControleur().getJeu()->getNbMonuments()){
        QMessageBox* message = new QMessageBox();
        message->setText(QString::fromUtf8(currentJoueur->getPseudo())+ " a gagné la partie !");
        message->exec();
        Controleur::getControleur().getJeu()->retirerJoueur(currentJoueur);
        if(Controleur::getControleur().getJeu()->getJoueursList().size()<=1){
            QMessageBox* message = new QMessageBox();
            message->setText("Fin de la partie !");
            message->exec();
            this->hide();
            return -1;
        }
    }
    return 0;
}



void VuePartie::boutonInfoClique(){
    QMessageBox* message = new QMessageBox();
    message->setText("Minivilles ! made with <3 by :\n\nAntoine SESINI\nMatthieu PERETTE\nMathieu BOUSQUET\nHarry BROUDEHOUX");
    message->exec();
    delete message;
}



VuePartie::~VuePartie(){
    delete layout;
    delete secondLayout;
    delete param;
    delete vpj;
    delete plateau;
    delete joueurs;
    delete de;
    delete nbDe;
    delete bouton;
    delete boutonRelance;
    delete boutonAjout;
    delete scrollBar;
    delete historique;
}
