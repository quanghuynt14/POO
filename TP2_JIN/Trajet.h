/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC
private:
    Depart,
    Arrivee,
    Transport moyen
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Enum Transport
    {
        Train = 0,
        Auto,
        Velo,
        Marche,
        Bateau,
        Avion
    } 

//------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ( const char* start, const char* goal, Transport means);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher( ) const;
//------------------------------------------------------------------ PRIVE



};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

