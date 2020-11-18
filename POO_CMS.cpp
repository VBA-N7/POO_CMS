#include <iostream>
#include <string>
#include "moteur.h"

int main()
{
    std::cout << "Hello World!\n";

    //TEST STATIC INSTANCE CREATION
    Diesel Diesel1("BVA",(float)1800);
    cout<< Diesel1.get_puissance() <<endl;
    //TEST CYLINDREE ERROR
    Diesel Diesel2("BVA",(float)1700);
    cout<< Diesel2.get_puissance() <<endl;
    //TEST BOITE ERROR
    Diesel Diesel3("BVE",(float)2200);
    cout<< Diesel3.get_puissance() <<endl;
    
}