/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#include "Trajet.h"


Trajet::Trajet (const char *Start, const char *Goal)
{
	depart = new char[strlen(Start) + 1];
	strcpy(depart, Start);
	arrivee = new char[strlen(Goal) + 1];
	strcpy(arrivee, Goal);
}

Trajet::~Trajet()
{
	delete [] depart;
	delete [] arrivee;
	//cout << "Trajet détruit" << endl;
}

const char *Trajet::getDepart() const
{
	return depart;
}

const char *Trajet::getArrivee() const
{
	return arrivee;
}





