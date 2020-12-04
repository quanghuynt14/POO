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
    size = 0;
}

Liste::~Liste()
{
	delete premiereEtape;
	delete derniereEtape;
} 

void Liste::Afficher() const
{
	const Etape *x = premiereEtape;
    if (x == NULL) {
        cout << "Desole. Il y a rien pour afficher.\n";
    } else {
        int i = 1;
        while (x != NULL) {
            cout << "\n" << i << " : ";
            x->Afficher();
            x = x->getEtapeSuivante();
            i++;
        }
    }
}

void Liste::AjouterTrajet(const Trajet *UnTrajet)
{
    if (premiereEtape == NULL) {
        premiereEtape = new Etape(UnTrajet);
        derniereEtape = premiereEtape;
        size = 1;
    } else if (premiereEtape->getEtapeSuivante() == NULL) {
        derniereEtape = new Etape(UnTrajet);
        premiereEtape->setEtapeSuivant(derniereEtape);
        derniereEtape->setEtapePrecedent(premiereEtape);
        size = 2;
    } else {
    //} else {
        Etape *x = new Etape(UnTrajet);
        derniereEtape->setEtapeSuivant(x);
        x->setEtapePrecedent(derniereEtape);
        derniereEtape = x;
        size++;
    }
}

Etape *Liste::getPremiereEtape() const {
    return premiereEtape;
}
Etape *Liste::getDerniereEtape() const {
    return derniereEtape;
}

int Liste::getSize() const {
    return size;
}

int Liste::getPosition(const Etape *UnEtape) const {
    int pos = 0;
    const Etape *x = premiereEtape;

    while (x != UnEtape) {
        pos++;
        if (x != NULL) {
            x = x->getEtapeSuivante();
        }
    }

    if (x == NULL) {
        return -1;
    } else {
        return pos;
    }
}

void Liste::RetirerEtape(const Etape *UneEtape) {
    if (UneEtape->getEtapePrecedent() != NULL) {
        UneEtape->getEtapePrecedent()->setEtapeSuivant(UneEtape->getEtapeSuivante());
    } else {
        premiereEtape = UneEtape->getEtapeSuivante();
    }

    if (UneEtape->getEtapeSuivante() != NULL) {
        UneEtape->getEtapeSuivante()->setEtapePrecedent(UneEtape->getEtapePrecedent());
    }
}


