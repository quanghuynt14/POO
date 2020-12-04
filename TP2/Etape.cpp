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

Etape::Etape (const Trajet *UnTrajet) 
{
	TrajetActuel = UnTrajet;
    EtapePrecedent = NULL;
    EtapeSuivant = NULL;
}

Etape::~Etape ( )
{
    
} 

void Etape::Afficher () const
{
	TrajetActuel->Afficher();
    
}

const Trajet *Etape::getTrajet() const 
{
    return TrajetActuel;
}

const Etape *Etape::getEtapePrecedent() const
{
    return EtapePrecedent;
}

const Etape *Etape::getEtapeSuivante() const
{
    return EtapeSuivant;
}

void Etape::setEtapeSuivant(const Etape *UneEtape) 
{
    EtapeSuivant = UneEtape;
}

void Etape::setEtapePrecedent(const Etape *UneEtape) 
{
    EtapePrecedent = UneEtape;
}



