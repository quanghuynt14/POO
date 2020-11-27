/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
//
//------------------------------------------------------------------------

class Ensemble 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Ensemble & operator = ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ensemble ( const Ensemble & unEnsemble );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ensemble ( unsigned int lo  = CARD_MAX );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Ensemble ( int t[], unsigned int nbElements );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher ( void );

    bool EstEgal(const Ensemble &unEnsemble) const;

    crduEstInclus EstInclus(const Ensemble &unEnsemble) const;

    crduAjouter Ajouter(int aAjouter);

    unsigned int Ajuster(int delta);

    bool Retirer(int element);

    unsigned int Retirer (const Ensemble &unEnsemble);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
void Sort();
//----------------------------------------------------- Attributs protégés
unsigned int cardMax;
unsigned int cardAct;
int *a;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

