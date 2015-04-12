#include <stdlib.h>
#include <stdio.h>
#include "position.h"
#include <math.h>

/** Verifie si la position actuelle n'a pas obstacle
 * \author Jordan PRADEL & SERENE G.
 * \param p, Le probleme avec la caractéristique de la carte
 * \param position à tester
 * \return 1 Si la position contient un obstacle ou n'est pas accessible
 *         0 sinon
 */
int obstacle(Problem *p, Coordonnee * position) {
    if (position->num_ligne < 0 || position->num_ligne > p->nb_ligne
     || position->num_col < 0 || position->num_col > p->nb_colonne) return 1;
    return p->carte[position->num_ligne][position->num_col] != ' ';
}

/**
 * Renvoie les positions possibles pour le déplacement du robot
 * \author Jordan PRADEL & SERENE G.
 * \param p, Le probleme avec la caractéristique de la carte
 * \param position à tester
 * \param optimisation - Trie le tableau des possibilités en fonction de la distance avec pos_actuelle
 * \return Tableau de 4 coordonnées possibles (haut, droite, bas et gauche)
 *         Chacune des cases correspondent à une coordonnee ( si elles sont différentes de -1)
 *         S'il n'y a pas de coordonnees (-1,-1) le deplacement est possible
 */
Coordonnee *pos_suiv(Problem *p, Coordonnee pos_actuelle, int optimisation) {
    Coordonnee c, * possibles;
    possibles = (Coordonnee *) malloc(4*sizeof(Coordonnee));

    for(int i =0; i < 4; i++) {
        possibles[i].num_col = -1;
        possibles[i].num_ligne = -1;
    }

    // Déplacement à haut
    c.num_ligne = (pos_actuelle.num_ligne)-1,
    c.num_col = pos_actuelle.num_col;

    if (!obstacle(p, &c)) {
        possibles[0] = c;
    }

    // Déplacement en droite
    c.num_ligne = pos_actuelle.num_ligne,
    c.num_col = (pos_actuelle.num_col)+1;

    if (!obstacle(p, &c)) {
        possibles[1] = c;
    }

    // Déplacement à bas
    c.num_ligne = (pos_actuelle.num_ligne)+1,
    c.num_col = pos_actuelle.num_col;

    if (!obstacle(p, &c)) {
        possibles[2] = c;
    }

    // Déplacement en gauche
    c.num_ligne = pos_actuelle.num_ligne,
    c.num_col = (pos_actuelle.num_col)-1;

    if (!obstacle(p, &c)) {
        possibles[3] = c;
    }
    printf("\n\n");

    if (optimisation) {
        tri_coordonnees(p, possibles);
    }

    return possibles;
}

/** Trie le tableau de coordonnées
 * \param p - Permet d'obtenir la position d'arrivée pour le tri
 * \param tab - Tableau à trier
 */
void tri_coordonnees(Problem *p, Coordonnee *tab) {
    int i, j;
    Coordonnee temp;
    for (i=0; i<4; i++) {
       for (j=0; j<4; j++) {
            if (calcul_distance(tab[j],p->arrive) > calcul_distance(tab[i],p->arrive)) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

/** Trie le tableau de coordonnées
 * \param p - Permet d'obtenir la position d'arrivée pour le tri
 * \param tab - Tableau à trier
 */
int calcul_distance(Coordonnee a, Coordonnee b) {
    return sqrt((a.num_col - b.num_col)*(a.num_col - b.num_col) + (a.num_ligne - b.num_ligne)*(a.num_ligne - b.num_ligne));
}

/** Affiche les deplacements du robot et marque une position
 * \param p - La carte du probleme
 * \param deplacement - Le tableau representant les endroits
 */
void affiche_marque(Problem p, char *deplacement) {

    //Permet de definir les commandes adquates en fonction du SE
    #ifdef __unix__
        #define Win 0
    #elif defined(_WIN32) || defined(WIN32)
        #define Win 1
    #endif

    int i,j;

    system(Win ? "cls" : "clear");

    for(i=0; i < p.nb_ligne; i++) {

        for(j=0; j < p.nb_colonne; j++) {
            printf("%c", (deplacement[i * p.nb_colonne + j] == 1 ? '*': ' '));
        }

        printf("\n");

    }

}
