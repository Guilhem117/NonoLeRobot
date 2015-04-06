typedef struct coordonnee {
    unsigned int num_ligne,num_col;
    } Coordonnee;

typedef struct problem {
    char nom[20];
    Coordonnee arrive, depart;
    int nb_ligne,nb_colonne;
    char **carte;
    } Problem;


/**
 * Renvoie les positions possibles pour le déplacement du robot
 * @author Jordan PRADEL & SERENE G.
 * @param p, Le probleme avec la caractéristique de la carte
 * @param position à tester
 * @return Tableau de 4 coordonnées possibles (haut, droite, bas et gauche)
 *         Chacune des cases correspondent à une coordonnee ( si elles sont différentes de -1)
 *         S'il n'y a pas de coordonnees (-1,-1) le deplacement est possible
 */
Coordonnee *pos_suiv(Problem *p, Coordonnee posActuelle);
