#include "position.h"
#include "Pile.h"
#include "File.h"

int toutMarque(Problem * p, Coordonnee positionActuelle, int* Marque){
    Coordonnee* suivants =  pos_suiv(p,positionActuelle,1);
	return  ((suivants[0].num_col==-1 || Marque[0]==1)
	      && (suivants[1].num_col==-1 || Marque[1]==1)
		  && (suivants[2].num_col==-1 || Marque[2]==1)
		  && (suivants[3].num_col==-1 || Marque[3]==1));
}

/** Permet d’obtenir le parcours demandé par un probléme à l’aide d’un algorithme de parcours en largeur.
 * ATTENTION : Le programme envoi une Pile_Vide
 * \author Salandini Steven
 * \param m, le problème contenant les sommets de départ/de fin et la map->
 * \return chemin la pile contenant les sommets constituants le parcours
 *         null si aucun chemin possible
 */
Pile parcours_largeur(Problem * p){

    Pile chemin;
    File F;
    int DegreExt, numU;
    Coordonnee * suivants;
	Coordonnee suivant,positionActuelle;
	int Marque[4] = {0,0,0,0};
    chemin = init_pile();

	//On place le premier élement
	F = init_File();
    AjouterElemF(&F,&p->depart);
    ajout_elem(&chemin,&p->depart);
	//Tant que la file de lecture n'est pas vide, on lit les chemins suivant
    while(!FileVide(F)){
        positionActuelle = *(Coordonnee *) RetirerElemF(&F);
        if(positionActuelle.num_ligne == p->arrive.num_ligne
            && positionActuelle.num_col == p->arrive.num_col) {
            return chemin;
        }

        suivants = pos_suiv(p,positionActuelle,1);

        for(numU=0, DegreExt = 0; numU<4 ;numU++) {
            suivant = suivants[numU];
            if(!Marque[numU] && suivant.num_col == -1) {
                DegreExt++;
                Marque[numU] = 1;
                AjouterElemF(&F,&suivant);
                ajout_elem(&chemin,&suivant);
            }
        }

        if(DegreExt == 0 || toutMarque(p,positionActuelle,Marque)) {
            retirer_elem(&chemin);
        }
    }
	return init_pile();//Si pas de chemin retourner une file vide
}
