#include <stdlib.h>


typedef struct Pile {
    void * element;
    struct Pile * suivant;
} Pile;

/** Fonction qui intialise une pile
 * @return une pile avec un element null
 */
Pile init_pile();

/** Permet d'ajouter un element � une pile
 * ATTENTION, INTERDIT d'ajouter NULL
 * @param p, la pile � ajouter l'element
 * @param element � ajouter
 */
void ajout_elem(Pile p, void * element);


/** Permet de retirer un element de la pile
 * On ne peut pas enlever un element si c'est
 * @param  la pile o� il faut enlever le sommet
 * @return element qui a �t� d�pil�
 *         NULL l'element � depiler
 */
void * retirer_elem(Pile p);

/** Renvoit le sommet de la pile
 * @param p, la pile contenant l'element
 * @return l'element du sommet de la pile
 *         NULL si l'element est le dernier de ma pile
 */
void * sommet(Pile p);

/** Permet d'inverser la pile le fond de la pile devient la tete
 * @param p, la pile � inverser
 * @return la pile invers�e
 *         si elle est vide, NULL est renvoy�
 */
Pile * inverser(Pile p);

/** Connaitre la taille d'une pile
 * @param  p, la pile � calculer
 * @return La taille de la pile
 *         0 si la pile est vide
 */
int taille_pile(Pile p);

/** Permet de tester si la pile est vide
 * @param p, la pile � tester
 * @return 1 si la pile est vide
 *         0 si la pile n'est pas vide
 */
int pile_vide(Pile p);
