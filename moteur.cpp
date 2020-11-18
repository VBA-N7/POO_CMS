#include <cmath>
#include <exception>
#include "moteur.h"


float Moteur::get_puissance(void)
{
    this->calcul_puissance();
    return this->puissance;
}

Diesel::Diesel(string boite, float cylindree):Moteur()
{
    //add try and catch to check if arguments are valid in term of type and value
    try
    {   
        if(cylindree==1800 || cylindree==2200)
        {
            this->cylindree = cylindree;
        }
        else
        {
            throw string("valeur de la cylindree invalide");
        }
        
        if (boite=="BMA" || boite=="BVA")
        {
            this->boite = boite;
        }
        else
        {
            throw string("type de boite de vitesse invalide");
        }
    }
    catch(string str)
    {
        cout << "erreur : " << str <<endl;
    }
    
}

void Diesel::calcul_puissance(void)
{
    this->puissance = this->K*this->cylindree;
}

void Diesel::calcul_consommation(void)
{
    this->calcul_puissance();
    this->consommation = Q*puissance/log10(puissance/6);
}
   
