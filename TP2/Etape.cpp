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
#include "TrajetCompose.h"

Etape::Etape (const Trajet *UnTrajet) 
{
	TrajetActuel = UnTrajet;
    EtapePrecedent = NULL;
    EtapeSuivant = NULL;
}

Etape::Etape (const Etape *UneEtape) 
{
	TrajetActuel = UneEtape->getTrajet();
    EtapePrecedent = UneEtape->getEtapePrecedent();
    EtapeSuivant = UneEtape->getEtapeSuivante();
}

Etape::~Etape ( )
{
    delete EtapePrecedent;
    delete EtapeSuivant;
} 

void Etape::Afficher () const
{
    // const TrajetCompose* t = static_cast<TrajetCompose*>(TrajetActuel); 
    // if (t) {
    //     cout << "    ";
    // } 
	TrajetActuel->Afficher();
}

const Trajet *Etape::getTrajet() const 
{
    return TrajetActuel;
}

Etape *Etape::getEtapePrecedent() const
{
    return EtapePrecedent;
}

Etape *Etape::getEtapeSuivante() const
{
    return EtapeSuivant;
}

void Etape::setEtapeSuivant( Etape *UneEtape) 
{
    EtapeSuivant = UneEtape;
}

void Etape::setEtapePrecedent( Etape *UneEtape) 
{
    EtapePrecedent = UneEtape;
}



