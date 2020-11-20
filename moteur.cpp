#include <cmath>
#include <exception>
#include "moteur.h"


float Moteur::get_puissance(void)
{
    this->calcul_puissance();
    return puissance;
}
float Moteur::get_consommation(void)
{
    this->calcul_consommation();
    return consommation;
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
    if(this->boite=="BMA")
    {
        this->puissance = this->K*this->cylindree;
    }
    else if(this->boite=="BVA")
    {
        this->puissance = 0.9*this->K*this->cylindree;
        
    }
} 

void Diesel::calcul_consommation(void)
{
    this->calcul_puissance();
    this->consommation = this->Q*this->puissance;
}

Essence::Essence(string boite, float cylindree):Moteur()
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

void Essence::calcul_puissance(void)
{
    if(this->boite=="BMA")
    {
        this->puissance = this->K*this->cylindree;
    }
    else if(this->boite=="BVA")
    {
        this->puissance = 0.9*this->K*this->cylindree; 
    }
}

void Essence::calcul_consommation(void)
{
    this->calcul_puissance();
    this->consommation = this->Q*this->puissance;
}

Electrique::Electrique():Moteur()
{
    this->boite = "BVA";
    puissance=95;
}
void Electrique::calcul_puissance()
{
    this->puissance=95;
}
void Electrique::calcul_consommation()
{
    this->calcul_puissance();
    this->consommation=0;
}

Hybride::Hybride():Moteur()
{
    essence = new Essence("BVA", 1800);
    electrique = new Electrique();
}
void Hybride::calcul_puissance()
{
    this->puissance = essence->get_puissance()+electrique->get_puissance();
}

void Hybride::calcul_consommation()
{
    this->consommation = essence->get_consommation();
}



