/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : 11/18
    copyright            : (C) 2018 par Lelouard M, Tondereau A
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
void Ensemble::Afficher ( )
// Algorithme : 
{
	tri();	
	cout<<cardActuelle<<"\r\n";
	cout<<cardMax<<"\r\n";
	cout<<"{";
	for (unsigned int i = 0 ; i<cardActuelle ; i++)
	{
		cout<<elements[i];
		if (i!=cardActuelle-1)
		{
			cout<<",";
		}
	}

	cout<<"}\r\n";
} //----- Fin de Méthode

crduAjouter Ensemble::Ajouter (int aAjouter)
{
	if(ElemEstInclus(aAjouter))
	{
		return DEJA_PRESENT;
	}
	else if(cardActuelle==cardMax)
	{
		return PLEIN;
	}
	elements[cardActuelle]=aAjouter;
	cardActuelle++;
	tri();
	return AJOUTE;
}

bool Ensemble::ElemEstInclus(int element) const
{
	for(unsigned int i = 0; i<cardActuelle ; i++)
	{
		if(elements[i]==element)
		{
			return true;
		}
	}
	return false;
}

bool Ensemble::EstEgal(const Ensemble & unEnsemble) const
{
	return EstInclus(unEnsemble)==INCLUSION_LARGE;
}
crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const
{
	bool estInclus = true;
	for(unsigned int i = 0;i<cardActuelle;i++)
	{
		if(!unEnsemble.ElemEstInclus(elements[i]))
		{
			estInclus = false;
			break;
		}
	}
	if(estInclus){
		if(cardActuelle==unEnsemble.cardActuelle)
		{
			return INCLUSION_LARGE;
		}
		return INCLUSION_STRICTE;
	}
	return NON_INCLUSION;

}
unsigned int Ensemble::Ajuster(int delta)
{
	if(cardMax+delta<=cardActuelle)
	{
		cardMax=cardActuelle;
	}
	else
	{
		cardMax+=delta;
	}
	int *tabCopie = new int[cardMax];
	for(unsigned int i=0 ; i<cardActuelle ; i++){
		tabCopie[i] = elements[i];
	}
	delete [] elements;
	elements=tabCopie;
	return cardMax;
}

bool Ensemble::Retirer(int element)
{

    int rang=-1;
	for(unsigned int i = 0; i<cardActuelle ; i++)
	{
		if(elements[i]==element)
		{
			rang=i;
			break;
		}
	}
	if(rang==-1)
	{
	    Ajuster(cardActuelle-cardMax);
        return false;
	}
    elements[rang]=elements[cardActuelle-1];
	cardActuelle--;
	
    Ajuster(cardActuelle-cardMax);
    tri();
    return true;

}
unsigned int Ensemble::Retirer( const Ensemble & unEnsemble)
{
    unsigned int cpt = 0;
    unsigned int cardMaxConserver = cardMax;
    int cAc=unEnsemble.cardActuelle;
    int *tabCopie= new int[unEnsemble.cardActuelle];
    for( unsigned int i=0;i< unEnsemble.cardActuelle;i++)
    {
        tabCopie[i]=unEnsemble.elements[i];
    }

    for( unsigned int i=0;i< cAc;i++)
    {
        if(Retirer(tabCopie[i]))
        {
            cpt++;
        }
    }
    Ajuster(cardMaxConserver-cardMax);
    tri();
    delete [] tabCopie;
    return cpt;
}

int Ensemble::Reunir (const Ensemble & unEnsemble)
{
     int cpt = unEnsemble.cardActuelle;
     //compter combien vont être à ajouter
     for (int i = 0 ; i<unEnsemble.cardActuelle ; i++){
         if(ElemEstInclus(unEnsemble.elements[i]))
         {
             cpt--;
         }
     }
     //voir si on peut tout ajouter
     if(cardActuelle+cpt>cardMax)
     {
         Ajuster(cardActuelle+cpt-cardMax);
         cpt *=-1;
     }
     //reellement faire les ajouts
     for ( int i = 0 ; i<unEnsemble.cardActuelle ; i++){
         Ajouter(unEnsemble.elements[i]);
     }
     return cpt;
}
unsigned int Ensemble::Intersection (const Ensemble & unEnsemble)
 {
     int *inter;
     inter = new int[cardActuelle];
     int remp = 0;
     for( int i = 0; i<cardActuelle ; i++){
         if(unEnsemble.ElemEstInclus(elements[i]))
         {
             inter[remp] = elements[i];
             remp++;
         }
     }
     int aRenvoyer = cardActuelle -remp;
     delete []elements;
     elements = inter;
     cardActuelle = remp;
     Ajuster(-cardMax);
     return aRenvoyer;
 }


//------------------------------------------------- Surcharge d'opérateurs
//Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
//{
//} ----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Ensemble::Ensemble ( const Ensemble & unEnsemble )
// Algorithme :
//
//{
#ifdef MAP
  //  cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
//} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble (unsigned int cMax)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
	cardMax = cMax;
	cardActuelle = 0;
	elements = new int[cardMax];

} //----- Fin de Ensemble

Ensemble::Ensemble (int t [], unsigned int nbElements )
{
	cardMax = nbElements;
	cardActuelle = 0;
	elements = new int[cardMax];
	for(unsigned int i=0; i<nbElements ; i++)
	{
		Ajouter(t[i]);
	}	
}

Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
	delete [] elements;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Ensemble::tri()
{
	
	bool estTrie = false;
	int tmp = 0;
	while(!estTrie)
	{
		estTrie = true;
		for (unsigned int i = 0 ;cardActuelle!=0 && i<cardActuelle-1 ; i++)
		{
			if (elements[i]>elements[i+1])
			{
				tmp = elements[i];
				elements[i] = elements[i+1];
				elements[i+1] = tmp;
				estTrie = false;
			}

		}
	}
}
