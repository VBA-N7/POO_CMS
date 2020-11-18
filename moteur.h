#include <iostream>
#include <string>

using namespace std;

class Moteur
{
protected:
    float cylindree;
    string boite;
    float puissance;
    float consommation;

float K;
float Q=0.055;

public:
    virtual void calcul_consommation(void)=0;
    virtual void calcul_puissance(void)=0;
    float get_puissance(void);
};

class Diesel:public Moteur
{
protected:
    float K=0.06;
public:
    Diesel(string boite, float cylindree);
    void calcul_consommation(void);
    void calcul_puissance(void);
};
 
class Essence:public Moteur
{
protected:
    float K = 0.06;
public:
    Essence(string boite, float cylindree);
    void calcul_consommation(void);
    void calcul_puissance(void);
};

class Electrique:public Moteur
{
protected:
    float cylindre = 0;
    float consommation = 0;
    string boite;
    float puissance=95;
public:
    Electrique();
    void calcul_puissance(void);
    void calcul_consommation(void);
};
