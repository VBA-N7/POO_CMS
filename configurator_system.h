#pragma once
#include "voiture.h"

using namespace std;

class Configurator
{
public:
	Configurator();
	Voiture* configurer(void);
	void afficher(Voiture*);
};


