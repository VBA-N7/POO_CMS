#include "liste.h"

class Database
{
protected:
    noeud_liste *ma_liste ;
public:
    Database(Voiture*);
    void stocker(Voiture*);
    void lister();
    Database* filtrer(string);
};