#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <vector>

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;
class VueCarte;
class VueParametre;
class VueParametreJoueur;
class VuePlateau;
class VueJoueurs;
class Joueur;
class QTextEdit;
class QScrollBar;
class Carte;

class VuePartie : public QWidget
{
    Q_OBJECT
public:
    explicit VuePartie(QWidget *parent = nullptr);
    ~VuePartie();
    void setResultatDe(int nb) {resultatDe=nb;}
    bool setSDoubleDe(bool d) {doubleDe=d;}
    QTextEdit* getHistorique(){return historique;}

private:
    QGridLayout* layout;
    QGridLayout* secondLayout;
    VueParametre* param;
    VueParametreJoueur* vpj;
    VuePlateau* plateau;
    VueJoueurs* joueurs;
    QComboBox* de;
    QLabel* nbDe;
    QPushButton* boutonInfo;
    QPushButton* bouton;
    QPushButton* boutonRelance;
    QPushButton* boutonAjout;
    Joueur* joueurActif;
    bool dejaAchete = false;
    QScrollBar* scrollBar;
    QTextEdit* historique;
    int resultatDe;
    bool doubleDe=false;
    void majPartie();
    void QTdebutTour(Joueur* currentJoueur);
    void QTsilenceLIAJoue(Joueur* currentJoueur);
    void QTbuyingManager(Joueur* currentJoueur, Carte* carte);
    void QTlancementDes(Joueur* currentJoueur);
    void QTinterpretation(Joueur* currentJoueur, int desResult);
    Joueur* QTprochainJoueur(Joueur* currentJoueur);
    int QTfinTour(Joueur* currentJoueur);
private slots:
    // slots qui gère les clics sur les cartes
    void boutonInfoClique();
    void boutonClique();
    void boutonRelanceClique();
    void boutonAjoutClique();
    void parametreClique(VueParametre* v);
    void parametreJoueurClique(VueParametreJoueur* v);
    void carteClique(VueCarte* vc);

};

#endif // VUEPARTIE_H
