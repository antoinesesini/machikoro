#include "De.h"
//using namespace std;


//****************class De*******************//
unsigned int De::lancerDe() const {
	//random entre min et max
	int random = rand() % (getMax() - getMin() + 1) + getMin();
	return random;
}
//****************class De*******************//


//****************Fonctions supplementaires******************//
std::ostream& operator<<(std::ostream& f, const De& d) {
	f << "De allant de " << d.getMin() << " a " << d.getMax() << "\n";
	return f;
}
//****************Fonctions supplementaires******************//
