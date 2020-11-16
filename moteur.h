#include <iostream>
#include <string>

using namespace std;

class moteur
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