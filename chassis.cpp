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

float Chassis::get_prix(void)
{
	if (option == 1)
	{
		return prix + LUXURY_PRICE;
	}
	else
	{
		return prix;
	}
}

string Chassis::get_finition(void)
{
	if (option == 1)
	{
		return "LUXE";
	}
	else
	{
		return "STRD";
	}
}

string Chassis::get_name(void)
{
	return name;
}

/*DEFINITION COUPE CLASS*/

Coupe::Coupe(int option_finition) : Chassis(option_finition)
{
	nb_portes = 2;
	h = 1.3;
	prix += COUPE_PRICE;
	name = "Coupe";
	calcul_coef_pen();
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
	h = 1.4;
	name = "Berline";
	calcul_coef_pen();
}

void Berline::calcul_coef_pen(void)
{
	coef_pen = R * (((L1 - (h / 2) + L2) / 2) * l * h + pow((h / 2), 2));
}

/*DEFINITION BREAK*/
Break::Break(int option_finition) : Berline(option_finition)
{
	L2 = 3.2;
	prix += BERLINE_BREAK_PRICE;
	name = "Break";
	calcul_coef_pen();
}

void Break::calcul_coef_pen(void)
{
	coef_pen = R * (L1 + L2) / 2 * l * h;
}

/*DEFINITION AWD*/
AWD::AWD(int option_finition) : Berline(option_finition)
{
	h = 1.3;
	l = 2.5;
	prix += BERLINE_AWD_PRICE;
	name = "AWD";
	calcul_coef_pen();
}
void AWD::calcul_coef_pen(void)
{
	coef_pen = R * L1 * l * h;
}