/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Ensemble &Ensemble::operator=(const Ensemble &unEnsemble)
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble(const Ensemble &unEnsemble)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble (constructeur de copie)

Ensemble::Ensemble(unsigned int lo)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
    cardMax = lo;
    cardAct = 0;
    a = new int[cardMax];
} //----- Fin de Ensemble

Ensemble::Ensemble(int t[], unsigned int nbElements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
    cardMax = nbElements;
    cardAct = 0;
    a = new int[cardMax];
    for (unsigned int i = 0; i < nbElements; i++)
    {
        bool inclus = false;
        for (unsigned int j = 0; j < cardAct; j++)
        {
            if (a[j] == t[i])
            {
                inclus = true;
            }
        }
        if (!inclus)
        {
            a[cardAct] = t[i];
            cardAct++;
        }
    }
}

Ensemble::~Ensemble()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
    delete [] a;
} //----- Fin de ~Ensemble

void Ensemble::Afficher(void)
{
    Sort();
    cout << cardAct << "\r\n";
    cout << cardMax << "\r\n";
    cout << "{";
    for (unsigned int i = 0; i < cardAct; i++)
    {
        cout << a[i];
        if (i != cardAct - 1)
        {
            cout << ",";
        }
    }
    cout << "}\r\n";
}

bool Ensemble::EstEgal(const Ensemble &unEnsemble) const
{
    if (cardAct != unEnsemble.cardAct)
    {
        return false;
    }
    for (unsigned int i = 0; i < cardAct; i++)
    {
        bool match = false;
        for (unsigned int j = 0; j < unEnsemble.cardAct; j++)
        {
            if (a[i] == unEnsemble.a[j])
            {
                match = true;
            }
        }
        if (match == false)
        {
            return false;
        }
    }
    return true;
}

crduEstInclus Ensemble::EstInclus(const Ensemble &unEnsemble) const
{
    if (EstEgal(unEnsemble))
    {
        return INCLUSION_LARGE;
    }
    for (unsigned int i = 0; i < cardAct; i++)
    {
        bool match = false;
        for (unsigned int j = 0; j < unEnsemble.cardAct; j++)
        {
            if (a[i] == unEnsemble.a[j])
            {
                match = true;
            }
        }
        if (match == false)
        {
            return NON_INCLUSION;
        }
    }
    return INCLUSION_STRICTE;
}

crduAjouter Ensemble::Ajouter(int aAjouter)
{
    for (unsigned int i = 0; i < cardAct; i++)
    {
        if (a[i] == aAjouter)
        {
            return DEJA_PRESENT;
        }
    }
    if (cardAct == cardMax)
    {
        return PLEIN;
    }
    a[cardAct] = aAjouter;
    cardAct++;
    return AJOUTE;
}

unsigned int Ensemble::Ajuster(int delta)
{
    if(cardMax+delta<=cardAct)
	{
		cardMax=cardAct;
	}
	else
	{
		cardMax+=delta;
	}
	int *tabCopie = new int[cardMax];
	for(unsigned int i=0 ; i<cardAct ; i++){
		tabCopie[i] = a[i];
	}
	delete [] a;
	a=tabCopie;
	return cardMax;
}

bool Ensemble::Retirer(int element)
{
    int h = -1;
    for (unsigned int i = 0; i < cardAct; i++)
    {
        if (a[i] == element)
        {
            h = i;
            break;
        }
    }
    if (h == -1)
    {
        
        return false;
    }

    int *tab = new int[cardMax - 1];
    for (int i = 0; i < h; i++)
    {
        tab[i] = a[i];
    }
    for (unsigned int i = h + 1; i < cardAct; i++)
    {
        tab[i] = a[i];
    }
    delete[] a;
    a = tab;
    cardMax--;
    cardAct--;
    return true;
}

unsigned int Ensemble::Retirer(const Ensemble &unEnsemble)
{
    unsigned int cpt = 0;
    unsigned int cardMaxConserver = cardMax;
    int cAc=unEnsemble.cardAct;
    int *tabCopie= new int[unEnsemble.cardAct];
    for( unsigned int i=0;i< unEnsemble.cardAct;i++)
    {
        tabCopie[i]=unEnsemble.a[i];
    }

    for( unsigned int i=0;i< cAc;i++)
    {
        if(Retirer(tabCopie[i]))
        {
            cpt++;
        }
    }
    Ajuster(cardMaxConserver-cardMax);
    Sort();
    delete [] tabCopie;
    return cpt;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Ensemble::Sort()
{
    if (cardAct <= 1)
    {
        return;
    }
    for (unsigned int i = 0; i < cardAct - 1; i++)
    {
        for (unsigned int j = i + 1; j < cardAct; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

