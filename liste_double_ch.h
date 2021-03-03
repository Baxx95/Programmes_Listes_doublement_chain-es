#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char char15[15];
typedef	struct liste {
	char15 nom;
	struct liste *prec;
	struct liste *suiv;
}	ELEMENT, *LISTE_ELEMENT;

LISTE_ELEMENT	creer_maillon(char15);
LISTE_ELEMENT	saisir_liste(int); 	

LISTE_ELEMENT	ajouter_debut_liste(LISTE_ELEMENT, char15);
LISTE_ELEMENT	ajouter_fin_liste(LISTE_ELEMENT, char15);
LISTE_ELEMENT	ajouter_a_position_liste(LISTE_ELEMENT, char15, int);

LISTE_ELEMENT	destruction(LISTE_ELEMENT);	

LISTE_ELEMENT	supprimer_tete(LISTE_ELEMENT);	 
LISTE_ELEMENT	supprimer_queue(LISTE_ELEMENT);	
LISTE_ELEMENT	supprimer_a_position(LISTE_ELEMENT,int);

void	afficher_liste_version_iterative(LISTE_ELEMENT);

int	rechercher_elmt(LISTE_ELEMENT, char15);
