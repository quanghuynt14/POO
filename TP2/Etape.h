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
    const Etape *EtapePrecedent;
    const Etape *EtapeSuivant;

public:

    Etape (const Trajet *UnTrajet = NULL);

    virtual ~Etape ( );

    void Afficher( ) const;
    const Trajet *getTrajet() const;
    const Etape *getEtapePrecedent() const;
    const Etape *getEtapeSuivante() const;
    void setEtapeSuivant(const Etape *UneEtape);
    void setEtapePrecedent(const Etape *UneEtape);

};


#endif // ETAPE_H

