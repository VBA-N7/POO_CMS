#include <sys/types.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "liste.h"

/*==================================================================================*/
/*								Constructeur de noeud								*/
/*==================================================================================*/
/* Construit un element noeud avec gestion des pointeurs pour chainage avec avec	*/
/* un noeud précédent.
/*==================================================================================*/
/*======================================================================================*/
/* Si présence d'un noeud précédent non NULL , le pointeur SUIVANT du nouveau noeud     */
/* pointe sur le même élément que le pointeur SUIVANT du noeud précédent. Le pointeur   */
/* SUIVANT du noeud précédent pointe alors sur le nouveau noeud							*/
/*======================================================================================*/
/*
/*	   e0	
/*	 ---- 
/*	 |  |   SUIVANT = NULL		Premier élément de la liste
/*	 ----  
/*	 |      ^ 
/*	 |______| 
/*
/*
/*
/*   e0	   e1   
/*  ----  ----  
/*  |  |  |  |  SUIVANT = NULL		Nouvelle élement dans la liste 
/*  ----  ----  
/*  |     ^ |   ^
/*  |_____| |___|
/*
/*
/*
/*
/*	  e0   e1     e2 
/*	----  ----  ----
/*	|  |  |  |	|  |  SUIVANT = NULL		Nouvelle élement dans la liste 
/*	----  ----  ----
/*	|     ^ |   ^  |   ^
/*	|_____| |___|  |___|
/*
/*
/*======================================================================================*/

noeud_liste::noeud_liste ( element contenu_nouvel_element , noeud_liste *precedent) 

{


	/* Enregistrement du nouvelle element à stocker dans le noeud */

	contenu_noeud = contenu_nouvel_element ;

	/* Gestion des pointeur pour chainage */

	 if (precedent!=NULL)
	{	

		 noeud_suivant = NULL ;
		 precedent->noeud_suivant = this;

	}

	else noeud_suivant = NULL ;

}


//===================================================================================*/
//								Insertion élément									 */
//===================================================================================*/
// Lors de l'insertion d'un élément, un nouveau noeud est créé a la suite du dernier */
/* noeud. Si première insertion (on se trouve à la racine), le noeud est directement */
/* créé. Le mot clef THIS représente un pointeur sur l'objet.Sinon, on parcours la   */
/* liste jusqu'au dernier élément inséré et on appelle le constructeur du nouveau    */
/* noeud avec pour paramètre l'élément à insérer et un pointeur sur le dernier noeud */
/* inséré avant la création du nouveau noeud										 */
/*===================================================================================*/

void noeud_liste::inserer_element( element e )

{

	
	/*========================================================*/
	/* Si première insertion d'un élément , creation du noeud */
	/*========================================================*/


	if ( noeud_suivant == NULL ) 

		noeud_liste *nouveau = new noeud_liste(e,this );
	
	/*========================================================*/
	/* Sinon , recuperation du dernier élément inséré		  */
	/*========================================================*/

	else 		
		
		{

			noeud_liste *noeud =  noeud_suivant ;
			noeud_liste *noeud_precedent ;
		

		while ( noeud != NULL ) 
		
		{
			noeud_precedent = noeud ;
			noeud = noeud->noeud_suivant ;
		}

		/*================================================================*/	
		/* Creation du nouveau noeud a la suite du dernier élément inséré */
		/*================================================================*/	

		noeud_liste *nouveau = new noeud_liste(e,noeud_precedent );
	
	}
    	
}


/*===================================================================================*/
/*						       Recuperation du contenu du noeud						 */
/*===================================================================================*/


element noeud_liste::recuperer_element()

{

return contenu_noeud ;

}

/*===================================================================================*/
/*		       Recuperation du pointeur suivant du noeud courant 					 */
/*===================================================================================*/

noeud_liste* noeud_liste::recupere_pointeur_suivant()

{

return noeud_suivant ;

}


noeud_liste* Creation_Liste (element e) 

{  
	noeud_liste *racine = new noeud_liste ((e), (noeud_liste*) 0);

    return racine;
}