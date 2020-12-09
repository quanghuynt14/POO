
/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#include "Trajet.h"
#include "TrajetCompose.h"
#include "Liste.h"

TrajetCompose::TrajetCompose(const Liste *UneListe) : 
        Trajet(UneListe->getPremiereEtape()->getTrajet()->getDepart(), 
               UneListe->getDerniereEtape()->getTrajet()->getArrivee())
{
	Etapes = new Liste;
    const Etape *x = UneListe->getPremiereEtape();
    while (x != NULL) {
        Etapes->AjouterTrajet(x->getTrajet());
        x = x->getEtapeSuivante();
    }
}

TrajetCompose::~TrajetCompose()
{
	delete Etapes;
} 

void TrajetCompose::Afficher() const
{
    cout << "Depart : " << Etapes->getPremiereEtape()->getTrajet()->getDepart() 
         << "       Arrivee : " << Etapes->getDerniereEtape()->getTrajet()->getArrivee() << endl;
	Etapes->Afficher();
}


