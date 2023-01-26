#ifndef VUECARTE_H
#define VUECARTE_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QMessageBox>
#include "carte.h"

class VueCarte : public QPushButton
{
    Q_OBJECT
public:
    VueCarte(Carte& c, QWidget *parent = nullptr);
    Carte& getCarte() const { return carte; }
private:
    Carte& carte;
    QPen pen;
    QBrush brush;
    ~VueCarte();
protected:
    void paintEvent(QPaintEvent *event) override;
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueCarte*);
public slots:
private slots:
    void clickedEvent() {emit carteClicked(this); }

};


class VuePetiteCarte : public QPushButton
{
    Q_OBJECT
public:
    VuePetiteCarte(Carte& c, bool ferme, QWidget *parent = nullptr);
    Carte& getCarte() const { return carte; }
private:
    Carte& carte;
    bool ferme;
    QPen pen;
    QBrush brush;
    ~VuePetiteCarte();
protected:
    void paintEvent(QPaintEvent *event) override;
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void petiteCarteClicked(VuePetiteCarte*);
public slots:
private slots:
    void clickedEvent() {emit petiteCarteClicked(this); }

};

#endif // VUECARTE_H
