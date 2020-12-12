#ifndef VOITURE_H
#define VOITURE_H
#include "chassis.h"
#include "moteur.h"

#define STARTING_PRICE 15e3

class Voiture
{
public:
	Voiture(Moteur*, Chassis*);
	void calcul_vitesse(void);
	float get_prix(void);
	float get_vitesse_max(void);

	Chassis* CH;
	Moteur* MT;

	float prix = STARTING_PRICE;	
protected:
	float vitesse_max;
};

#endif