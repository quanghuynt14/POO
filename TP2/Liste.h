/*************************************************************************
                           Liste  -  description
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

public:

    Liste (Etape *UnePremiereEtape = nullptr);

    virtual ~Liste ( );

    void Afficher( ) const;
    const Trajet *getPremierTrajet() const;
    void AjouterEtape(const Trajet *UnTrajet);

};


#endif // ETAPE_H

