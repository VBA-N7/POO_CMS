#include <iostream>
#include <string>
#include "moteur.h"

int main()
{
    std::cout << "Hello World!\n";

    //TEST DIESEL STATIC INSTANCE CREATION
    cout<< "TEST DIESEL STATIC INSTANCE CREATION" <<endl;
    Diesel Diesel1("BVA",(float)1800);
    cout<< Diesel1.get_puissance() <<endl;
    //TEST DIESEL CYLINDREE ERROR
    cout<< "TEST DIESEL CYLINDREE ERROR" <<endl;
    Diesel Diesel2("BVA",(float)1700);
    cout<< Diesel2.get_puissance() <<endl;
    //TEST DIESEL BOITE ERROR
    cout<< "TEST DIESEL BOITE ERROR" <<endl;
    Diesel Diesel3("BVE",(float)2200);
    cout<< Diesel3.get_puissance() <<endl;
    
    //TEST ESSENCE STATIC INSTANCE CREATION
    cout<< "TEST ESSENCE CYLINDREE ERROR" <<endl;
    Essence Essence1("BVA",(float)1800);
    cout<< Essence1.get_puissance() <<endl;
    //TEST ESSENCE CYLINDREE ERROR
    cout<< "TEST ESSENCE CYLINDREE ERROR" <<endl;
    Essence Essence2("BVA",(float)1700);
    cout<< Essence2.get_puissance() <<endl;
    //TEST ESSENCE BOITE ERROR
    cout<< "TEST ESSENCE BOITE ERROR" <<endl;
    Essence Essence3("BVE",(float)2200);
    cout<< Essence3.get_puissance() <<endl;
    
}