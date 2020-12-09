/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/


#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

class Catalogue
{
private:
    Liste *trajets;

public:

    Catalogue();

    virtual ~Catalogue();

    void Afficher() const;

    void AjouterTrajetSimple();

    void AjouterTrajetCompose(const TrajetCompose *UnTrajetCompose);

    void RechercheSimple(const char *Start, const char *Goal) const;

    void RechercheAvancee(const char *Start, const char *Goal) const;

    void BFS(const Trajet *x, bool *v, const char *Goal, 
             Liste *Chemin, int &nbParcours) const;



};


#endif // CATALOGUE_H

