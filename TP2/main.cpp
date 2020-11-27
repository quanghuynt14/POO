#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Etape.h"

int main(){
	const TrajetSimple *t = new TrajetSimple("Lyon", "Paris", "bateau");
	t->Afficher();
	
	Etape *v = new Etape(t);

	v->Afficher();
	cout << v->getEtapeSuivante() << endl;
	return 0;
}