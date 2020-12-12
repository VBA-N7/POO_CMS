#include <iostream>
#include <string>

using namespace std;

#define PRICE_DIESEL 2000
#define PRICE_ESSENCE 0
#define PRICE_ELECTRIQUE 3000
#define PRICE_HYBRIDE 3000
#define PRICE_CYLINDREE 1000
#define PRICE_BVA 500

class Moteur
{
protected:
    float cylindree;
    string boite;
    float puissance;
    float consommation;

    float K;
    float Q;

    float prix;
    string name;

public:
    Moteur();
    virtual void calcul_consommation()=0;
    virtual void calcul_puissance()=0;
    virtual void calcul_prix()=0;
    float get_puissance();
    float get_consommation();
    float get_prix();
    float get_cylindre();
    string get_name();
    string get_boite();
};

class Diesel:public Moteur
{
public:
    Diesel(string boite, float cylindree);
    void calcul_consommation();
    void calcul_puissance();
    void calcul_prix();
};
 
class Essence:public Moteur
{
public:
    Essence(string boite, float cylindree);
    void calcul_consommation();
    void calcul_puissance();
    void calcul_prix();
};

class Electrique:public Moteur
{
public:
    Electrique();
    void calcul_puissance();
    void calcul_consommation();
    void calcul_prix();
};

class Hybride:public Moteur
{
public:
    Hybride();
    void calcul_puissance();
    void calcul_consommation();
    void calcul_prix();
   
protected:
    Essence* essence;
    Electrique* electrique; 
};
