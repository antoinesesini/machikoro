#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>

#include "vueCarte.h"
#include "VueParametre.h"
#include "Controleur.h"
//#include "combinaison.h"

VueParametre::VueParametre(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Minivilles !"); // modifier le titre de la fenêtre
    LabelEdition= new QLabel("Edition :");
    choixEdition=new QComboBox;
    LabelSens= new QLabel("Sens :");
    nbJoueurs= new QLabel("Nombre de Joueurs :");
    ChoixNb= new QLineEdit();
    choixSens=new QComboBox;
    valide = new QPushButton("Valider");

    choixSens->addItem("Horaire");
    choixSens->addItem("Anti-Horaire");

    for (auto e: Editions)
        choixEdition->addItem(QString::fromUtf8(toString(e)));


    layout=new QGridLayout;
    layout->columnMinimumWidth(20);

    layout->addWidget(LabelEdition,0,0);
    layout->addWidget(choixEdition,0,2);
    layout->addWidget(LabelSens,2,0);
    layout->addWidget(choixSens,2,2);
    layout->addWidget(nbJoueurs,4,0);
    layout->addWidget(ChoixNb,4,2);
    layout->addWidget(valide,6,2);
    setLayout(layout);
    //connect(valide, &QPushButton::released, this, &VueParametre::boutonClique);
    connect(valide,SIGNAL(clicked()),this,SLOT(clickedEvent()));
}

void VueParametre::clickedEvent(){
    if (ChoixNb->text().toInt()>6 or ChoixNb->text().toInt() < 2){
        QMessageBox* message = new QMessageBox();
        message->setText("Erreur le nombre de joueur doit être entre 2 et 6 compris");
        message->exec();
    }else{
        intNbJoueurs=ChoixNb->text().toInt();
        sens=choixSens->currentIndex()==0;
        edition=toEdition(choixEdition->currentText().toStdString());
        emit parametreClicked(this);
    }
}

VueParametreJoueur::VueParametreJoueur(Edition e, bool s, int n, QWidget *parent) : edition(e), sens(s), nbJoueurs(n), QWidget(parent) {

    layout=new QGridLayout;
    layout->columnMinimumWidth(40);

    for (int i=0;i<nbJoueurs;i++){
        Joueurs.push_back(new QLabel);
        labelNomsJoueurs.push_back(new QLabel("Nom :"));
        choixNomsJoueurs.push_back(new QLineEdit);
        IA.push_back(new QLabel("Est il une IA :"));
        choixIA.push_back(new QComboBox);
        Joueurs[i]->setText(QString("Joueur %1 :").arg(i+1));
        choixIA[i]->addItem("Non");
        choixIA[i]->addItem("Oui");
        layout->addWidget(Joueurs[i],8*i,0);
        layout->addWidget(choixNomsJoueurs[i],8*i+2,2);
        layout->addWidget(labelNomsJoueurs[i],8*i+2,0);

        layout->addWidget(IA[i],8*i+4,0);
        layout->addWidget(choixIA[i],8*i+4,2);
    }

    valide = new QPushButton("Valider");
    layout->addWidget(valide,nbJoueurs*8,2);
    setLayout(layout);

    connect(valide,SIGNAL(clicked()),this,SLOT(clickedEvent()));
}

void VueParametreJoueur::clickedEvent(){

    auto it=choixNomsJoueurs.begin();
    while((it != choixNomsJoueurs.end()) and (*it)->text() != "")
        it++;

    auto it2=choixIA.begin();
    while (it2!=choixIA.end() and (*it2)->currentIndex()!=0)
        it2++;

    QMessageBox* message = new QMessageBox();
    if (it != choixNomsJoueurs.end())
    {
        message->setText("Erreur vous devez remplir tous les noms des joueurs");
        message->exec();
    }
    else
    {
        if (it2==choixIA.end())
        {
            message->setText("Erreur ! Aumoins un joueur humain doit participer !");
            message->exec();
        }
        else
        {
            for (int i=0; i< choixNomsJoueurs.size();i++){
                nomsJoueurs.push_back(choixNomsJoueurs[i]->text().toStdString());
                IAJoueurs.push_back(choixIA[i]->currentText()=="Oui");
            }
            emit parametreJoueurClicked(this);
        }
    }
    delete message;
}

VueParametre::~VueParametre(){
    delete LabelEdition;
    delete choixEdition;
    delete LabelSens;
    delete nbJoueurs;
    delete ChoixNb;
    delete choixSens;
    delete valide;
}

VueParametreJoueur::~VueParametreJoueur(){
    delete layout;
    Joueurs.clear();
    labelNomsJoueurs.clear();
    choixNomsJoueurs.clear();
    IA.clear();
    choixIA.clear();
    delete valide;
}
