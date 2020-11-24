#include <stdio.h>
#include <iostream>
using namespace std;

#include "liste.h"

#include "Database.h"

Database::Database(Voiture* voiture)
{
    ma_liste = Creation_Liste(voiture);
}
void Database::stocker(Voiture* voiture)
{
    ma_liste->inserer_element(voiture);
}

void Database::lister()
{
    noeud_liste *i= ma_liste ; //increment
    Voiture* voiture;
    while (i != NULL)
	{
	voiture = i->recuperer_element();
    /*
	cout << voiture->CH->get_name()<< " " << voiture->CH->get_nb_portes() << "P ";
	cout << voiture->CH->get_finition() << " C" << voiture->MT->get_cylindre();
	cout << " " << voiture->MT->get_boite() << " " << voiture->MT->get_name();
	cout << " " << voiture->MT->get_puissance() << " CV ";
	cout << voiture->get_vitesse_max() << " km/h\t" << voiture->get_prix() << " $";
    */


	cout << "Element = " << typeid(voiture).name() << endl ;
    cout << "Element = " << typeid(voiture->CH).name() << endl ;
    cout << "Element = " << typeid(voiture->MT).name() << endl ;
	i = i->recupere_pointeur_suivant();

	}
}
    
/*Voiture Database::filtrer(string)
{

}*/