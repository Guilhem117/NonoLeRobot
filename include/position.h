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

/** Verifie si la position actuelle n'a pas obstacle
 * @author Jordan PRADEL & SERENE G.
 * @param p, Le probleme avec la caractéristique de la carte
 * @param position à tester
 * @return 1 Si la position contient un obstacle ou n'est pas accessible
 *         0 sinon
 */
int obstacle(Problem *p, Coordonnee * position);


/** Intialise un tableau avec que des zeros
 * @param nb_lignes - Nombre de lignes
 * @param nb_colonnes - Nombre de colonnes
 * @return un tableau rempli de 0
 */
char * init_tableau_booleen(int nb_lignes, int nb_colonnes);

/** Affiche les deplacements du robot et marque une position
 * @param p - La carte du probleme
 * @param deplacement - Le tableau representant les endroits
 */
void affiche_marque(Problem p, char **deplacement);
