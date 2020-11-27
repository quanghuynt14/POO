/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char* TrajetSimple::GetDepart ( ) const
{
    return villeD;
} // ----- Fin de GetDepart

const char* TrajetSimple::GetArrivee ( ) const
{
    return villeA;
} // ----- Fin de GetArrivee

void TrajetSimple::Afficher ( bool nl ) const
{
    cout << "De " << villeD << " a " << villeA << " en " << transport;
    if(nl)
    {
        cout << endl;
    }
} // ----- Fin de Afficher

Trajet* TrajetSimple::Clone ( ) const
// Algorithme :
// Allocation dynamique d'une copie du trajet en utilisant le constructeur
// de copie
{
    return new TrajetSimple(*this);
} // ----- Fin de Clone

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
// Allocation en mémoire de chaque attribut du trajet avec la taille
// nécessaire pour réaliser une copie en profondeur des attributs de
// unTrajetSimple correspondants
// Puis copie en profondeur des attributs de unTrajetSimple
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
    villeD = new char[strlen(unTrajetSimple.villeD)+1];
    villeA = new char[strlen(unTrajetSimple.villeA)+1];
    transport = new char[strlen(unTrajetSimple.transport)+1];
    strcpy(villeD, unTrajetSimple.villeD);
    strcpy(villeA, unTrajetSimple.villeA);
    strcpy(transport, unTrajetSimple.transport);
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( const char* vD, const char* vA, const char* mT )
// Algorithme :
// Allocation en mémoire de chaque attribut du trajet avec la taille
// nécessaire pour réaliser une copie en profondeur des paramètres
// correspondants
// Puis copie en profondeur des paramètres dans les attributs
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    villeD = new char[strlen(vD)+1];
    villeA = new char[strlen(vA)+1];
    transport = new char[strlen(mT)+1];
    strcpy(villeD, vD);
    strcpy(villeA, vA);
    strcpy(transport, mT);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete[] villeD;
    delete[] villeA;
    delete[] transport;
} //----- Fin de ~TrajetSimple

