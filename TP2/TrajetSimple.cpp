/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#include "Trajet.h"
#include "TrajetSimple.h"

TrajetSimple::TrajetSimple(const char *Start, const char *Goal, 
                           const char *Means) : Trajet(Start, Goal)
{
	moyen = new char[strlen(Means) + 1];
	strcpy(moyen, Means);
}

TrajetSimple::~TrajetSimple()
{
	delete [] moyen;
} 

void TrajetSimple::Afficher() const
{
	cout << "Trajet de " << getDepart() << " a " << getArrivee() 
            << " en " << moyen << " " << endl;
}


