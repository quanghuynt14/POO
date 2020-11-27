/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

class Trajet
{

private:
    char *depart; 
    char *arrivee; 

protected:
    Trajet(const char *Start, const char *Goal);
    virtual ~Trajet();

public:

    //Trajet & operator = ( const Trajet & unTrajet );
    virtual void Afficher() const = 0;
    const char *getDepart() const;
    const char *getArrivee() const;

};


#endif // TRAJET_H

