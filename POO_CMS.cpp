#include <iostream>
#include <string>
#include "liste.h"
#include "Database.h"
#include "configurator_system.h"
#include "test.h"

using namespace std;

int main()
{
    //all_test();

    Configurator configurator;
    Voiture* voiture;
    char rep='y';
    string filtre;

    //first interation is out of while(1)
    //as database must be create with one element

    voiture = configurator.configurer(); //configurer une voiture
    configurator.afficher(voiture);      //afficher la voiture
    Database database(voiture);          //mettre la voiture dans database

    while (1)
    {
        cout <<"Continue (y)? " ; cin >> rep; if (rep !='y') break;
        
        voiture = configurator.configurer();
        configurator.afficher(voiture);
        database.stocker(voiture);
    }
    
    database.lister();


    cout <<"Filtrer ?" ;                    // Pas de gestion d'erreur
    cin >> filtre;                          // il faut ecrire le filtre 
    Database* database_filtre;              // correctement
    database_filtre=database.filtrer(filtre);
    database_filtre->lister();
}
