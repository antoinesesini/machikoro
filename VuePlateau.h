#ifndef VUEPLATEAU_H
#define VUEPLATEAU_H
#include <QWidget>
#include <vector>
#include <QMessageBox>
#include "Joueur.h"

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


class VuePlateau : public QWidget
{
    Q_OBJECT
public:
    explicit VuePlateau(Joueur* currentJoueur, QWidget *parent = nullptr);
    ~VuePlateau() {vuecartes.clear();nbcartes.clear();}
    std::vector<VueCarte*> getVueCartes() const {return vuecartes;}
private:
    QGridLayout* layout;
    std::vector<VueCarte*> vuecartes;
    std::vector<QLabel*> nbcartes;
signals:
    void carteClicked(VueCarte*);
private slots:
    void carteClique(VueCarte* vc);
};

#endif // VUEPLATEAU_H
