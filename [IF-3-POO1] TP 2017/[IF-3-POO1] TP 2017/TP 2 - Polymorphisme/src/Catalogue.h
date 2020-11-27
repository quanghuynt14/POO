/*************************************************************************
                           Catalogue  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeChainee.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// La classe Catalogue fait le lien entre l'utilisateur final et le modèle
// de données. Elle contient une liste de Trajets (trajets)
// Elle propose trois types de services à l'utilisateur :
// - Affichage du catalogue : Affiche tous les trajets enregistrés dans le
//   catalogue
// - Ajout de trajets : Permet à l'utilisateur de saisir de nouveaux
//   trajets avec ou sans escales (TrajetSimple ou TrajetCompose) à
//   ajouter au catalogue
// - Recherche de parcours : Permet à l'utilisateur de rechercher les
//   parcours (séquences ordonnées de trajets) correspondant à un voyage
//   d'une ville donnée à une autre ville donnée
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void InterfaceUtilisateur ( );
    // Mode d'emploi :
    // Menu qui permet à l'utilisateur d'accéder aux services du catalogue
    // Le menu se base sur l' entrée / sortie standard
    // Contrat :
    // Rien

//------------------------------------------------- Surcharge d'opérateurs
    Catalogue& operator=(const Catalogue& unCatalogue);

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi :
    // Construction d'un catalogue de trajets vide
    // Contrat :
    // Rien

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // Rien
    // Contrat :
    // Rien

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void afficher ( ) const;
    // Mode d'emploi :
    // Service qui affiche le contenu du catalogue sur la sortie standard
    // Contrat :
    // Rien
    
    void rechercheSimple ( ) const;
    // Mode d'emploi :
    // Service qui permet de rechercher les parcours entre deux villes,
    // constitués d'un seul trajet (simple ou composé)
    // Contrat :
    // L'utilisateur rentre des données correctes dans l'entrée standard :
    // les chaines entrées doivent faire moins de 64 caractères et ne pas
    // contenir d'espaces

    void rechercheAvancee ( ) const;
    // Mode d'emploi :
    // Service qui permet de rechercher les parcours entre deux villes,
    // en effectuant des combinaisons de tous les trajets possibles
    // Contrat :
    // L'utilisateur rentre des données correctes dans l'entrée standard :
    // les chaines entrées doivent faire moins de 64 caractères et ne pas
    // contenir d'espaces

    void explorerEnProfondeur ( const Trajet ** t,
                                const char * depart,
                                const char * arrivee,
                                unsigned int niveauMax,
                                bool& trouve,
                                unsigned int niveau = 0 ) const;
    // Mode d'emploi :
    // Affiche toutes les combinaisons de trajets du catalogue qui ont
    // pour départ une ville de nom depart et pour arrivée une ville de
    // nom arrivee
    // t représente l'état courant de l'exploration
    // niveau représente la profondeur d'exploration courante
    // A la fin, trouve est à true si au moins une combinaison a été
    // trouvée, et false sinon
    // Contrat :
    // t doit être un tableau de taille niveauMax, initialisé avec des
    // pointeurs nuls
    // depart et arrivee doivent pointer vers des chaines de caractères
    // valides

    void ajouterTrajetSimple ( );
    // Mode d'emploi :
    // Service qui permet d'ajouter au catalogue un TrajetSimple entre
    // deux villes
    // Contrat :
    // L'utilisateur rentre des données correctes dans l'entrée standard :
    // les chaines entrées doivent faire moins de 64 caractères et ne pas
    // contenir d'espaces

    void ajouterTrajetCompose ( );
    // Mode d'emploi :
    // Service qui permet d'ajouter au catalogue un TrajetCompose entre
    // deux villes, avec ou sans étapes
    // Contrat :
    // L'utilisateur rentre des données correctes dans l'entrée standard :
    // les chaines entrées doivent faire moins de 64 caractères et ne pas
    // contenir d'espaces

//----------------------------------------------------- Attributs protégés
    ListeChainee trajets;
};

#endif // CATALOGUE_H

