/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/


#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

#include "Trajet.h"
#include "Liste.h"

class TrajetCompose : public Trajet 
{
private:
    Liste *Etapes;

public:

    TrajetCompose();
    
    TrajetCompose(const char *Start, const char *Goal, const Liste *UneListe);

    virtual ~TrajetCompose();

    void Afficher() const;

};


#endif // TRAJET_COMPOSE_H

