/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) -----
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// TrajetSimple hérite publiquement de Trajet
// Un TrajetSimple décrit un trajet orienté entre deux villes, impliquant
// un moyen de transport, et ne comportant pas d'étape intermédiaire
// Un TrajetSimple comporte trois attributs sous forme de chaines de
// caractères : une ville de départ (villeD), une ville d'arrivée (villeA)
// et un moyen de transport (transport)
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( bool nl = true ) const;
    // Mode d'emploi :
    // Affiche sur la sortie standard une description du trajet simple :
    // ville de départ, ville d'arrivée et moyen de transport utilisé.
    // Le paramètre nl (nouvelle ligne) spécifie si l'affichage doit être
    // suivi d'un retour à la ligne. Il y a retour à la ligne si nl = true
    // Contrat :
    // Rien
    
    const char* GetDepart ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur la chaine de caractères représentant la
    // ville de départ, sans effectuer de copie en profondeur
    // Contrat :
    // Rien
	
    const char* GetArrivee ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur la chaine de caractères représentant la
    // ville d'arrivée, sans effectuer de copie en profondeur
    // Contrat :
    // Rien
    
    Trajet* Clone ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur une copie en profondeur de ce trajet
    // Attention, il y a allocation dynamique de mémoire lors de la copie
    // Contrat :
    // Rien

//------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple& operator=(const TrajetSimple& unTrajetSimple);

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    // Recopie en profondeur de unTrajetSimple
    // Contrat :
    // unTrajetSimple est un TrajetSimple correctement construit

    TrajetSimple ( const char* vD, const char * vA, const char* mT );
    // Mode d'emploi :
    // Recopie en profondeur les chaines de caractères dans les attributs
    // correspondants
    // vD est un pointeur sur une chaine représentant la ville de départ
    // vA est un pointeur sur une chaine représentant la ville d'arrivée
    // mT est un pointeur sur une chaine représentant le transport
    // Contrat :
    // Les chaines de caractère doivent être des chaines valides au sens
    // du C : elles se terminent par un caractère nul ('\0')

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    // Libère toute la mémoire allouée lors de la construction
    // Contrat :
    // Rien

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    char* villeD;
    char* villeA;
    char* transport;
};

#endif // TRAJET_SIMPLE_H

