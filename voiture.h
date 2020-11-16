#include "chassis.h"
#include "moteur.h"

class Voiture
{
public:
	Voiture();
	void calcul_vitesse(void);

	//chassis* CH;
	//moteur* MT;
protected:
	float vitesse_max;
};