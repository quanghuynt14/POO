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
    delete trajets;
} 

void Catalogue::Afficher() const
{
    trajets->Afficher();
}
 
char *getString () {
	char w = getc(stdin);
	char *s = new char[100];
	int i = 0;

	if (w != '\n') {
		s[i] = w;
		i++;
	}
	while ((w = getc(stdin)) != '\n') {
		s[i] = w;
		i++;
	}
	return s;
}

void Catalogue::AjouterTrajetSimple() 
{
    char *villeDepart;
	char *villeArrivee;
	char *transport;

	cout << "Ville de depart : ";
	villeDepart = getString();
    cout << "Ville d'arrivee : ";
	villeArrivee = getString();
	cout << "Moyen de transport : ";
	transport = getString();

    const TrajetSimple *trajet_simple = 
			  new TrajetSimple(villeDepart, villeArrivee, transport);

    trajets->AjouterTrajet(UnTrajetSimple);

    cout << "Ajout reussi dans le catalogue du trajet : ";
    trajets->Afficher(); 
	
}

void Catalogue::AjouterTrajetCompose(const TrajetCompose *UnTrajetCompose) 
{
    trajets->AjouterTrajet(UnTrajetCompose);
}

void Catalogue::RechercheSimple(const char *Start, const char *Goal) const     \
{                                                                              \
    int nombreParcours = 0;                                                    \
    const Etape *x = trajets->getPremiereEtape();                              \
    while (x != NULL) {                                                        \
                                                                               \
        if (strcmp(x->getTrajet()->getDepart(), Start) == 0 &&                 \
            strcmp(x->getTrajet()->getArrivee(), Goal) == 0) {                 \
                                                                               \
            nombreParcours++;                                                  \
            cout << "\n" << "Parcours " << nombreParcours << " : ";            \
            x->Afficher();                                                     \
                                                                               \
        }                                                                      \
        x = x->getEtapeSuivante();                                             \
    }                                                                          \
}                                                                              \

void Catalogue::RechercheAvancee(const char *Start, const char *Goal) const    \
{                                                                              \
    int nombreParcours = 0;                                                    \
    const Etape *x = trajets->getPremiereEtape();                              \
                                                                               \
    while (x != NULL) {                                                        \
                                                                               \
        if (strcmp(x->getTrajet()->getDepart(), Start) == 0) {                 \
                                                                               \
            bool *visited = new bool[trajets->getSize()];                      \
            for (int i = 0; i < trajets->getSize(); i++) visited[i] = 0;       \
            visited[trajets->getPosition(x)] = true;                           \
                                                                               \
            Liste *A = new Liste;                                              \
            A->AjouterTrajet(x->getTrajet());                                  \
                                                                               \
            BFS(x->getTrajet(), visited, Goal, A, nombreParcours);             \
                                                                               \
        }                                                                      \
        x = x->getEtapeSuivante();                                             \
    }                                                                          \
}                                                                              \

void Catalogue::BFS(const Trajet *x, bool *v, const char *Goal,                \
                    Liste *Chemin, int &nbParcours) const                      \
{                                                                              \
    if (strcmp(x->getArrivee(), Goal) == 0) {                                  \
        nbParcours++;                                                          \
        cout << "\n#Parcours " << nbParcours << " : ";                         \
        Chemin->Afficher();                                                    \
    } else {                                                                   \
        const Etape *y = trajets->getPremiereEtape();                          \
                                                                               \
        while (y != NULL) {                                                    \
                                                                               \
            if (strcmp(x->getArrivee(), y->getTrajet()->getDepart()) == 0 &&   \
                v[trajets->getPosition(y)] == false) {                         \
                                                                               \
                v[trajets->getPosition(y)] = true;                             \
                Chemin->AjouterTrajet(y->getTrajet());                         \
                                                                               \
                BFS(y->getTrajet(), v, Goal, Chemin, nbParcours);              \
                                                                               \
                v[trajets->getPosition(y)] = false;                            \
                Chemin->RetirerEtape(Chemin->getDerniereEtape());              \
                                                                               \
            }                                                                  \
                                                                               \
            y = y->getEtapeSuivante();                                         \
        }                                                                      \
    }                                                                          \
                                                                               \
}                                                                              \