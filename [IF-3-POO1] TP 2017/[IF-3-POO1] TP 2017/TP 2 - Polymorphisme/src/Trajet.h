/*************************************************************************
                           Trajet  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Trajet> (fichier Trajet.h) -------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// La classe Trajet représente un trajet orienté entre deux villes,
// le départ et l'arrivée, comprenant ou pas des étapes intermédiaires.
// C'est une classe abstraite qui sert à manipuler dans une collection
// hétérogène ses classes filles (TrajetSimple et TrajetCompose), sans
// distinction de leur nature
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( bool nl = true ) const = 0;
    // Mode d'emploi :
    // Affiche sur la sortie standard une description du trajet.
    // Le paramètre nl (nouvelle ligne) spécifie si l'affichage doit être
    // suivi d'un retour à la ligne. Il y a retour à la ligne si nl = true
    // Contrat :
    // Cette méthode doit être redéfinie dans les classes filles de Trajet

    virtual const char* GetDepart ( ) const = 0;
    // Mode d'emploi :
    // Retourne un pointeur sur une chaine de caractères représentant la
    // ville de départ pour ce trajet
    // Contrat :
    // Cette méthode doit être redéfinie dans les classes filles de Trajet
    // Le trajet doit posséder une ville de départ

    virtual const char* GetArrivee ( ) const = 0;
    // Mode d'emploi :
    // Retourne un pointeur sur une chaine de caractères représentant la
    // ville d'arrivée pour ce trajet
    // Contrat :
    // Cette méthode doit être redéfinie dans les classes filles de Trajet
    // Le trajet doit posséder une ville d'arrivée

    virtual Trajet* Clone ( ) const = 0;
    // Mode d'emploi :
    // Retourne une copie (en profondeur) du trajet
    // Contrat :
    // Cette méthode doit être redéfinie dans les classes filles de Trajet

//------------------------------------------------- Surcharge d'opérateurs
    Trajet& operator=(const Trajet& unTrajet);

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( );
    // Mode d'emploi :
    // Constructeur appelé par les classes filles uniquement
    // Cette classe (abstraite) n'est pas instanciable
    // Contrat :
    // Rien

    virtual ~Trajet ( );
    // Mode d'emploi :
    // Rien
    // Contrat :
    // Rien

//------------------------------------------------------------------ PRIVE

protected:

};

#endif // TRAJET_H

