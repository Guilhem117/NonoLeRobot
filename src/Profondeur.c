#include "Algorithme.h"

/**
  *Calcule un chemin qui va de la position de départ à la position d’arrivée
  *\author SERENE Guilhem
  *\param p, le probleme contenant la carte du labyrinthe (et ses obstacles), la position d’arrivée et la position de départ
  *\return P, une pile contenant les sommets constituant le parcours
  *                  ou une pile vide si le chemin n’a pas pu être trouvé
  */
Pile parcours_profondeur(Problem p) {

    Pile chemin;
    int marques[p.nb_ligne][p.nb_colonne];
    int posSuivant;
    int i,j;
    Coordonnee * suivants;

    //Initialisation du tableau des marques
    for(i=0; i < (p.nb_ligne); i++) {
        for (j=0; j < p.nb_colonne; j++) {
            marques[i][j] =0;
        }
    }

    chemin = init_pile();

    ajout_elem(&chemin,&p.depart);

    while ((Coordonnee *)chemin.element != &p.arrive && !pile_vide(chemin)) {
        //ajout_elem(&chemin, chemin.element);
        marques[(*(Coordonnee *)chemin.element).num_ligne][(*(Coordonnee *) chemin.element).num_col] = 1;
        Coordonnee aze = *(Coordonnee *)chemin.element;
        printf("test : (%d;%d)\n", aze.num_ligne, aze.num_col);
        suivants = pos_suiv(&p, *(Coordonnee *) chemin.element);
        //printf("test 2 : (%d;%d) ; (%d;%d) ; (%d;%d) ; (%d;%d)", suivants[0].num_ligne,suivants[0].num_col,suivants[1].num_ligne,suivants[1].num_col,suivants[2].num_ligne,suivants[2].num_col,suivants[3].num_ligne,suivants[3].num_col);
        posSuivant = 0; //Permet de savoir si on a testé une case
        i=0;

        /* Je regarde où je peux me deplacer (dans une position libre) des 4 cotés */
        while (i < 4 && !posSuivant) {
            /* L'Obstacle n’existe pas ou n'est pas déjà marqué */
            if (!obstacle(&p, &suivants[i])
                && marques[suivants[i].num_ligne][suivants[i].num_col] == 0) {
                ajout_elem(&chemin, &suivants[i]);
                posSuivant=1;
            }
            i++;
        }

        //Il n'y a pas de position suivante donc je recule
        if (!posSuivant) {
            retirer_elem(&chemin);
        }
    }

    return chemin;

}
