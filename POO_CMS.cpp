#include <iostream>
#include "chassis.h"

using namespace std;

void unit_tests_chassis(void)
{
    cout << "Bienvenue dans la premiere version du CMS" << endl;
    cout << "Ce programme créer differents types de chasssis" << endl;
    cout << "Voici la liste:" << endl;
    cout << "- Coupe\n- Berline\n- Berline 4X4\n- Berline break" << endl;

    Chassis* mon_chassis;

    mon_chassis = new Coupe(1);
    cout << "\nCreation d'un coupe..." << endl;
    mon_chassis->calcul_coef_pen();
    cout << "Nombre de porte de mon Coupe: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon coupe: " << mon_chassis->get_coef_pen() << endl;

    mon_chassis = new AWD(1);
    cout << "\nCreation d'un 4X4..." << endl;
    mon_chassis->calcul_coef_pen();
    cout << "Nombre de porte de mon 4X4: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon 4X4: " << mon_chassis->get_coef_pen() << endl;

    mon_chassis = new Break(1);
    cout << "\nCreation d'un break..." << endl;
    mon_chassis->calcul_coef_pen();
    cout << "Nombre de porte de mon break: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon break: " << mon_chassis->get_coef_pen() << endl;

    mon_chassis = new Berline(1);
    cout << "\nCreation d'une berline..." << endl;
    mon_chassis->calcul_coef_pen();
    cout << "Nombre de porte de ma berline: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de ma berline: " << mon_chassis->get_coef_pen() << endl;
}

int main()
{
    unit_tests_chassis();
}