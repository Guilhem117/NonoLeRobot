#include <stdlib.h>
#include "Pile.h"

/** Fonction qui intialise une pile
 * @return une pile avec un element null
 */
Pile init_pile() {

    Pile * pile;

    pile = (Pile*) malloc(sizeof(pile));

    pile->element = NULL; //TODO a revoir

    pile->suivant = NULL; //TODO a revoir

    return *pile;
}

/** Permet d'ajouter un element à une pile
 * ATTENTION, INTERDIT d'ajouter NULL
 * @param p, la pile à ajouter l'element
 * @param element à ajouter
 */
void ajout_elem(Pile p, void * element) {

    Pile * aAjouter;

    /* On ne peut pas ajouter l'element null */
    if (element == NULL) {
        return;
    }

    //Je rempli l'element actuel qui est null
    if (pile_vide(p)) {
        p.element = element;

    //J'ajoute un autre element
    } else {

        aAjouter = (Pile *) malloc(sizeof(Pile));

        aAjouter->element = element;
        aAjouter->suivant = &p;

    }

}

/** Permet de retirer un element de la pile
 * On ne peut pas enlever un element si c'est
 * @param  la pile où il faut enlever le sommet
 * @return element qui a été dépilé
 *         NULL l'element à depiler
 */
void * retirer_elem(Pile p) {

    void * sommet;
    sommet = p.element;

    //C'est le dernier element de la pile, donc je supprime que l'element
    if (p.suivant == NULL) {
        p.element = NULL;
    } else {//Sinon, je supprime l'element suivant aussi
        p.suivant = p.suivant->suivant;
        p.element = p.suivant->element;
    }


    return sommet;
}

/** Renvoit le sommet de la pile
 * @param p, la pile contenant l'element
 * @return l'element du sommet de la pile
 *         NULL si l'element est le dernier de ma pile
 */
void * sommet(Pile p) {
    return p.element;
}

/** Permet d'inverser la pile le fond de la pile devient la tete
 * @param p, la pile à inverser
 * @return la pile inversée
 *         si elle est vide, NULL est renvoyé
 */
Pile * inverser(Pile p) {

    Pile * inverse;

    if (pile_vide(p)) {
        return NULL;
    }

    inverse = (Pile *) malloc(sizeof(p));

    while (!pile_vide(p)) {

        ajout_elem(*inverse, p.element);

        retirer_elem(p);

    }

    return inverse;

}

/** Connaitre la taille d'une pile
 * @param  p, la pile à calculer
 * @return La taille de la pile
 *         0 si la pile est vide
 */
int taille_pile(Pile p) {

    int taille;

    taille = 0;
    while (p.suivant != NULL) {
        taille++;
        p = *(p.suivant);
    }

    //Le dernier element != null, il contient un element spupplémentaire!
    if (p.element != NULL) {
        taille++;
    }

    return taille;

}

/** Permet de tester si la pile est vide
 * @param p, la pile à tester
 * @return 1 si la pile est vide
 *         0 si la pile n'est pas vide
 */
int pile_vide(Pile p) {
    return (p.element == NULL);
}
