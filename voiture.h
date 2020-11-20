#include "chassis.h"
#include "moteur.h"

class Voiture
{
public:
	Voiture();
	void calcul_vitesse(void);

	//Chassis* CH;
	Moteur* MT;
protected:
	float vitesse_max;
};