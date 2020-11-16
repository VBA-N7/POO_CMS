#include "chassis.h"
#include <math.h>

/*DEFINITION CHASSIS CLASS*/
Chassis::Chassis(int option_finition)
{
	option = option_finition;
}

int Chassis::get_nb_portes(void)
{
	return nb_portes;
}

float Chassis::get_coef_pen(void)
{
	return coef_pen;
}

/*DEFINITION COUPE CLASS*/

Coupe::Coupe(int option_finition) : Chassis(option_finition)
{
	nb_portes = 2;
	h = 1.3;
}

void Coupe::calcul_coef_pen(void)
{
	coef_pen = R * l * L1 / 2 * h;
}

/*DEFINITION BERLINE*/

Berline::Berline(int option_finition) : Chassis(option_finition)
{
	nb_portes = 4;
	L2 = 2;
	h = 1.3;
}

void Berline::calcul_coef_pen(void)
{
	coef_pen = R * (((L1 - (h / 2) + L2) / 2) * l * h + pow((h / 2), 2));
}