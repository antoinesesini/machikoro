#include "vuecarte.h"
#include "Carte.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <vector>
#include <iostream>
#include "Effet.h"

#define x_scale 1
#define y_scale 1

VueCarte::VueCarte(Carte& c, QWidget *parent) : QPushButton(parent),carte(c)
{
    setBackgroundRole(QPalette::Base);
    //setAutoFillBackground(true);
    setFixedSize(120*x_scale,120*y_scale);
    //QPalette pal=this->palette();
    //pal.setColor(QPalette::Window, QColor(Qt::white));
    this->setAutoFillBackground(true);
    //this->setPalette(pal);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    //connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
    this->setToolTip(QString::fromUtf8(c.getEffet()->getDescription()));
}

void VueCarte::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    // rectangle autour de la carte

    pen.setColor(QColor(QString::fromUtf8(toQtColor(carte.getCouleur()))));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawRect(QRect(2, 2, width() - 2, height() - 2));

    pen.setColor(QColor("black"));
    painter.setPen(pen);
    std::string info= "";
    std::string activation="activation : ";
    std::vector<int> vecteur=carte.getActivation();
    for (auto nb : vecteur ){
        activation = activation + std::to_string(nb) +" ";
    }
    info = info + carte.getNom() + "\n" + activation+ "\n" + "Prix : " + std::to_string(carte.getPrix()) + "\n" + "Type : " +toString(carte.getType()) + "\n" ;
    //std::cout << info;
    painter.drawText(QRect(2, 2, width() - 2, height() - 2), Qt::AlignCenter, QString::fromUtf8(info.c_str()));
}

VueCarte::~VueCarte(){}


VuePetiteCarte::VuePetiteCarte(Carte& c, bool ferme, QWidget *parent) : QPushButton(parent),carte(c), ferme(ferme)
{
    setBackgroundRole(QPalette::Base);
    //setAutoFillBackground(true);
    this->setFixedHeight(60*y_scale);
    //QPalette pal=this->palette();
    //pal.setColor(QPalette::Window, QColor(Qt::white));
    this->setAutoFillBackground(true);
    //this->setPalette(pal);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    //connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
    this->setToolTip(QString::fromUtf8(c.getEffet()->getDescription()));
}

void VuePetiteCarte::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    // rectangle autour de la carte

    pen.setColor(QColor(QString::fromUtf8(toQtColor(carte.getCouleur()))));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawRect(QRect(2, 2, width() - 2, height() - 2));

    pen.setColor(QColor("black"));
    painter.setPen(pen);
    std::string info= "";
    std::string activation="activation : ";
    std::vector<int> vecteur=carte.getActivation();
    for (auto nb : vecteur ){
        activation = activation + std::to_string(nb) +" ";
    }
    info = info + carte.getNom() + "\n" + activation+ "\n";
    if (ferme)
        info =info + "Ferme\n";
    else
        info = info + "Ouvert \n";
    //std::cout << info;
    painter.drawText(QRect(2, 2, width() - 2, height() - 2), Qt::AlignCenter, QString::fromUtf8(info.c_str()));
}

VuePetiteCarte::~VuePetiteCarte(){}
