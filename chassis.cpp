#include "chassis.h"

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

