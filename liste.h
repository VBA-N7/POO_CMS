#ifndef LISTE_H
#define LISTE_H

#include <sys/types.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "voiture.h"

/*==============================================================*/
/*		Definition du type d'�l�ment manipul�s dans la liste 	*/
/*==============================================================*/

typedef Voiture* element;

/*===================================================================*/
/*		Definition de la classe noeud_liste						     */
/*===================================================================*/
/* Une liste est un ensemble de noeuds, chaque noeud comportant un   */
/* �l�ment stock� et un pointeur sur l'�l�ment suivant de la liste   */
/* L'ensemble des noeuds constituant la liste est ainsi chain�e      */
/* grace au pointeur "noeud_suivant"								 */
/*===================================================================*/


class noeud_liste

{

protected :


	// pointeur sur l'�l�ment suivant de la liste  
	
		noeud_liste *noeud_suivant ; 

	// information contenue dans le noeud 

		element contenu_noeud ;   

public :


	// Constructeur de noeud

		noeud_liste(element , noeud_liste *)  ;		

	// Methode pour ins�rer un nouvel �l�ment dans la liste

		void inserer_element( element e ) ;
	
	// M�thode pour r�cup�rer l'�l�ment contenu dans le noeud

		element recuperer_element();
	
	// M�thode pour r�cup�rer le pointeur sur le noeud suivant lde la liste 

		noeud_liste* recupere_pointeur_suivant() ;


};


noeud_liste* Creation_Liste (element e) ;

#endif