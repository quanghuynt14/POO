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

TrajetSimple::TrajetSimple(const char *Start, const char *Goal, const char *Means) : Trajet(Start, Goal)
{
	moyen = new char[strlen(Means) + 1];
	strcpy(moyen, Means);
}

TrajetSimple::~TrajetSimple()
{
	delete [] moyen;
	//cout<<"TrajetS détruit"<<endl;
} 

void TrajetSimple::Afficher() const
{
	cout << "Trajet simple de " << getDepart() << " à " << getArrivee() << " en " << moyen << endl;
}

