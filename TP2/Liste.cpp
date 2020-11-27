/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Liste.h"
#include "Etape.h"

Liste::Liste(Etape *UnePremiereEtape) 
{
	premiereEtape = UnePremiereEtape;
}

Liste::~Liste()
{
	//delete [] moyen;
	//cout<<"TrajetS détruit"<<endl;
} 

void Liste::Afficher() const
{
	//cout << "Trajet de " << getDepart() << " à " << getArrivee() << " en " << moyen << endl;
}

void Liste::AjouterEtape(const Trajet *UnTrajet)
{
    Etape *etapeSuivante = new Etape(UnTrajet);

    if (premiereEtape == NULL) {
        premiereEtape = new Etape(UnTrajet);
    } else {
        Etape *temp = premiereEtape;
    }


}


