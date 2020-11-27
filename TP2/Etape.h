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
    const Trajet *TrajetActuel; //1 trajet -> 2 ou plus escales
    Etape *TrajetSuivant;

public:

    Etape (const Trajet *Arrivant);

    virtual ~Etape ( );

    void Afficher( ) const;
    const Trajet *getTrajet() const;
    const Etape *getEtapeSuivante() const;
    void setTrajetSuivant(const Etape UneEtape) const;

};


#endif // ETAPE_H

