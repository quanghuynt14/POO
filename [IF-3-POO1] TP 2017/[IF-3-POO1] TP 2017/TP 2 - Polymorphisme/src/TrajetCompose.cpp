/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "ListeChainee.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher ( bool nl ) const
// Algorithme :
// Affiche tous les sous-trajets séparés par un tiret
{
    for(unsigned int i=0; i<trajets->Longueur(); ++i)
    {
        if(i > 0)
        {
            cout << " - ";
        }
        trajets->Acceder(i)->Afficher(false);
    }
    if(nl)
    {
        cout << endl;
    }
} //----- Fin de Afficher

const char* TrajetCompose::GetDepart ( ) const
{
    return trajets->PremierTrajet()->GetDepart();
} //----- Fin de GetDepart

const char* TrajetCompose::GetArrivee ( ) const
{
    return trajets->DernierTrajet()->GetArrivee();
} //----- Fin de GetArrivee

Trajet* TrajetCompose::Clone ( ) const
// Algorithme :
// Allocation dynamique d'une copie du trajet en utilisant le constructeur
// de copie
{
    return new TrajetCompose(*this);
} // ----- Fin de Clone

void TrajetCompose::Ajouter ( const Trajet *t )
{
    trajets->AjouterElement(t);
} //----- Fin de Ajouter

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
// Recopie en profondeur de la liste de trajets
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
    trajets = new ListeChainee(*unTrajetCompose.trajets);
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    trajets = new ListeChainee;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete trajets;
} //----- Fin de ~TrajetCompose


