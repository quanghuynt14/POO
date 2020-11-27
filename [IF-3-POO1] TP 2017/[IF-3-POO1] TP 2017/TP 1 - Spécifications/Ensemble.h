/*************************************************************************
                           Ensemble  -  Représentation d'un ensemble mathématique d'entiers
                             -------------------
    début                : 16/10/2017
    copyright            : (C) 2017 par aleconte, rdeclercq
    e-mail               : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const unsigned int CARD_MAX = 5;

//------------------------------------------------------------------ Types
enum crduEstInclus {NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE};
enum crduAjouter {DEJA_PRESENT, PLEIN, AJOUTE};


//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
// La classe Ensemble représente une collection d'entiers qui respecte
// la définition d'un ensemble au sens mathématique.
// Un Ensemble ne peut donc pas contenir de doublons.
// Il est possible d'ajouter et de retirer des éléments à un Ensemble,
// et d'effectuer les opérations ensemblistes usuelles sur ces Ensembles :
// comparaison (égalité), union, intersection, soustraction.
// La taille d'un Ensemble est fixée mais peut être réajustée sur demande.
// Les 3 caractéristiques principales d'un Ensemble sont :
// - sa cardinalité maximale : cardinaliteMax
// - sa cardinalité actuelle : cardinaliteActuelle
// - les entiers qu'il contient, sous forme d'un tableau : valeurs
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Afficher( );
	// Mode d'emploi :
    // Cette méthode affiche sur la sortie standard les éléments de
	// l'ensemble, par ordre croissant, en respectant la syntaxe :
	// cardinalité maximale
	// cardinalité actuelle
	// {entiers triés par ordre croissant, séparés par une virgule}
	// L'affichage est suivi d'un retour à la ligne
	//
    // Contrat :
    // Rien
    
    bool EstEgal(const Ensemble& unEnsemble) const;
    // Mode d'emploi :
    // Cette méthode compare l'ensemble qui invoque la méthode à
	// l'ensemble paramètre unEnsemble
	// C'est une comparaison d'égalité ensembliste au sens mathématique
	// Renvoie true si les ensembles sont égaux, false sinon
	//
    // Contrat :
    // Rien
    
    crduEstInclus EstInclus(const Ensemble& unEnsemble) const;
    // Mode d'emploi :
    // Cette méthode teste l'inclusion de l'ensemble paramètre unEnsemble
	// dans l'ensemble qui invoque la méthode. La méthode renvoie :
	// - INCLUSION_LARGE si les deux ensembles sont égaux
	// - INCLUSION_STRICTE si unEnsemble est inclus dans cet ensemble,
	//   mais pas égal cet l'ensemble
	// - NON_INCLUSION si au moins un élément d'unEnsemble n'appartient
	//   pas à cet ensemble
	//
    // Contrat :
    // Rien
    
    crduAjouter Ajouter(int aAjouter);
    // Mode d'emploi :
    // Ajoute l'entier aAjouter dans l'ensemble qui invoque la méthode.
	// L'entier est ajouté si et seulement si il n'existe pas déjà dans
	// cet ensemble, et que la cardinalité actuelle de cet ensemble est
	// strictement inférieure à sa cardinalité maximale.
	// La méthode renvoie :
	// - PLEIN si la cardinalité actuelle de l'ensemble est égale à sa
	//   cardinalité maximale, dans ce cas aAjouter n'a pas été ajouté
	// - DEJA_PRESENT si aAjouter est déjà présent dans l'ensemble. Dans
	//   ce cas il n'est pas ajouté une deuxième fois
	// - AJOUTE si l'ajout a réussi
	//
    // Contrat :
    // Pas besoin de tester si l'entier aAjouter est déjà présent dans
	// l'ensemble
    
    unsigned int Ajuster (int delta);
    // Mode d'emploi :
    // Ajuste la cardinalité maximale de l'ensemble, sans perte d'éléments
	// Le nombre d'éléments ajustés est égal à la valeur absolue de delta
	// Si delta > 0 l'ensemble est agrandi, si delta < 0 l'ensemble est
	// réduit, et si delta = 0 la cardinalité maximale reste inchangée.
	// La méthode retourne dans tous les cas la cardinalité maximale de
	// l'ensemble après le réajustement
	//
    // Contrat :
    // Rien, mais il est inutile d'appeler cette méthode avec delta = 0
    
    bool Retirer (int element);
    // Mode d'emploi :
    // Supprime de l'ensemble l'élément qui a la valeur element, s'il
	// existe. L'ensemble est automatiquement réajusté au plus juste,
	// c'est à dire que les cardinalités maximale et actuelle sont égales
	// après appel de la méthode, que le retrait ait été effectué ou pas.
	// Retourne true si element existait et qu'il a été supprimé, false
	// sinon
	//
    // Contrat :
    // Rien
    
    unsigned int Retirer(const Ensemble& unEnsemble);
    // Mode d'emploi :
    // Supprime de l'ensemble qui appelle la méthode tous les éléments de
	// unEnsemble, si possible. Aucun réajustement de cardinalité maximale
	// n'est effectué. Retourne le nombre d'éléments réellement retirés
	//
    // Contrat :
    // Rien
	
	int Reunir(const Ensemble& unEnsemble);
    // Mode d'emploi :
	// C'est une union ensembliste au sens mathématique.
    // Ajoute à l'ensemble qui appelle la méthode les éléments de
	// unEnsemble qui ne sont pas déjà présent dans cet ensemble.
	// La valeur de retour a comme valeur absolue le nombre d'éléments
	// effectivement ajoutés à cet ensemble. Cette valeur est positive
	// si cet ensemble n'a pas dû être réajusté pour contenir tous ces
	// ajouts, mais elle est négative si un réajustement a eu lieu.
	// Si un réajustement a lieu, il a lieu au plus juste
	//
    // Contrat :
    // Rien
	
	unsigned int Intersection(const Ensemble& unEnsemble);
    // Mode d'emploi :
    // C'est une intersection d'ensembles au sens mathématique.
	// Supprime de l'ensemble appelant la méthode tous les éléments qui
	// ne sont pas en commun avec l'ensemble unEnsemble.
	// L'ensemble appelant la méthode est ensuite réajusté au plus juste.
	// Retourne le nombre d'éléments supprimés
	//
    // Contrat :
    // Rien
    
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Ensemble (unsigned int cardMax = CARD_MAX);
    // Mode d'emploi :
    // Construit un ensemble vide de cardinalité maximale cardMax
	// La cardinalité actuelle est donc de 0
	//
    // Contrat :
    // cardMax est un entier positif ou nul
    
    Ensemble (int t[], unsigned int nbElements);
    // Mode d'emploi :
	// Construit un ensemble de cardinalité maximale nbElements
	// Cet ensemble est initialisé avec les nbElements premières valeurs
	// du tableau t, chaque valeur n'étant ajoutée qu'une seule fois dans
	// l'ensemble, si elle n'a pas déjà été ajoutée (pas de doublons)
    //
    // Contrat :
    // nbElements doit être positif ou nul, et inférieur à la longueur du
	// tableau t

    virtual ~Ensemble ( );
    // Mode d'emploi :
    // Le destructeur se charge de libérer les ressources mémoires
	// allouées dynamiquement pendant l'exécution
	//
    // Contrat :
    // Rien

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
bool ElementExiste(int element) const;
	// Mode d'emploi :
    // Indique si la valeur du paramètre element appartient à cet ensemble
	// Retourne true si element est dans cet ensemble, et false sinon
	//
    // Contrat :
    // Rien
    
void Tri( );
	// Mode d'emploi :
    // Trie les éléments du tableau qui représente cet ensemble par ordre
	// croissant
	//
    // Contrat :
    // Cette méthode est utilisée pour rendre plus lisible l'affichage
	// En effet, au sens mathématique un ensemble n'est pas ordonné

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
unsigned int cardinaliteMax;
unsigned int cardinaliteActuelle;
int *valeurs;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Ensemble>

#endif // ENSEMBLE_H

