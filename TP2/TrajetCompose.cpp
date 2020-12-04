
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

TrajetCompose::TrajetCompose(const char *Start, const char *Goal, const Liste *UneListe) : Trajet(Start, Goal)
{
	Etapes = new Liste;
    const Etape *x = UneListe->getPremiereEtape();
    while (x->getEtapeSuivante() != NULL) {
        Etapes->AjouterTrajet(x->getTrajet());
        x = x->getEtapeSuivante();
    }
    Etapes->AjouterTrajet(x->getTrajet());
}

TrajetCompose::~TrajetCompose()
{
	//delete [] moyen;
	//cout<<"TrajetS détruit"<<endl;
} 

void TrajetCompose::Afficher() const
{
    cout << "Trajet compose include les etapes suivantes : \n";
    cout << "-----------------------------------------------\n";
	Etapes->Afficher();
    cout << "-------------FIN-DE-TRAJET-COMPOSE-------------\n";
    cout << "\n";
}


