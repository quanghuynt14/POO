/*************************************************************************
                           Etape  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/


#if ! defined ( ETAPE_H )
#define ETAPE_H

#include "Trajet.h"

class Etape
{

private:
    const Trajet *TrajetActuel; 
    Etape *EtapePrecedent;
    Etape *EtapeSuivant;

public:

    Etape (const Trajet *UnTrajet = NULL);

    Etape (const Etape *UneEtape);

    virtual ~Etape ( );

    void Afficher() const;
    const Trajet *getTrajet() const;
    Etape *getEtapePrecedent() const;
    Etape *getEtapeSuivante() const;
    void setEtapeSuivant( Etape *UneEtape);
    void setEtapePrecedent( Etape *UneEtape);

};


#endif // ETAPE_H

