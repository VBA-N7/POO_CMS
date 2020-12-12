#include <iostream>
#include <string>
#include "liste.h"
#include "Database.h"
#include "configurator_system.h"

using namespace std;

void unit_tests_chassis(void)
{
    cout << "Bienvenue dans la premiere version du CMS" << endl;
    cout << "Ce programme cr�er differents types de chasssis" << endl;
    cout << "Voici la liste:" << endl;
    cout << "- Coupe\n- Berline\n- Berline 4X4\n- Berline break" << endl;

    Chassis* mon_chassis;

    mon_chassis = new Coupe(1);
    cout << "\nCreation d'un coupe de luxe..." << endl;
    cout << "Nombre de porte de mon coupe de luxe: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon coupe de luxe: " << mon_chassis->get_coef_pen() << endl;
    cout << "Prix de mon coupe de luxe: " << mon_chassis->get_prix() << endl;

    mon_chassis = new AWD(1);
    cout << "\nCreation d'un 4X4 de luxe..." << endl;
    cout << "Nombre de porte de mon 4X4 de luxe: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon 4X4 de luxe: " << mon_chassis->get_coef_pen() << endl;
    cout << "Prix de mon 4X4 de luxe: " << mon_chassis->get_prix() << endl;

    mon_chassis = new Break(1);
    cout << "\nCreation d'un break de luxe..." << endl;
    cout << "Nombre de porte de mon break de luxe: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de mon break de luxe: " << mon_chassis->get_coef_pen() << endl;
    cout << "Prix de mon break de luxe: " << mon_chassis->get_prix() << endl;

    mon_chassis = new Berline(1);
    cout << "\nCreation d'une berline de luxe..." << endl;
    cout << "Nombre de porte de ma berline de luxe: " << mon_chassis->get_nb_portes() << endl;
    cout << "Coefficient de penetration de ma berline de luxe: " << mon_chassis->get_coef_pen() << endl;
    cout << "Prix de ma berline de luxe: " << mon_chassis->get_prix() << endl;
}

void unit_tests_moteur(void)
{
    //TEST DIESEL
    cout<<"TEST DIESEL"<<endl;
        //TEST DIESEL DYNAMIC INSTANCE CREATION
        cout<<"    "<<"TEST DIESEL DYNAMIC INSTANCE CREATION" <<endl;
        Moteur* Diesel1;
        Diesel1 = new Diesel("BVA",float(1800));
        cout<<"    "<<Diesel1->get_puissance() <<endl;
        cout<<"    "<<Diesel1->get_prix() <<endl;   //2000 500
        //TEST DIESEL STATIC INSTANCE CREATION
        cout<<"    "<<"TEST DIESEL STATIC INSTANCE CREATION" <<endl;
        Diesel Diesel2("BVA",(float)1800);
        cout<<"    "<<Diesel2.get_puissance() <<endl;
        cout<<"    "<<Diesel2.get_prix() <<endl; //2000 500
        //TEST DIESEL CYLINDREE ERROR
        cout<<"    "<<"TEST DIESEL CYLINDREE ERROR" <<endl;
        Diesel Diesel3("BVA",(float)1700);
        cout<<"    "<<Diesel3.get_puissance() <<endl;
        cout<<"    "<<Diesel3.get_prix() <<endl; //2000 500
        //TEST DIESEL BOITE ERROR
        cout<<"    "<<"TEST DIESEL BOITE ERROR" <<endl;
        Diesel Diesel4("BVE",(float)2200);
        cout<<"    "<<Diesel4.get_puissance() <<endl;
        cout<<"    "<<Diesel4.get_prix() <<endl; //2000 1000

    //TEST ESSENCE
    cout<<"TEST ESSENCE"<<endl;
        //TEST ESSENCE DYNAMIC INSTANCE CREATION
        cout<<"    "<<"TEST ESSENCE DYNAMIC INSTANCE CREATION" <<endl;
        Moteur* Essence1;
        Essence1 = new Essence("BVA",float(1800));
        cout<<"    "<<Essence1->get_puissance() <<endl;
        cout<<"    "<<Essence1->get_prix() <<endl; //500
        //TEST ESSENCE STATIC INSTANCE CREATION
        cout<<"    "<<"TEST ESSENCE CYLINDREE ERROR" <<endl;
        Essence Essence2("BVA",(float)1800);
        cout<<"    "<<Essence2.get_puissance() <<endl;
        cout<<"    "<<Essence2.get_prix() <<endl; //500
        //TEST ESSENCE CYLINDREE ERROR
        cout<<"    "<<"TEST ESSENCE CYLINDREE ERROR" <<endl;
        Essence Essence3("BVA",(float)1700);
        cout<<"    "<<Essence3.get_puissance() <<endl;
        cout<<"    "<<Essence3.get_prix() <<endl; //500
        //TEST ESSENCE BOITE ERROR
        cout<<"    "<<"TEST ESSENCE BOITE ERROR" <<endl;
        Essence Essence4("BVE",(float)2200);    //1000
        cout<<"    "<<Essence4.get_puissance() <<endl;
        cout<<"    "<<Essence4.get_prix() <<endl;  

    //TEST ELECTRIQUE
    cout<<"TEST ELECTRIQUE"<<endl;
        //TEST ELECTRIQUE DYNAMIC INSTANCE CREATION
        cout<<"    "<<"TEST ELECTRIQUE DYNAMIC INSTANCE CREATION" <<endl;
        Moteur* Electrique1;
        Electrique1 = new Electrique();
        cout<<"    "<<Electrique1->get_puissance() <<endl;
        cout<<"    "<<Electrique1->get_prix() <<endl; //3000 500
        //TEST ELECTRIQUE STATIC INSTANCE CREATION
        cout<<"    "<<"TEST HYBRIDE STATIC INSTANCE CREATION" <<endl;
        Electrique Electrique2;
        cout<<"    "<<Electrique2.get_puissance() <<endl;
        cout<<"    "<<Electrique2.get_prix() <<endl; //3000 500
        

    //TEST HYBRIDE
    cout<<"TEST HYBRIDE"<<endl;
        //TEST HYBRIDE DYNAMIC INSTANCE CREATION
        cout<<"    "<<"TEST HYBRIDE DYNAMIC INSTANCE CREATION" <<endl;
        Moteur* Hybride1;
        Hybride1 = new Hybride();
        cout<<"    "<<Hybride1->get_puissance() <<endl; 
        cout<<"    "<<Hybride1->get_prix() <<endl; //3000 500
        //TEST HYBRIDE STATIC INSTANCE CREATION
        cout<<"    "<<"TEST HYBRIDE STATIC INSTANCE CREATION" <<endl;
        Hybride Hybride2;
        cout<<"    "<<Hybride2.get_puissance() <<endl;
        cout<<"    "<<Hybride2.get_prix() <<endl;   
}

void unit_tests_voiture(void)
{
    Voiture* ma_voiture;
    Chassis* choix_chassis; 
    Moteur* choix_moteur;
    
    /*CREATION VOITURE LA MOINS CHERE*/
    choix_chassis = new Berline(0);
    choix_moteur = new Essence("BMA", float(1800));
    ma_voiture = new Voiture(choix_moteur, choix_chassis);
    cout << "Berline Essence 1800 en BMA" << endl;
    cout << "Prix de ma voiture: " << ma_voiture->get_prix() << " euros" << endl;
    cout << "Vitesse max de ma voiture: " << ma_voiture->get_vitesse_max() << " km/h" << endl;

    /*CREATION VOITURE LA PLUS CHERE*/
    choix_chassis = new AWD(1);
    choix_moteur = new Hybride();
    ma_voiture = new Voiture(choix_moteur, choix_chassis);
    cout << "\nBerline Essence 1800 en BMA" << endl;
    cout << "Prix de ma voiture: " << ma_voiture->get_prix() << " euros" << endl;
    cout << "Vitesse max de ma voiture: " << ma_voiture->get_vitesse_max() << " km/h"<< endl;
 }

void unit_tests_configurateur(void)
{
    Configurator mon_configurateur;
    mon_configurateur.afficher(mon_configurateur.configurer());
}
void unit_tests_database(void)
{   
    //TEST DATABASE
    cout<<"    "<<"TEST DATABASE" <<endl;
    Diesel moteur0("BVA",float(1800));
    Diesel moteur1("BVA",float(2200));
    Diesel moteur2("BMA",float(1800));
    Diesel moteur3("BMA",float(2200));

    Essence moteur4("BVA",float(1800));
    Essence moteur5("BVA",float(2200));
    Essence moteur6("BMA",float(1800));
    Essence moteur7("BMA",float(2200));

    Hybride moteur8();
    Electrique moteur9();

    Coupe chassis0(1);
    Coupe chassis1(0);
    Berline chassis2(1);
    Berline chassis3(0);
    Break chassis4(1);
    Break chassis5(0);
    AWD chassis6(1);
    AWD chassis7(0);

    Voiture voiture0(&moteur0,&chassis0);
    Voiture voiture1(&moteur1,&chassis0);
    Voiture voiture2(&moteur2,&chassis0);
    Voiture voiture3(&moteur3,&chassis0);
    Voiture voiture4(&moteur4,&chassis0);
    Voiture voiture5(&moteur5,&chassis0);
    Voiture voiture6(&moteur6,&chassis0);
    Voiture voiture7(&moteur7,&chassis0);
    Voiture voiture8(&moteur0,&chassis1);
    Voiture voiture9(&moteur1,&chassis1);
    Voiture voiture10(&moteur2,&chassis1);
    Voiture voiture11(&moteur3,&chassis1);
    Voiture voiture12(&moteur4,&chassis1);
    Voiture voiture13(&moteur5,&chassis1);
    Voiture voiture14(&moteur6,&chassis1);
    Voiture voiture15(&moteur7,&chassis1);
    
    Database database(&voiture0);
    database.stocker(&voiture1);
    database.stocker(&voiture2);
    database.stocker(&voiture3);
    database.stocker(&voiture4);
    database.stocker(&voiture5);
    database.stocker(&voiture6);
    database.stocker(&voiture7);
    database.stocker(&voiture8);
    database.stocker(&voiture9);
    database.stocker(&voiture10);
    database.stocker(&voiture11);
    database.stocker(&voiture12);
    database.stocker(&voiture13);
    database.stocker(&voiture14);
    database.stocker(&voiture15);
    database.lister();
}

void unit_tests_database_filter(void)
{
    //TEST DATABASE_FILTRE
    cout<<"    "<<"TEST DATABASE_FILTRE" <<endl;
    Diesel moteur0("BVA",float(1800));
    Diesel moteur1("BVA",float(2200));
    Diesel moteur2("BMA",float(1800));
    Diesel moteur3("BMA",float(2200));

    Essence moteur4("BVA",float(1800));
    Essence moteur5("BVA",float(2200));
    Essence moteur6("BMA",float(1800));
    Essence moteur7("BMA",float(2200));

    Hybride moteur8();
    Electrique moteur9();

    Coupe chassis0(1);
    Coupe chassis1(0);
    Berline chassis2(1);
    Berline chassis3(0);
    Break chassis4(1);
    Break chassis5(0);
    AWD chassis6(1);
    AWD chassis7(0);

    Voiture voiture0(&moteur0,&chassis0);
    Voiture voiture1(&moteur1,&chassis0);
    Voiture voiture2(&moteur2,&chassis0);
    Voiture voiture3(&moteur3,&chassis0);
    Voiture voiture4(&moteur4,&chassis0);
    Voiture voiture5(&moteur5,&chassis0);
    Voiture voiture6(&moteur6,&chassis0);
    Voiture voiture7(&moteur7,&chassis0);
    Voiture voiture8(&moteur0,&chassis1);
    Voiture voiture9(&moteur1,&chassis1);
    Voiture voiture10(&moteur2,&chassis1);
    Voiture voiture11(&moteur3,&chassis1);
    Voiture voiture12(&moteur4,&chassis1);
    Voiture voiture13(&moteur5,&chassis1);
    Voiture voiture14(&moteur6,&chassis1);
    Voiture voiture15(&moteur7,&chassis1);
    
    Database database(&voiture0);
    database.stocker(&voiture1);
    database.stocker(&voiture2);
    database.stocker(&voiture3);
    database.stocker(&voiture4);
    database.stocker(&voiture5);
    database.stocker(&voiture6);
    database.stocker(&voiture7);
    database.stocker(&voiture8);
    database.stocker(&voiture9);
    database.stocker(&voiture10);
    database.stocker(&voiture11);
    database.stocker(&voiture12);
    database.stocker(&voiture13);
    database.stocker(&voiture14);
    database.stocker(&voiture15);
    database.lister();

    cout<<" "<<endl;
    Database* database2 = NULL;
    database2=database.filtrer("Diesel");
    database2->lister();
}

void all_test(void)
{
    unit_tests_chassis();
    cout<<""<<endl;
    unit_tests_moteur();
    cout << "" << endl;
    unit_tests_voiture();
    cout << "" << endl;
    unit_tests_configurateur();
    cout << "" << endl;
    unit_tests_database();
    cout << "" << endl;
    unit_tests_database_filter();
}