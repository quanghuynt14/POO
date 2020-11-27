/*************************************************************************
                           Etape  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#include "Trajet.h"
#include "Etape.h"

Etape::Etape (const Trajet *Arrivant) 
{
	TrajetActuel = Arrivant;
    TrajetSuivant = NULL;
}

Etape::~Etape ( )
{
    //delete TrajetActuel;
} 

void Etape::Afficher () const
{
	TrajetActuel->Afficher();
    
}

const Etape *Etape::getEtapeSuivante() const
{
    return TrajetSuivant;
}


