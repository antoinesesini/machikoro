#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>
#include "Controleur.h"
#include "VueCarte.h"
#include "VuePartie.h"
#include "VuePlateau.h"
#include "Plateau.h"
//#include "combinaison.h"


VuePlateau::VuePlateau(Joueur* currentJoueur, QWidget *parent) : QWidget(parent)
{

   //setWindowTitle("Minivilles !"); // modifier le titre de la fenêtre
   layout = new QGridLayout;
   std::vector<Paquet*> paquets=Controleur::getControleur().getJeu()->getAllPaquetsPlateau();
   int cpt=0;


   for (auto paquet : paquets){
       //si le paquet est vide on ne le montre pas
       //de plus si le paquet contient des cartes de type tour et que le joueur en a déjà une on ne le montre pas
       if (paquet->getContener().size()!=0){
           std::string currentName=paquet->getCarte(0).getNom();
           if (!( paquet->getCarte(0).getType()==Type::tour && currentJoueur->getPaquet().is_In(currentName))){
           vuecartes.push_back(new VueCarte(paquet->getCarte(0)));
           layout->addWidget(vuecartes[cpt],2*(cpt/5),cpt%5);
           nbcartes.push_back(new QLabel("disponible : " + QString::number(paquet->getNbCartes())));
           layout->addWidget(nbcartes[cpt],2*(cpt/5)+1,cpt%5);
           connect(vuecartes[cpt],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));
           cpt++;
        }
       }

   }
   setLayout(layout);
   //connect(param,SIGNAL(parametreClicked(VueParametre*)),this,SLOT(parametreClique(VueParametre*)));

}

void VuePlateau::carteClique(VueCarte* vc){
    emit carteClicked(vc);
}


