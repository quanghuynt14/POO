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

    void AjouterTrajetSimple(const TrajetSimple *UnTrajetSimple);

    void AjouterTrajetCompose(const TrajetCompose *UnTrajetCompose);

    void Rechercher(const char *Start, const char *Goal) const;



};


#endif // CATALOGUE_H

