#include "VueJoueurs.h"
#include "Carte.h"
#include <QLabel>
#include <QString>
#include <vector>
#include <iostream>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "Effet.h"
#include "Joueur.h"
#include "Paquet.h"
#include "Carte.h"
#include "Controleur.h"
#include <QPainter>
#include <QScrollArea>
#include <QScrollBar>

#define x_scale 1
#define y_scale 1

VueJoueur::VueJoueur(Joueur* j, QWidget *parent) : QWidget (parent)
{
   layout=new QVBoxLayout();
   layout->setAlignment(layout,Qt::AlignTop);
   nom = new QLabel(QString::fromUtf8(j->getPseudo().c_str()));
   nom->setMinimumHeight(20);
   layout->addWidget(nom,0,Qt::AlignTop);
   argent = new QLabel("Argent : " + QString::number(j->getMoney()));
   argent->setMinimumHeight(20);
   layout->addWidget(argent,0,Qt::AlignTop);
   std::vector<Carte*> cartesJoueur= j->getPaquet().getContener();
   std::vector<bool> ferme=j->getToutFerme();
   int cpt=0;

   for (auto carte:cartesJoueur){
       cartes.push_back(new VuePetiteCarte(*carte, ferme[cpt]));
       cartes[cpt]->setMinimumHeight(60);
       layout->addWidget(cartes[cpt],0,Qt::AlignTop);
       cpt++;
   }
   //scroll = new QScrollArea;
   //scroll->setWidget(this);
   //scrollBar = new QScrollBar;
   //scroll->addScrollBarWidget(scrollBar,Qt::AlignRight);
   setMaximumWidth(140);
   setMinimumWidth(100);
   setMaximumHeight(600);
   setLayout(layout);
}

void VueJoueur::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    // rectangle autour de la carte

    pen.setColor(QColor("black"));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawRect(QRect(2, 2, width() - 2, height() - 2));
}

VueJoueur::~VueJoueur(){
    delete nom;
    delete argent;
    cartes.clear();

}

VueJoueurs::VueJoueurs(QWidget *parent) : QWidget(parent)
{
   //setWindowTitle("Minivilles !"); // modifier le titre de la fenêtre
   layout = new QHBoxLayout;

   //layout.setAlignment(Qt::AlignTop);
   std::vector<Joueur*> vectJoueurs=Controleur::getControleur().getJeu()->getJoueursList();
   int cpt=0;
   for (auto joueur : vectJoueurs){
        joueurs.push_back(new VueJoueur(joueur));
        layout->addWidget(joueurs[cpt]);
        cpt++;
   }
   setLayout(layout);
   //connect(param,SIGNAL(parametreClicked(VueParametre*)),this,SLOT(parametreClique(VueParametre*)));
}

VueJoueurs::~VueJoueurs(){
    joueurs.clear();
    delete layout;
}
