/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/


#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

class TrajetSimple : public Trajet
{
private:
    char *moyen;

public:

    TrajetSimple(const char *Start, const char *Goal, const char *Means);

    virtual ~TrajetSimple();

    void Afficher() const;

};


#endif // TRAJET_SIMPLE_H

