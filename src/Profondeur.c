#include "Algorithme.h"

/**
 * Calcul un chemin qui va de la position de départ à la position d’arrivée
 * \author SERENE Guilhem & PRADEL Jordan
 * \param p, le probleme contenant la carte du labyrinthe (et ses obstacles), la position d’arrivée et la position de départ
 * \return une pile contenant les sommets constituant le parcours
 *                  ou une pile vide si le chemin n’a pas pu être trouvé
 */
Pile parcours_profondeur_R(Problem p, Pile chemin, char *marques) {

    int i;

    if ((((Coordonnee *)chemin.element)->num_ligne != p.arrive.num_ligne
        || ((Coordonnee *)chemin.element)->num_col != p.arrive.num_col) && !pile_vide(chemin)) {


        Coordonnee * suivants = (Coordonnee*)malloc(sizeof(Coordonnee));

        suivants = pos_suiv(&p, *(Coordonnee *) chemin.element,1);

        marques[(*(Coordonnee *)chemin.element).num_ligne * p.nb_colonne + (*(Coordonnee *) chemin.element).num_col] = 1;

        //Test les différents possibilitées
        for(i=0; i < 4; i++) {

            if (!obstacle(&p, &suivants[i])
                && marques[suivants[i].num_ligne * p.nb_colonne + suivants[i].num_col] == 0) {
                ajout_elem(&chemin, &suivants[i]);
                affiche_marque(p, marques);
                return parcours_profondeur_R(p,chemin,marques);
            }
        }

        //Il n'y a pas de suivants
        retirer_elem(&chemin);
        return parcours_profondeur_R(p,chemin,marques);
    }

    return chemin;

}
