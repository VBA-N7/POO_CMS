#include "chassis.h"
#include "moteur.h"

#define STARTING_PRICE 15e3

class Voiture
{
public:
	Voiture();
	//void calcul_vitesse(void);
	float get_prix(void);

	Chassis* CH;
	Moteur* MT;

	float prix = STARTING_PRICE;	
protected:
	float vitesse_max;
};
