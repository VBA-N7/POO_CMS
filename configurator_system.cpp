#include "configurator_system.h"
#include <stdbool.h>
Configurator::Configurator()
{
}

Voiture* Configurator::configurer(void)
{
	Voiture* ma_voiture;
	Chassis* mon_chassis;
	Moteur* mon_moteur;
	
	/*INITIALISATION FOIREUSE SINON PLANTAGE*/
	mon_moteur = new Electrique();
	mon_chassis = new AWD(1);

	int choix, choix_luxe, choix_boite,choix_cyl;
	string boite;
	bool chassis_configured = false;
	bool motor_configured = false;

	cout << "Bienvenue dans le configurateur de voiture" << endl;

	cout << "Voici les types de chassis:" << endl;
	cout << "1)\tBerline simple\n2)\tBerline 4x4\n3)\tBerline Break\n4)\tCoupe" << endl;

	do
	{
		cout << "Faites votre choix de chassis: ";
		cin >> choix;
		cout << "Souhaitez vous l'option luxe ? " << endl;
		cout << "1)\tOUI\n2)\tNON\nChoix: ";
		cin >> choix_luxe;
		if ((choix_luxe != 1) && (choix_luxe != 2))
		{
			cout << "Mauvaise saisie pour la finition luxe" << endl;
			continue;
		}
		switch (choix)
		{
		case 1:
			mon_chassis = new Berline(choix_luxe);
			chassis_configured = true;
			break;
		case 2:
			mon_chassis = new AWD(choix_luxe);
			chassis_configured = true;
			break;
		case 3:
			mon_chassis = new Break(choix_luxe);
			chassis_configured = true;
			break;
		case 4:
			mon_chassis = new Coupe(choix_luxe);
			chassis_configured = true;
			break;
		default:
			cout << "Choix non disponible, veuillez ";
			break;
		}
	} while (!chassis_configured);
	cout << "Choisissez le type de moteur:" << endl;
	cout << "1)\tEssence\n2)\tDiesel\n3)\tHybride\n4)\tElectrique" << endl;

	do
	{
		cout << "Faites votre choix de moteur: ";
		cin >> choix;
		if (choix == 1 || choix == 2)
		{
			cout << "Quelle cylindree souhaitez vous ? " << endl;
			cout << "1)\t 1800\n2)\t2200\nChoix: " << endl;
			cin >> choix_cyl;
			cout << "Quelle type de boite souhaitez vous ? " << endl;
			cout << "1)\t BVA\n2)\tBMA\nChoix: " << endl;
			cin >> choix_boite;

			/*TRAITEMENT MAUVAISE SAISIE*/
			if (choix_cyl != 1 && choix_cyl != 2 && choix_boite != 1 && choix_boite != 2)
			{
				cout << "Mauvaise saisie pour la cylindre ou la boite" << endl;
				continue;
			}

			/*MISE AU FORMAT ATTENDU PAR LE CONSTRUCTEUR*/
			switch (choix_cyl)
			{
			case 1:
				choix_cyl = 1800;
				break;
			case 2:
				choix_cyl = 2200;
				break;
			default:
				break;
			}

			/*MISE AU FORMAT ATTENDU PAR LE CONSTRUCTEUR*/
			switch (choix_boite)
			{
			case 1:
				boite = "BVA";
				break;
			case 2:
				boite = "BMA";
				break;
			default:
				break;
			}
		}
		/*SELECTION DU TYPE DE MOTEUR*/
		switch (choix)
		{
		case 1:
			mon_moteur = new Essence(boite, choix_cyl);
			motor_configured = true;
			break;
		case 2:
			mon_moteur = new Diesel(boite, choix_cyl);
			motor_configured = true;
			break;
		case 3: 
			mon_moteur = new Hybride();
			motor_configured = true;
			break;
		case 4:
			mon_moteur = new Electrique();
			motor_configured = true;
			break;
		default:
			cout << "Choix non disponible, veuillez ressaisir le type de chassis";
			break;
		}
	} while (!motor_configured);

	ma_voiture = new Voiture(mon_moteur, mon_chassis);
	return ma_voiture;

}

void Configurator::afficher(Voiture* ma_voiture)
{
	/*cout << "Type de mon chassis: " << ma_voiture->CH->get_name() << endl;
	cout << "Nombre de portes: " << ma_voiture->CH->get_nb_portes() << endl;
	cout << "Finition: " << ma_voiture->CH->get_finition() << endl;

	cout << "Type de mon moteur: " << ma_voiture->MT->get_name() << endl;
	cout << "Type de boite: " << ma_voiture->MT->get_boite() << endl;
	cout << "Puissance: " << ma_voiture->MT->get_puissance() << endl;
	cout << "Vitesse max: " << ma_voiture->get_vitesse_max() <<" km/h"<< endl;
	cout << "Consommation: " << ma_voiture->MT->get_consommation() << endl;
	cout << "Cylindree: " << ma_voiture->MT->get_cylindre() << endl;*/

	cout << ma_voiture->CH->get_name()<< " " << ma_voiture->CH->get_nb_portes() << "P ";
	cout << ma_voiture->CH->get_finition() << " C" << ma_voiture->MT->get_cylindre();
	cout << " " << ma_voiture->MT->get_boite() << " " << ma_voiture->MT->get_name();
	cout << " " << ma_voiture->MT->get_puissance() << " CV ";
	cout << ma_voiture->get_vitesse_max() << " km/h\t" << ma_voiture->get_prix() << " $" << endl;
}