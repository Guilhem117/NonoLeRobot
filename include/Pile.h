

typedef struct Pile {
    void * element;
    struct Pile * suivant;
} Pile;

/** Fonction qui intialise une pile
 * \return une pile avec un element null
 */
Pile init_pile();

/** Permet d'ajouter un element à une pile
 * ATTENTION, INTERDIT d'ajouter NULL
 * \param p, la pile à ajouter l'element
 * \param element à ajouter
 * \author Guilhem SERENE & Jordan PRADEL
 */
void ajout_elem(Pile* p, void * element);

/** Permet de retirer un element de la pile
 * Si la pile est vide, rien ne change
 * \param  la pile où il faut enlever le sommet
 * \author Guilhem SERENE & Jordan PRADEL
 */
void retirer_elem(Pile * p);

/** Permet d'inverser la pile le fond de la pile devient la tete
 * \param p, la pile à inverser
 * \return la pile inversée
 *         si elle est vide, NULL est renvoyé
 */
Pile * inverse(Pile p);

/** Connaitre la taille d'une pile
 * \param  p, la pile à calculer
 * \return La taille de la pile
 *         0 si la pile est vide
 */
int taille_pile(Pile p);

/** Permet de tester si la pile est vide
 * \param p, la pile à tester
 * \return 1 si la pile est vide
 *         0 si la pile n'est pas vide
 */
int pile_vide(Pile p);

/**
 * Affiche les éléments d'une Pile
 * \author Jordan PRADEL
 */
void afficher_pile_entiers(Pile * p);

/**
 * Affiche les éléments d'une Pile de Coordonnées
 * \author Jordan PRADEL
 */
void afficher_pile_coordonnees(Pile * p);

/**
 * Tests des fonctions d'initialisation, d'ajout, d'affichage et de retrait
 * \author Jordan PRADEL & Guilhem SERENE
 */
void testPile();
