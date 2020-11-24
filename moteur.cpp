#include <cmath>
#include <exception>
#include "moteur.h"

//MOTEUR
Moteur::Moteur()
{
    Q=0.055;
    prix = 0;
}

float Moteur::get_puissance(void)
{
    return puissance;
}
float Moteur::get_consommation(void)
{
    return consommation;
}
float Moteur::get_prix(void)
{
    return prix;
}
float Moteur::get_cylindre(void)
{
    return cylindree;
}
string Moteur::get_name()
{
    return name;
}
string Moteur::get_boite(void)
{
    return boite;
}


//DIESEL
Diesel::Diesel(string boite, float cylindree):Moteur()
{   
    //INIT ATTRIBUTS
    K=0.06;
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

    name = "Diesel";
    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
    this->calcul_prix();
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

void Diesel::calcul_prix(void)
{
    prix += PRICE_DIESEL;
    if(boite=="BVA")
    {
        prix += PRICE_BVA;
    }
    if(cylindree==2200)
    {
        prix += PRICE_CYLINDREE;
    }
}

//ESSENCE
Essence::Essence(string boite, float cylindree):Moteur()
{
    //INIT ATTRIBUTS
    K = 0.07;
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

    name = "Essence";
    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
    this->calcul_prix();
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

void Essence::calcul_prix(void)
{
    prix += PRICE_ESSENCE;
    if(boite=="BVA")
    {
        prix += PRICE_BVA;
    }
    if(cylindree==2200)
    {
        prix += PRICE_CYLINDREE;
    }
}

//ELECTRIQUE
Electrique::Electrique():Moteur()
{
    //INIT ATTRIBUTS
    this->boite = "BVA";
    cylindree = 0;
    puissance=95;
    name = "Electrique";
    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
    this->calcul_prix();
}
void Electrique::calcul_puissance()
{
    this->puissance=95;
}
void Electrique::calcul_consommation()
{
    this->consommation=0;
}
void Electrique::calcul_prix(void)
{   
    prix += PRICE_ELECTRIQUE;
    if(boite=="BVA")
    {
        prix += PRICE_BVA;
    }
    if(cylindree==2200)
    {
        prix += PRICE_CYLINDREE;
    }
}

//HYBRIDE
Hybride::Hybride():Moteur()
{
    //INIT ATTRIBUTS
    essence = new Essence("BVA", 1800);
    electrique = new Electrique();
    name = "Hybride";
    //INIT METHODS
    this->calcul_puissance();
    this->calcul_consommation();
    this->calcul_prix();
}
void Hybride::calcul_puissance()
{
    this->puissance = essence->get_puissance()+electrique->get_puissance();
}

void Hybride::calcul_consommation()
{
    this->consommation = essence->get_consommation();
}
void Hybride::calcul_prix(void)
{
    prix += essence->get_prix() + electrique->get_prix()-PRICE_BVA; //price_bva is counted 2 times in electrique and essence so: -PRICE_BVA
}