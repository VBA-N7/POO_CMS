#include "voiture.h"

Voiture::Voiture(Moteur* my_engine, Chassis* my_chassis)
{
	MT = my_engine;
	CH = my_chassis;
	calcul_vitesse();
}

float Voiture::get_prix(void)
{
	// return 15k€ - (surcout chassis + surcout moteur)
	return prix + (CH->get_prix() + MT->get_prix());
}

void Voiture::calcul_vitesse(void)
{
	vitesse_max = 2 * MT->get_puissance() * (1 - CH->get_coef_pen());
}

float Voiture::get_vitesse_max(void)
{
	return vitesse_max;
}