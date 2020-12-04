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

Liste::Liste() 
{
	premiereEtape = NULL;
    derniereEtape = premiereEtape;
}

Liste::~Liste()
{
	//delete [] moyen;
	//cout<<"TrajetS détruit"<<endl;
} 

void Liste::Afficher() const
{
	const Etape *x = premiereEtape;
    if (x == NULL) {
        cout << "Desole. Il y a rien pour afficher.\n";
    } else {
        int i = 1;
        while (x->getEtapeSuivante() != NULL) {
            cout << i << " : ";
            x->Afficher();
            x = x->getEtapeSuivante();
            i++;
        }
        cout << i << " : ";
        x->Afficher();
    }
}

void Liste::AjouterTrajet(const Trajet *UnTrajet)
{
    if (premiereEtape == NULL) {
        premiereEtape = new Etape(UnTrajet);
        derniereEtape = premiereEtape;
    } else if (premiereEtape->getEtapeSuivante() == NULL) {
        derniereEtape = new Etape(UnTrajet);
        premiereEtape->setEtapeSuivant(derniereEtape);
        derniereEtape->setEtapePrecedent(premiereEtape);
    } else {
    //} else {
        Etape *x = new Etape(UnTrajet);
        derniereEtape->setEtapeSuivant(x);
        x->setEtapePrecedent(derniereEtape);
        derniereEtape = x;
    }
}

Etape *Liste::getPremiereEtape() const {
    return premiereEtape;
}
Etape *Liste::getDerniereEtape() const {
    return derniereEtape;
}


