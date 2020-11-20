#include <iostream>
#include <string>
#include "moteur.h"

int main()
{

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