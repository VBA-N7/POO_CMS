#include <cmath>
#include <exception>
#include "moteur.h"

//MOTEUR

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

//DIESEL

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

    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
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
    this->consommation = this->Q*this->puissance;
}

//ESSENCE

Essence::Essence(string boite, float cylindree):Moteur()
{
    //INIT ATTRIBUTS
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

    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
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
    this->consommation = this->Q*this->puissance;
}

//ELECTRIQUE

Electrique::Electrique():Moteur()
{
    //INIT ATTRIBUTS
    this->boite = "BVA";
    puissance=95;
    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
}
void Electrique::calcul_puissance()
{
    this->puissance=95;
}
void Electrique::calcul_consommation()
{
    this->consommation=0;
}

//HYBRIDE

Hybride::Hybride():Moteur()
{
    //INIT ATTRIBUTS
    essence = new Essence("BVA", 1800);
    electrique = new Electrique();
    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
}
void Hybride::calcul_puissance()
{
    this->puissance = essence->get_puissance()+electrique->get_puissance();
}

void Hybride::calcul_consommation()
{
    this->consommation = essence->get_consommation();
}



