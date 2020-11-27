/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------ Types
class ListeChainee;

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// TrajetCompose hérite publiquement de Trajet
// Un TrajetCompose décrit un trajet orienté entre deux villes, comportant
// éventuellement des étapes intermédiaires.
// Un TrajetCompose comporte en pratique une liste ordonnée de Trajets
// (trajets). Cette liste doit être non vide.
// Les trajets de la liste doivent se suivre : l'arrivée de l'un doit
// être le départ du suivant.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( bool nl = true ) const;
    // Mode d'emploi :
    // Affiche sur la sortie standard une description du trajet compose :
    // affiche la description de tous les sous-trajets de sa liste.
    // Le paramètre nl (nouvelle ligne) spécifie si l'affichage doit être
    // suivi d'un retour à la ligne. Il y a retour à la ligne si nl = true
    // Contrat :
    // La liste de trajets doit être non vide
    
    const char* GetDepart ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur une chaine de caractères représentant la
    // ville de départ, sans effectuer de copie en profondeur
    // La ville de départ est la ville de départ du premier sous-trajet
    // Contrat :
    // La liste de trajets doit être non vide
	
    const char* GetArrivee ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur une chaine de caractères représentant la
    // ville d'arrivée, sans effectuer de copie en profondeur
    // La ville d'arrivée est la ville d'arrivée du dernier sous-trajet
    // Contrat :
    // La liste de trajets doit être non vide
    
    Trajet* Clone ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur une copie en profondeur de ce trajet
    // Attention, il y a allocation dynamique de mémoire lors de la copie
    // Contrat :
    // Rien
    
    void Ajouter ( const Trajet* t );
    // Mode d'emploi :
    // Ajoute un sous-trajet à la suite de la liste de Trajets
    // Le paramètre t est un pointeur sur le trajet à ajouter, il est
    // copié en profondeur.
    // Contrat :
    // Rien

//------------------------------------------------- Surcharge d'opérateurs
    TrajetCompose& operator=(const TrajetCompose& unTrajetCompose);

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    // Recopie en profondeur de unTrajetCompose
    // Contrat :
    // Rien

    TrajetCompose ( );
    // Mode d'emploi :
    // Construit un TrajetCompose avec une liste de sous-trajets vide
    // Contrat :
    // Rien

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Libération de la mémoire allouée à la construction
    // Contrat :
    // Rien

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    ListeChainee* trajets;
};

#endif // TRAJET_COMPOSE_H

