#include <sys/types.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "liste.h"

/*==================================================================================*/
/*								Constructeur de noeud								*/
/*==================================================================================*/
/* Construit un element noeud avec gestion des pointeurs pour chainage avec avec	*/
/* un noeud pr�c�dent.
/*==================================================================================*/
/*======================================================================================*/
/* Si pr�sence d'un noeud pr�c�dent non NULL , le pointeur SUIVANT du nouveau noeud     */
/* pointe sur le m�me �l�ment que le pointeur SUIVANT du noeud pr�c�dent. Le pointeur   */
/* SUIVANT du noeud pr�c�dent pointe alors sur le nouveau noeud							*/
/*======================================================================================*/
/*
/*	   e0	
/*	 ---- 
/*	 |  |   SUIVANT = NULL		Premier �l�ment de la liste
/*	 ----  
/*	 |      ^ 
/*	 |______| 
/*
/*
/*
/*   e0	   e1   
/*  ----  ----  
/*  |  |  |  |  SUIVANT = NULL		Nouvelle �lement dans la liste 
/*  ----  ----  
/*  |     ^ |   ^
/*  |_____| |___|
/*
/*
/*
/*
/*	  e0   e1     e2 
/*	----  ----  ----
/*	|  |  |  |	|  |  SUIVANT = NULL		Nouvelle �lement dans la liste 
/*	----  ----  ----
/*	|     ^ |   ^  |   ^
/*	|_____| |___|  |___|
/*
/*
/*======================================================================================*/

noeud_liste::noeud_liste ( element contenu_nouvel_element , noeud_liste *precedent) 

{


	/* Enregistrement du nouvelle element � stocker dans le noeud */

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
//								Insertion �l�ment									 */
//===================================================================================*/
// Lors de l'insertion d'un �l�ment, un nouveau noeud est cr�� a la suite du dernier */
/* noeud. Si premi�re insertion (on se trouve � la racine), le noeud est directement */
/* cr��. Le mot clef THIS repr�sente un pointeur sur l'objet.Sinon, on parcours la   */
/* liste jusqu'au dernier �l�ment ins�r� et on appelle le constructeur du nouveau    */
/* noeud avec pour param�tre l'�l�ment � ins�rer et un pointeur sur le dernier noeud */
/* ins�r� avant la cr�ation du nouveau noeud										 */
/*===================================================================================*/

void noeud_liste::inserer_element( element e )

{

	
	/*========================================================*/
	/* Si premi�re insertion d'un �l�ment , creation du noeud */
	/*========================================================*/


	if ( noeud_suivant == NULL ) 

		noeud_liste *nouveau = new noeud_liste(e,this );
	
	/*========================================================*/
	/* Sinon , recuperation du dernier �l�ment ins�r�		  */
	/*========================================================*/

	else 		
		
		{

			noeud_liste *noeud =  noeud_suivant ;
			noeud_liste *noeud_precedent = NULL;
		

		while ( noeud != NULL ) 
		
		{
			noeud_precedent = noeud ;
			noeud = noeud->noeud_suivant ;
		}

		/*================================================================*/	
		/* Creation du nouveau noeud a la suite du dernier �l�ment ins�r� */
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