/*************************************************************************
                           ListeChainee  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----
#if ! defined ( LISTE_CHAINEE_H )
#define LISTE_CHAINEE_H

//------------------------------------------------------------------ Types
class Trajet;

// Cellule de la ListeChainee
struct Cellule {
    Trajet *trajet;        // Pointeur sur le Trajet associé à la Cellule
    Cellule *suivante;     // Chainage simple sur la cellule suivante
};

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// Une ListeChainee est une collection ordonnée de Trajets
// La ListeChainee contrôle l'allocation et la libération de mémoire
// dynamique de tous les Trajets qu'on lui rajoute, en réalisant une
// copie en profondeur de tous les trajets qu'on lui ajoute.
// Elle est constituée d'un chainage simple de Cellules qui possèdent
// un pointeur vers leur Trajet. Chaque Cellule est seule responsable du
// Trajet vers lequel elle possède un pointeur.
// Les Trajets peuvent être triés de deux manières différentes :
// - Par ordre d'ajout (Séquence ordonnée de Trajets)
//   pour respecter la sémantique d'un parcours composé de plusieurs
//   Trajets.
// - Par ordre alphabétique sur les noms de villes de départ, puis
//   d'arrivée, pour respecter la sémantique d'un catalogue.
// La ListeChainee permet d'ajouter un Trajet, et d'accéder à un Trajet :
// Accès au premier Trajet de la liste, au dernier Trajet, ou accès par
// indice.
// Attributs :
// - racine : la première cellule de la liste chainee
// - triInsertion : tri alphabétique si true, tri par ordre d'ajout sinon
// - longueur : nombre de Trajets dans la liste (nombre de cellules)
//------------------------------------------------------------------------

class ListeChainee
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterElement ( const Trajet* t );
    // Mode d'emploi :
    // Ajoute le Trajet pointé par t à la liste de trajets, en faisant une
    // copie en profondeur du trajet à ajouter
    // Contrat :
    // t pointe vers un Trajet valide
    
    const Trajet* PremierTrajet ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur vers le premier Trajet de la liste chainee,
    // sans faire de copie en profondeur. C'est le Trajet associé à la
    // Cellule racine
    // Contrat :
    // La liste n'est pas vide (racine pointe vers une Cellule valide)
    
    const Trajet* DernierTrajet ( ) const;
    // Mode d'emploi :
    // Retourne un pointeur vers le dernier Trajet de la liste chainee,
    // sans faire de copie en profondeur
    // Contrat :
    // La liste n'est pas vide (racine pointe vers une Cellule valide)
    
    const Trajet* Acceder ( unsigned int indice ) const;
    // Mode d'emploi :
    // Retourne un pointeur vers le Trajet à l'indice indice de la liste
    // chainee, sans faire de copie en profondeur
    // Retourne 0 si indice n'est pas un indice valide
    // Contrat :
    // indice est inférieur au nombre d'éléments de la liste
    
    unsigned int Longueur ( ) const;
    // Mode d'emploi :
    // Renvoie le nombre de Trajets que contient actuellement la liste
    // Renvoie 0 si la liste est vide
    // Contrat :
    // Rien

//------------------------------------------------- Surcharge d'opérateurs
    ListeChainee& operator=(const ListeChainee& uneListeChainee);

//-------------------------------------------- Constructeurs - destructeur
    ListeChainee ( const ListeChainee & uneListeChainee );
    // Mode d'emploi (constructeur de copie) :
    // Recopie en profondeur de uneListeChainee
    // Contrat :
    // Rien

    ListeChainee ( bool triAlpha = false );
    // Mode d'emploi :
    // Construction d'une ListeChainee ordonnée, vide
    // Le paramètre triAlpha spécifie si le tri doit se faire par ordre
    // alphabétique (si true) ou par ordre d'ajout (si false)
    // Contrat :
    // Rien

    virtual ~ListeChainee ( );
    // Mode d'emploi :
    // Libération de la mémoire allouée à l'ajout de chaque Trajet
    // Contrat :
    // Rien

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool compare ( const Trajet* t1, const Trajet* t2 ) const;
    // Mode d'emploi :
    // Compare les trajets pointés par t1 et t2 par ordre alphabétique sur
    // leurs noms de villes de départ, puis d'arrivée.
    // Contrat :
    // t1 et t2 pointent bien vers des Trajets valides

//----------------------------------------------------- Attributs protégés
    Cellule *racine;
    bool triInsertion;
    unsigned int longueur;
};

#endif // LISTE_CHAINEE_H

