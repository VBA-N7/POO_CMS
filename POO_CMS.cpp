#include <iostream>
#include "chassis.h"
#include <string>
#include "moteur.h"

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
int main()
{
    unit_tests_chassis();
    cout<<""<<endl;
    unit_tests_moteur();
}