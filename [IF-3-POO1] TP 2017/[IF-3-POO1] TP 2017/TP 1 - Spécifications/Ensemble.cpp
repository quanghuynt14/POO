/*************************************************************************
                           Ensemble  -  Représentation d'un ensemble mathématique d'entiers
                             -------------------
    début                : 16/10/2017
    copyright            : (C) 2017 par aleconte, rdeclercq
    e-mail               : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Ensemble::Afficher ( )
// Algorithme :
// Tri des valeurs par ordre croissant
// Affichage des cardinalités
// Affichage de toutes les valeurs, sauf la dernière, séparées par une
// virgule
// Affichage de la dernière valeur de l'ensemble
{
	Tri();
	cout << cardinaliteActuelle << "\r\n" << cardinaliteMax << "\r\n{";
	for(unsigned int i=0; i+1<cardinaliteActuelle; ++i)
	{
		cout << valeurs[i] << ",";
	}
	if(cardinaliteActuelle > 0)
	{
		cout << valeurs[cardinaliteActuelle-1];
	}
	cout << "}\r\n";
} //----- Fin de Afficher

bool Ensemble::EstEgal(const Ensemble& unEnsemble) const
// Algorithme :
// Si deux ensembles ont des cardinalités actuelles différentes ils ne
// sont pas égaux.
// Sinon si au moins une valeur de unEnsemble n'appartient pas à
// l'ensemble appelant, alors les ensembles ne sont pas égaux.
// Sinon, les ensembles ont la même cardinalité actuelle et l'un des deux
// contient toutes les valeurs de l'autre, ils sont donc égaux
{
	if(cardinaliteActuelle != unEnsemble.cardinaliteActuelle)
	{
		return false;
	}
	for(unsigned int i=0; i<unEnsemble.cardinaliteActuelle; ++i)
	{
		if(!ElementExiste(unEnsemble.valeurs[i]))
		{
			return false;
		}
	}
	return true;
} //----- Fin de EstEgal

crduEstInclus Ensemble::EstInclus(const Ensemble& unEnsemble) const
// Algorithme :
// Si les ensembles sont égaux, il y a inclusion large
// Sinon si un élément de unEnsemble ne fait pas partie de cet ensemble,
// alors il n'y a pas inclusion
// Sinon les ensembles ne sont pas égaux mais tous les éléments de
// unEnsemble sont inclus dans cet ensemble donc il y a inclusion stricte
{
	if(EstEgal(unEnsemble))
	{
		return INCLUSION_LARGE;
	}
	for(unsigned int i=0; i<cardinaliteActuelle; ++i) {
		if(!unEnsemble.ElementExiste(valeurs[i]))
		{
			return NON_INCLUSION;
		}
	}
	return INCLUSION_STRICTE;
} //----- Fin de EstInclus

crduAjouter Ensemble::Ajouter(int aAjouter)
// Algorithme :
// Si l'élément existe déjà dans l'ensemble retourner DEJA_PRESENT
// Sinon si l'ensemble est plein retourner PLEIN
// Sinon ajouter l'élément à la fin du tableau de valeurs
{
	if(ElementExiste(aAjouter))
	{
		return DEJA_PRESENT;
	}
	else if(cardinaliteActuelle == cardinaliteMax)
	{
		return PLEIN;
	} 
	else
	{
		valeurs[cardinaliteActuelle++] = aAjouter;
		return AJOUTE;
	}
} //----- Fin de Ajouter

unsigned int Ensemble::Ajuster (int delta)
// Algorithme :
// Cas où delta = 0 : appel inutile, retourne la cardinalité maximale
// Si delta > 0, la méthode ajoute delta à la cardinalité maximale
// Si delta < 0, la méthode retranche si possible la valeur absolue
// de delta à la cardinalité maximale de l'ensemble. Sinon le
// réajustement se fait au plus juste donc
// cardinaliteMax = cardinaliteActuelle
// Allocation d'un nouveau tableau de longueur réajustée
// Copie des éléments de l'ensemble dans ce tableau
// Libération de l'ancien tableau
{
	if(delta == 0)
	{
		return cardinaliteMax;
	}
	else if(delta > 0) 
	{
		cardinaliteMax += delta;
	}
	else
	{
		if(cardinaliteMax >= (unsigned)(-delta) && cardinaliteMax + delta >= cardinaliteActuelle)
		{
			cardinaliteMax += delta;
		}
		else
		{
			cardinaliteMax = cardinaliteActuelle;
		}
	}
	
	int * ajustement = new int [cardinaliteMax];
	for(unsigned int i=0; i<cardinaliteActuelle; ++i)
	{
		ajustement[i] = valeurs[i];
	}
	delete [] valeurs;
	valeurs = ajustement;
	return cardinaliteMax;
} //----- Fin de Ajuster

bool Ensemble::Retirer (int element)
// Algorithme :
// Si element existe dans le tableau :
// - on le recherche
// - on le remplace par l'élément en fin de tableau (suppression)
// - on décrémente la cardinallité maximale
// Dans tous les cas on ajuste au plus près la cardinalité maximale
{
	if(ElementExiste(element))
	{
		for(unsigned int i=0; i<cardinaliteActuelle; ++i)
		{
			if(valeurs[i] == element)
			{
				valeurs[i] = valeurs[--cardinaliteActuelle];
				Ajuster(cardinaliteActuelle - cardinaliteMax);
				return true;
			}
		}
	}
	Ajuster(cardinaliteActuelle - cardinaliteMax);
	return false;
} //----- Fin de Retirer

unsigned int Ensemble::Retirer(const Ensemble& unEnsemble)
// Algorithme :
// On teste le cas spécial ou l'ensemble à retirer est lui-même
// Pour chaque élément de unEnsemble, on le retire suivant le même
// algorithme que la méthode Retirer(int) mais sans réajustement
{
	unsigned int nbRetraits = 0;
	if(EstEgal(unEnsemble))
	{
		nbRetraits = cardinaliteActuelle;
		cardinaliteActuelle = 0;
		return nbRetraits;
	}
	for(unsigned int i=0; i<unEnsemble.cardinaliteActuelle; ++i)
	{
		if(ElementExiste(unEnsemble.valeurs[i]))
		{
			for(unsigned int j=0; j<cardinaliteActuelle; ++j)
			{
				if(valeurs[j] == unEnsemble.valeurs[i])
				{
					valeurs[j] = valeurs[--cardinaliteActuelle];
					nbRetraits++;
				}
			}
		}
	}
	return nbRetraits;
} //----- Fin de Retirer

int Ensemble::Reunir(const Ensemble& unEnsemble)
// Algorithme :
// Si unEnsemble est inclus (au sens large ou strict) dans cet ensemble
// alors il n'y a rien à faire
// Pour chaque élément de unEnsemble, essayer de l'ajouter dans cet
// ensemble.
// Si l'ajout échoue car cet ensemble est plein, le réajuster avec assez
// de place pour contenir unEnsemble tout entiers, puis ajouter l'élément
// Si on a dû réajuster l'ensemble, l'ajuster de nouveau, mais cette fois
// au plus près de la cardinalité actuelle
{
	if(unEnsemble.EstInclus(*this) != NON_INCLUSION)
	{
		return 0;
	}
	int nbAjouts = 0;
	bool ajuste = false;
	for(unsigned int i=0; i<unEnsemble.cardinaliteActuelle; ++i)
	{
		switch(Ajouter(unEnsemble.valeurs[i]))
		{
			case AJOUTE:
				++nbAjouts;
				break;
			case PLEIN:
				Ajuster(unEnsemble.cardinaliteActuelle);
				Ajouter(unEnsemble.valeurs[i]);
				++nbAjouts;
				ajuste = true;
				break;
			case DEJA_PRESENT:
				break;
		}
	}
	if(ajuste)
	{
		Ajuster(cardinaliteActuelle - cardinaliteMax);
		nbAjouts = -nbAjouts;
	}
	return nbAjouts;
} //----- Fin de Reunir

unsigned int Ensemble::Intersection(const Ensemble& unEnsemble)
// Algorithme :
// Pour chaque élément du tableau de valeurs, s'il n'existe pas dans
// unEnsemble, le retirer.
// Ajuster la cardinalité maximale au plus juste
{
	unsigned int nbSuppressions = 0, index = 0;
	while(index < cardinaliteActuelle)
	{
		if(!unEnsemble.ElementExiste(valeurs[index]))
		{
			Retirer(valeurs[index]);
			++nbSuppressions;
		}
		else
		{
			++index;
		}
	}
	Ajuster(cardinaliteActuelle - cardinaliteMax);
	return nbSuppressions;
} //----- Fin de Intersection

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble (unsigned int cardMax)
	: cardinaliteMax(cardMax), cardinaliteActuelle(0)
// Algorithme :
// Allocation du tableau valeurs, de longueur cardMax
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>\r\n";
#endif
	valeurs = new int [cardMax];
} //----- Fin de Ensemble

Ensemble::Ensemble (int t[], unsigned int nbElements)
// Algorithme :
// Initialisation des cardinalités
// Allocation du tableau de valeurs
// Recopie dans le tableau de valeurs des éléments de t, en évitant les
// doublons
{
#ifdef MAP
    cout << "Appel au constructeur 2 de <Ensemble>\r\n";
#endif
	cardinaliteMax = nbElements;
	cardinaliteActuelle = 0;
	valeurs = new int[cardinaliteMax];
	for(int *it = t; it < t+nbElements; ++it)
	{
		if(!ElementExiste(*it))
		{
			valeurs[cardinaliteActuelle++] = *it;
		}
	}
} //----- Fin de Ensemble

Ensemble::~Ensemble ( )
// Algorithme :
// Si valeurs pointe sur un tableau, libérer ce tableau
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>\r\n";
#endif
	if(valeurs)
	{
		delete [] valeurs;
	}
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
bool Ensemble::ElementExiste (int element) const
// Algorithme :
// Parcours du tableau de tous les éléments de l'ensemble
// Si la valeur de element appartient au tableau, retourne true
// Si à la fin du parcours element n'a pas été trouvé, retourne false
{
	for(unsigned int i=0; i<cardinaliteActuelle; ++i)
	{
		if(valeurs[i] == element)
		{
			return true;
		}
	}
	return false;
} //----- Fin de ElementExiste

void Ensemble::Tri ()
// Algorithme :
// Il s'agit d'un algorithme de tri à bulles
// Les éléments de l'ensemble sont triés par ordre croissant
{
	bool estTrie = false;
	while(!estTrie)
	{
		estTrie = true;
		for(unsigned int i=0; i+1<cardinaliteActuelle; ++i)
		{
			if(valeurs[i] > valeurs[i+1])
			{
				int buffer = valeurs[i];
				valeurs[i] = valeurs[i+1];
				valeurs[i+1] = buffer;
				estTrie = false;
			}
		}
	}
} //----- Fin de Tri
