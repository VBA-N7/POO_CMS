#include "voiture.h"

Voiture::Voiture()
{
}
float Voiture::get_prix(void)
{
	// return 15k€ - (surcout chassis + surcout moteur)
	return prix - (CH->get_prix() /*+ MT->get_prix()*/);
}

/*void Voiture::calcul_vitesse(void)
{
	vitesse_max = 2 * MT->get_puissance() * (1 - CH->get_coef_pen());
}*/
