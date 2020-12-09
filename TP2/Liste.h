/*************************************************************************
                           Liste  -  description (Unsorted and Doubly Linked List)
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/


#if ! defined ( LISTE_H )
#define LISTE_H

#include "Trajet.h"
#include "Etape.h"

class Liste
{

private:
    Etape *premiereEtape; 
    Etape *derniereEtape;
    int size;

public:

    Liste ();

    virtual ~Liste ( );

    void Afficher( ) const;
    Etape *getPremiereEtape() const;
    Etape *getDerniereEtape() const;
    void AjouterTrajet(const Trajet *UnTrajet);
    int getSize() const;
    int getPosition(const Etape *UnEtape) const;
    void RetirerEtape(const Etape *UneEtape);  // The delete opetation in Doubly LinkedList is more efficient 
                                               // if pointer to the node to be deleted is given.

};


#endif // LISTE_H

