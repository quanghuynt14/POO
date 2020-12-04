/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

Catalogue::Catalogue() 
{
    trajets = new Liste;
}

Catalogue::~Catalogue()
{

} 

void Catalogue::Afficher() const
{
    trajets->Afficher();
}

void Catalogue::AjouterTrajetSimple(const TrajetSimple *UnTrajetSimple) 
{
    trajets->AjouterTrajet(UnTrajetSimple);
}

void Catalogue::AjouterTrajetCompose(const TrajetCompose *UnTrajetCompose) 
{
    trajets->AjouterTrajet(UnTrajetCompose);
}