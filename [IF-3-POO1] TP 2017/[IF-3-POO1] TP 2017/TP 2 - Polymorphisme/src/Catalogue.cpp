/*************************************************************************
                           Catalogue  -  description
                             -------------------
  début      : 20/11/2017
  copyright  : (C) 2017 par aleconte, rdeclercq
  e-mail     : alexis.le-conte@insa-lyon.fr, romain.de-clercq@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::InterfaceUtilisateur ( )
// Algorithme :
// Propose une liste de services à l'utilisateur tant que celui-ci ne
// quitte pas l'application
{
    char choix = '0';
    cout << "Bienvenue dans le Catalogue de Trajets !" << endl;
    do
    {
        cout << endl;
        cout << "==================== MENU ====================" << endl;
        cout << "Que souhaitez-vous faire a present ?" << endl;
        cout << "0 : Afficher les trajets disponibles" << endl;
        cout << "1 : Ajouter un nouveau trajet simple" << endl;
        cout << "2 : Ajouter un nouveau trajet compose" << endl;
        cout << "3 : Recherche simple de trajet" << endl;
        cout << "4 : Recherche avancee de trajet" << endl;
        cout << "5 : Quitter l'application" << endl;
        cin >> choix;
        cout << "==============================================" << endl;
        switch (choix)
        {
            case '0':
                afficher();
                break;
            case '1':
                ajouterTrajetSimple();
                break;
            case '2':
                ajouterTrajetCompose();
                break;
            case '3':
                rechercheSimple();
                break;
            case '4':
                rechercheAvancee();
                break;
            case '5':
                cout << "Au revoir..." << endl;
                break;
            default:
                cout << "Choix invalide. Attendu : 0-1-2-3-4-5" << endl;
        }
    } while (choix != '5');
} //----- Fin de InterfaceUtilisateur

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( ) : trajets(true)
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Catalogue::afficher ( ) const
{
    cout << "Le catalogue comporte actuellement " << trajets.Longueur();
    cout << " trajet" << (trajets.Longueur() > 1 ? "s." : ".") << endl;
    for(unsigned int i=0; i<trajets.Longueur(); ++i)
    {
        trajets.Acceder(i)->Afficher();
    }
} //----- Fin de afficher

void Catalogue::ajouterTrajetSimple ( )
{
    char villeD[64] = {};
    char villeA[64] = {};
    char transport[64] = {};
    cout << "Les entrees ne doivent pas comporter d'espaces !" << endl;
    cout << "Ville de depart : ";
    cin >> villeD;
    cout << "Ville d'arrivee : ";
    cin >> villeA;
    cout << "Moyen de transport : ";
    cin >> transport;
    TrajetSimple t(villeD, villeA, transport);
    trajets.AjouterElement(&t);
    cout << "Le trajet ";
    t.Afficher(false);
    cout << " a ete ajoute au catalogue." << endl;
} //----- Fin de ajouterTrajetSimple

void Catalogue::ajouterTrajetCompose ( )
// Algorithme :
// Entrées : ville de départ puis étapes et transports suivants
// Ajoute un premier TrajetSimple
// Puis continue à demander à l'utilisateur l'étape suivante
// jusqu'à ce qu'il valide le TrajetCompose en entrant "1"
{
    TrajetCompose tc;
    char villePrec[64] = {};
    char villeSuiv[64] = {};
    char transport[64] = {};
    cout << "Les entrees ne doivent pas comporter d'espaces !" << endl;
    cout << "Un trajet compose comporte au moins 2 villes" << endl;
    cout << "Entrez 1 pour valider la saisie du trajet" << endl;
    cout << "Ville de depart : ";
    cin >> villePrec;
    cout << "Etape suivante : ";
    cin >> villeSuiv;
    do
    {
        cout << "Moyen de transport : ";
        cin >> transport;
        TrajetSimple t(villePrec, villeSuiv, transport);
        tc.Ajouter(&t);
        strcpy(villePrec, villeSuiv);
        cout << "Etape suivante (ou 1) : ";
    } while(cin >> villeSuiv && strcmp(villeSuiv, "1") != 0);
    trajets.AjouterElement(&tc);
    cout << "Le trajet ";
    tc.Afficher(false);
    cout << " a ete ajoute au catalogue." << endl;
} //----- Fin de ajouterTrajetCompose

void Catalogue::rechercheSimple ( ) const
// Algorithme :
// Entrées : villes de départ et d'arrivée du parcours recherché
// Parcourt tous les trajets du catalogue et affiche ceux dont les villes
// de départ et d'arrivée correspondent à celles recherchées
{
    char villeD[64] = {};
    char villeA[64] = {};
    cout << "Ville de depart : ";
    cin >> villeD;
    cout << "Ville d'arrivee : ";
    cin >> villeA;
    bool trouve = false;
    for(unsigned int i=0; i<trajets.Longueur(); ++i)
    {
        const Trajet* t = trajets.Acceder(i);
        if(strcmp(t->GetDepart(), villeD) == 0 && strcmp(t->GetArrivee(), villeA) == 0)
        {
            cout << "+ Parcours : ";
            t->Afficher();
            trouve = true;
        }
    }
    if(!trouve)
    {
        cout << "Aucun trajet ne correspond a cette requete" << endl;
    }
} //----- Fin de rechercheSimple

void Catalogue::rechercheAvancee ( ) const
// Algorithme :
// Entrées : villes de départ et d'arrivée du parcours recherché
// Initialisation du tableau d'état pour la recherche en profondeur
// Algorithme récursif de parcours en profondeur (DFS)
{
    char villeD[64] = {};
    char villeA[64] = {};
    cout << "Ville de depart : ";
    cin >> villeD;
    cout << "Ville d'arrivee : ";
    cin >> villeA;

    const Trajet ** parcours = new const Trajet* [trajets.Longueur()];
    for(unsigned int i=0; i<trajets.Longueur(); ++i)
    {
        parcours[i] = 0;
    }
    bool trouve = false;
    explorerEnProfondeur(parcours, villeD, villeA, trajets.Longueur(), trouve);
    if(!trouve)
    {
        cout << "Aucun parcours ne correspond a cette requete" << endl;
    }
    delete[] parcours;
} //----- Fin de rechercheAvancee

void Catalogue::explorerEnProfondeur ( const Trajet ** parcours,
                                       const char * depart,
                                       const char * arrivee,
                                       unsigned int niveauMax,
                                       bool& trouve,
                                       unsigned int niveau ) const
// Algorithme :
// Recherche récursive en profondeur avec retour sur trace
{
    //Profondeur maximale atteinte, fin de l'exploration sur cette branche
    if(niveau == niveauMax)
    {
        return;
    }
    //Pour tous les trajets
    for(unsigned int i=0; i<niveauMax; ++i)
    {
        const Trajet * candidat = trajets.Acceder(i);
        //Dont le départ est l'arrivée du précédent trajet
        if(strcmp(candidat->GetDepart(), depart) != 0)
        {
            //Si ça n'est pas le cas, passe au trajet suivant
            continue;
        }
        //Et s'il n'a pas déjà été utilisé
        bool utilise = false;
        for(unsigned int j=0; j<niveau; ++j)
        {
            if(candidat == parcours[j])
            {
                utilise = true;
                break;
            }
        }
        if(!utilise)
        {
            //Valider le trajet
            parcours[niveau] = candidat;
            //Si l'arrivée du parcours est la destination choisie, l'afficher
            if(strcmp(candidat->GetArrivee(), arrivee) == 0)
            {
                trouve = true;
                cout << "+ Parcours : ";
                for(unsigned int j=0; j<=niveau; ++j)
                {
                    if(j > 0)
                    {
                        cout << " - ";
                    }
                    parcours[j]->Afficher(false);
                }
                cout << endl;
            }
            //Continuer l'exploration sur cette branche
            explorerEnProfondeur(parcours, candidat->GetArrivee(), arrivee, niveauMax, trouve, niveau+1);
        }
    }
} //----- Fin de explorerEnProfondeur


