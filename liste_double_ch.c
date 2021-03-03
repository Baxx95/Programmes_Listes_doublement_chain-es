#include "liste_double_ch.h"

/*---------------------------------------------------------------------*/

LISTE_ELEMENT	creer_maillon(char15 nom){

	LISTE_ELEMENT	maillon;
	
	maillon = (LISTE_ELEMENT)malloc(sizeof(ELEMENT));
	maillon->prec = NULL;
	maillon->suiv = NULL;
	strcpy(maillon->nom, nom);
	
	return maillon;
};
/*---------------------------------------------------------------------*/

void	afficher_liste_version_iterative(LISTE_ELEMENT liste){
	printf("\n-----------------------------------------------\n");
	if(liste == NULL)
		printf("RIEN A AFFICHER !!!\n");
	else{
		int i = 1;
		LISTE_ELEMENT temp;
		while(liste != NULL){
			printf("NOM[%d] = %s\n",i, liste->nom);
			temp = liste;
			liste = liste->suiv;
			i++;
		}
		printf("-----------------------------------------------\n");
		i--;
		while(temp != NULL){
			printf("NOM[%d] = %s\n",i, temp->nom);
			temp = temp->prec;
			i--;
		}
	}
	printf("-----------------------------------------------\n");
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	saisir_liste(int taille){
	LISTE_ELEMENT maillon, courant, l;
	int i;
	char15 nom;
	
	if (taille >= 1)
	{
		printf("donner nom : \n");
		scanf("%s", nom);
		courant = l = creer_maillon(nom); 
		for (int i = 1; i < taille; i++){	
			printf("donner nom : \n");
			scanf("%s", nom);
			maillon = creer_maillon(nom);
			courant->suiv = maillon;
			maillon->prec = courant;
			courant = courant->suiv;
		}
	}

	return l;
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	ajouter_debut_liste(LISTE_ELEMENT liste, char15 nom){
	LISTE_ELEMENT	nouveau_element;

	nouveau_element = creer_maillon(nom);
	liste->prec = nouveau_element;	
	nouveau_element->suiv = liste;

	return nouveau_element;
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	ajouter_fin_liste(LISTE_ELEMENT liste, char15 nom){
	LISTE_ELEMENT	dernier_element;

	dernier_element = creer_maillon(nom);
	
	if(liste == NULL)
		return dernier_element;
	else{
		LISTE_ELEMENT temp = liste;
		while(temp->suiv != NULL){
			temp = temp->suiv;
		}
		dernier_element->prec = temp;
		temp->suiv = dernier_element;
	return liste;
	}
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	ajouter_a_position_liste(LISTE_ELEMENT liste, char15 nom, int pos){
	LISTE_ELEMENT p1, p2, maillon;
	int j=0;
	p1= p2 = liste;
	maillon = creer_maillon(nom);

	while (p1->suiv != NULL && j < pos){
		p2 = p1;
		p1 = p1->suiv;
	}
	p2->suiv = maillon;
	maillon->prec = p2;
	maillon->suiv = p1;
	p1->prec = maillon;

	return liste;
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	destruction(LISTE_ELEMENT liste){
	free(liste);
	liste = NULL;
	return liste;
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	supprimer_queue(LISTE_ELEMENT liste){
	LISTE_ELEMENT temp, courant;

	if(liste == NULL)
		return NULL;
	else {
		courant = temp = liste;
		while (courant->suiv != NULL){
			temp = courant;
			courant = courant->suiv;
		}
		temp->suiv = NULL;
		courant->prec = NULL;
		destruction(courant);
		return liste;
	}
};
/*---------------------------------------------------------------------*/
LISTE_ELEMENT	supprimer_tete(LISTE_ELEMENT liste){
	LISTE_ELEMENT	temp;

	temp = liste->suiv;
	temp->prec = NULL;
	destruction(liste);

	return temp;
};
/*---------------------------------------------------------------------*/

LISTE_ELEMENT	supprimer_a_position(LISTE_ELEMENT liste, int i){
	LISTE_ELEMENT temp, courant;
	int j=0;

	if(liste == NULL)
		return NULL;
	else{
		temp = courant = liste;
		while(courant->suiv != NULL && j != i){
			temp = courant;
			j++;
			courant = courant->suiv;
		}
		temp->suiv = courant->suiv;
		temp->suiv->prec = temp;
		destruction(courant);
		return liste;
	}
};
/*---------------------------------------------------------------------*/

int	rechercher_elmt(LISTE_ELEMENT liste,char15 nom){
	int i=1;
	
	if(liste == NULL)
		return 0;	
	while(liste != NULL && strcmp(liste->nom,nom)){
		++i;
		liste = liste->suiv;
	}
	return i;
};
/*---------------------------------------------------------------------*/
