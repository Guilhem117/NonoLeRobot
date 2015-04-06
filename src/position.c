#include "position.h"

/** Verifie si la position actuelle n'a pas obstacle
 * @author Jordan PRADEL & SERENE G.
 * @param p, Le probleme avec la caractéristique de la carte
 * @param position à tester
 * @return 1 Si la position contient un obstacle ou n'est pas accessible
 *         0 sinon
 */
int obstacle(Problem *p, Coordonnee position) {
    if (position.num_ligne < 0 || position.num_ligne > p->nb_ligne
     || position.num_col < 0 || position.num_col > p->nb_colonne) return 1;
    return p->carte[position.num_ligne][position.num_col] != ' ' ;
}

/**
 * Renvoie les positions possibles pour le déplacement du robot
 * @author Jordan PRADEL & SERENE G.
 * @param p, Le probleme avec la caractéristique de la carte
 * @param position à tester
 * @return Tableau de 4 coordonnées possibles (haut, droite, bas et gauche)
 *         Chacune des cases correspondent à une coordonnee ( si elles sont différentes de -1)
 *         S'il n'y a pas de coordonnees (-1,-1) le deplacement est possible
 */
Coordonnee *pos_suiv(Problem *p, Coordonnee posActuelle) {
    Coordonnee c, possibles[4];


    /* J'initialise tout le tableau des possibilités à -1 (position suivante inacessible)*/
    for(int i = 0; i < 4; i++) {
        possibles[i].num_ligne = -1;
        possibles[i].num_col = -1;
    }

    // Déplacement en haut
    c.num_ligne = posActuelle.num_ligne,
    c.num_col = (posActuelle.num_col)-1;
    if (obstacle(p, c)) {
        possibles[0] = c;
    }


    // Déplacement à droite
    c.num_ligne = (posActuelle.num_ligne)-1,
    c.num_col = posActuelle.num_col;
    if (obstacle(p, c)) {
        possibles[1] = c;
    }

    // Déplacement en bas
    c.num_ligne = (posActuelle.num_ligne)+1,
    c.num_col = posActuelle.num_col;
    if (obstacle(p, c)) {
        possibles[2] = c;
    }

    // Déplacement à gauche
    c.num_ligne = posActuelle.num_ligne,
    c.num_col = (posActuelle.num_col)+1;
    if (obstacle(p, c)) {
        possibles[3] = c;
    }

    return possibles;
}
