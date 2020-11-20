#include <iostream>
#include "chassis.h"
#include <string>
#include "moteur.h"

using namespace std;

void unit_tests_chassis(void)
{
    cout << "Bienvenue dans la premiere version du CMS" << endl;
    cout << "Ce programme cr�er differents types de chasssis" << endl;
    cout << "Voici la liste:" << endl;
    cout << "- Coupe\n- Berline\n- Berline 4X4\n- Berline break" << endl;

    Chassis* mon_chassis;

    mon_chassis = new Coupe(1);
    cout << "\nCreation d'un coupe..." << endl;
    cout << "Nombre de porte de mon Coupe: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon coupe: " << mon_chassis->get_coef_pen() << endl;

    mon_chassis = new AWD(1);
    cout << "\nCreation d'un 4X4..." << endl;
    cout << "Nombre de porte de mon 4X4: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon 4X4: " << mon_chassis->get_coef_pen() << endl;

    mon_chassis = new Break(1);
    cout << "\nCreation d'un break..." << endl;
    cout << "Nombre de porte de mon break: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon break: " << mon_chassis->get_coef_pen() << endl;

    mon_chassis = new Berline(1);
    cout << "\nCreation d'une berline..." << endl;
    cout << "Nombre de porte de ma berline: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de ma berline: " << mon_chassis->get_coef_pen() << endl;
}

int main()
{
    unit_tests_chassis();

    //TEST DIESEL DYNAMIC INSTANCE CREATION
    cout<< "TEST DIESEL DYNAMIC INSTANCE CREATION" <<endl;
    Moteur* Diesel1;
    Diesel1 = new Diesel("BVA",float(1800));
    cout<< Diesel1->get_puissance() <<endl;

    //TEST DIESEL STATIC INSTANCE CREATION
    cout<< "TEST DIESEL STATIC INSTANCE CREATION" <<endl;
    Diesel Diesel2("BVA",(float)1800);
    cout<< Diesel2.get_puissance() <<endl;
    //TEST DIESEL CYLINDREE ERROR
    cout<< "TEST DIESEL CYLINDREE ERROR" <<endl;
    Diesel Diesel3("BVA",(float)1700);
    cout<< Diesel3.get_puissance() <<endl;
    //TEST DIESEL BOITE ERROR
    cout<< "TEST DIESEL BOITE ERROR" <<endl;
    Diesel Diesel4("BVE",(float)2200);
    cout<< Diesel4.get_puissance() <<endl;
    

    //TEST ESSENCE DYNAMIC INSTANCE CREATION
    cout<< "TEST ESSENCE DYNAMIC INSTANCE CREATION" <<endl;
    Moteur* Essence1;
    Essence1 = new Diesel("BVA",float(1800));
    cout<< Essence1->get_puissance() <<endl;    
    //TEST ESSENCE STATIC INSTANCE CREATION
    cout<< "TEST ESSENCE CYLINDREE ERROR" <<endl;
    Essence Essence2("BVA",(float)1800);
    cout<< Essence2.get_puissance() <<endl;
    //TEST ESSENCE CYLINDREE ERROR
    cout<< "TEST ESSENCE CYLINDREE ERROR" <<endl;
    Essence Essence3("BVA",(float)1700);
    cout<< Essence3.get_puissance() <<endl;
    //TEST ESSENCE BOITE ERROR
    cout<< "TEST ESSENCE BOITE ERROR" <<endl;
    Essence Essence4("BVE",(float)2200);
    cout<< Essence4.get_puissance() <<endl;
  
    
    //TEST ELECTRIQUE DYNAMIC INSTANCE CREATION
    cout<< "TEST ELECTRIQUE DYNAMIC INSTANCE CREATION" <<endl;
    Moteur* Electrique1;
    Electrique1 = new Electrique();
    cout<< Electrique1->get_puissance() <<endl;    
    //TEST ELECTRIQUE STATIC INSTANCE CREATION
    cout<< "TEST ELECTRIQUE CYLINDREE ERROR" <<endl;
    Electrique Electrique2;
    cout<< Electrique2.get_puissance() <<endl;


    //TEST HYBRIDE DYNAMIC INSTANCE CREATION
    cout<< "TEST HYBRIDE DYNAMIC INSTANCE CREATION" <<endl;
    Moteur* Hybride1;
    Hybride1 = new Hybride();
    cout<< Hybride1->get_puissance() <<endl;    
    //TEST HYBRIDE STATIC INSTANCE CREATION
    cout<< "TEST HYBRIDE CYLINDREE ERROR" <<endl;
    Hybride Hybride2;
    cout<< Hybride2.get_puissance() <<endl;
    

}