#ifndef VUEJOUEURS_H
#define VUEJOUEURS_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "carte.h"
#include "VueCarte.h"
#include <QPen>
#include <QBrush>

class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QScrollArea;
class QScrollBar;

class VueJoueur : public QWidget
{
    Q_OBJECT
public:
    VueJoueur(Joueur* j, QWidget *parent = nullptr);
private:

    QVBoxLayout* layout;
    QLabel* nom;
    QLabel* argent;
    std::vector<VuePetiteCarte*> cartes;
    QPen pen;
    QBrush brush;
    //QScrollArea* scroll;
    //QScrollBar* scrollBar;
    ~VueJoueur();
protected:
    void paintEvent(QPaintEvent *event) override;

};

class VueJoueurs : public QWidget
{
    Q_OBJECT
public:

    VueJoueurs(QWidget *parent = nullptr);
    ~VueJoueurs();
private:
    std::vector<VueJoueur*> joueurs;
    QHBoxLayout* layout;
};

#endif // VUEJOUEURS_H
