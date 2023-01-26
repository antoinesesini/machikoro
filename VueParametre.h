#ifndef VUEPARAMETRE_H
#define VUEPARAMETRE_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QComboBox>
//#include "carte.h"
//#include "Controleur.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;
class VueCarte;
enum class Edition;

class VueParametre : public QWidget
{
    Q_OBJECT
public:
    explicit VueParametre(QWidget *parent = nullptr);
    Edition getEdition() const{return edition;}
    bool getSens() const {return sens;}
    int getNbJoueurs() const {return intNbJoueurs;}
    ~VueParametre();
private:
    //Controleur controleur; // controleur de la partie
    Edition edition;
    bool sens;
    int intNbJoueurs;
    QLabel* LabelEdition; // texte "Edition"
    QComboBox* choixEdition;
    QLabel* LabelSens; // texte "sens"
    QComboBox* choixSens;
    QLabel* nbJoueurs;
    QLineEdit* ChoixNb;
    QProgressBar* nbCartesPioche; // progression de la pioche
    QGridLayout* layout; // grille des cartes
    QPushButton* valide;


signals:
    void parametreClicked(VueParametre*);

private slots:
    // slots qui gère les clics sur les cartes
    void clickedEvent();

};

class VueParametreJoueur : public QWidget
{
    Q_OBJECT
public:
    explicit VueParametreJoueur(Edition edition, bool sens, int nbJoueur, QWidget *parent = nullptr);
    Edition getEdition() const{return edition;}
    bool getSens() const {return sens;}
    int getNbJoueurs() const {return nbJoueurs;}
    std::vector<std::string> getNomsJoueurs()const { return nomsJoueurs;}
    std::vector<bool> getIA() const { return IAJoueurs;}
    ~VueParametreJoueur();

private:
    Edition edition;
    bool sens;
    int nbJoueurs;
    std::vector<std::string> nomsJoueurs;
    std::vector<bool> IAJoueurs;
    QGridLayout* layout;
    std::vector<QLabel*> Joueurs;
    std::vector<QLabel*> labelNomsJoueurs;
    std::vector<QLineEdit*> choixNomsJoueurs;
    std::vector<QComboBox*> choixIA;
    std::vector<QLabel*> IA;
    QPushButton* valide;
signals:
    void parametreJoueurClicked(VueParametreJoueur*);

private slots:
    // slots qui gère les clics sur les cartes
    void clickedEvent();
};


#endif // VUEPARAMETRE_H
