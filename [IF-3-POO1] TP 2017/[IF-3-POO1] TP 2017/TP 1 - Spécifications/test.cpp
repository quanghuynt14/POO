#include "Ensemble.h"
#include <iostream>

using namespace std;

int main() {
	int tab[] = {1,2,3,4,5};
	Ensemble E(tab, 5);
	E.Ajuster(3);
	E.Ajouter(6);
	E.Ajouter(2);
	
	int ret[] = {2,3,1};
	Ensemble R(ret, 3);
	
	E.Afficher();
	R.Afficher();
	
	cout << "RETIRES=" << E.Retirer(R) << endl;
	E.Afficher();
	return 0;
}