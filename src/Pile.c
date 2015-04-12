#include <stdlib.h>
#include <stdio.h>
#include "Pile.h"

/** Fonction qui intialise une pile
 * @return une pile avec un element null
 * @author Guilhem SERENE
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
 * @author Guilhem SERENE & Jordan PRADEL
 */
void ajout_elem(Pile* p, void * element) {

    /* Controle de validité du paramètre element */
    if (element == NULL) {
        return;
    }

    // Si la pile est vide, le premier élément prend la valeur du paramètre élément
    if (pile_vide(*p)) {
        p->element = element;

    // Sinon on créé une nouvelle pile copie de la pile actuelle,
    // l'élément de la pile actuelle prend la valeur du paramètre élément
    // et la pile copie vient s'insérer en dessous de la pile actuelle.
    } else {

        Pile * aAjouter;
        aAjouter = (Pile *)malloc(sizeof(Pile)); // Allocation d'espace mémoire
        if (aAjouter == NULL) {
            exit(1);
        }
        aAjouter->element = p->element; // Copie de
        aAjouter->suivant = p->suivant; // la pile actuelle
        p->element = element; // l'élément de la pile actuelle prend la valeur du paramètre élément
        p->suivant = aAjouter; // on insère la pile copie en dessous de la pile actuelle

    }

}

/** Permet de retirer un element de la pile
 * Si la pile est vide, rien ne change
 * @param  la pile où il faut enlever le sommet
 * @author Guilhem SERENE & Jordan PRADEL
 */
void retirer_elem(Pile * p) {

    // Si l'élément à retirer est le derneir de la liste, on le met à null
    if (p->suivant == NULL) {
        p->element = NULL;
    } else {//Sinon on le remplace par l'élément suivant


        p->element = p->suivant->element;
        p->suivant = p->suivant->suivant;

    }

}

/** Permet d'inverser la pile le fond de la pile devient la tete
 * @param p, la pile à inverser
 * @return la pile inversée
 *         si elle est vide, NULL est renvoyé
 * @author Guilhem SERENE
 */
Pile * inverser(Pile p) {

    Pile * inverse;

    if (pile_vide(p)) {
        return NULL;
    }

    inverse = (Pile *) malloc(sizeof(p));

    while (!pile_vide(p)) {

        ajout_elem(inverse, p.element);
        retirer_elem(&p);

    }

    return inverse;

}

/** Connaitre la taille d'une pile
 * @param  p, la pile à calculer
 * @return La taille de la pile
 *         0 si la pile est vide
 * @author Guilhem SERENE
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
 * @author Guilhem SERENE
 */
int pile_vide(Pile p) {
    return (p.element == NULL);
}

/**
 * Affiche les éléments d'une Pile
 * @author Jordan PRADEL
 */
void afficherPileEntiers(Pile * p) {
    Pile * temp; // Pile temporaire
    temp = (Pile *)malloc(sizeof(Pile)); // Allocation d'espace mémoire
    // On copie les données de la Pile p dans la Pile temp
    temp->element = p->element;
    temp->suivant = p->suivant;

    // On dépile jusqu'au dernier élément de la Pile
    while (temp->suivant != NULL) {
        if (temp->suivant->element == NULL) {
            return;
        }
        printf("%d\n", *(int*)temp->element);
        // Passage à l'élément suivant
        temp->element = temp->suivant->element;
        temp->suivant = temp->suivant->suivant;
    }
    // On n'oublie pas d'afficher le dernier élément
    printf("%d\n", *(int*)temp->element);
    free(temp); // On libère l'espace mémoire utilisé par temp
}

/**
 * Tests des fonctions d'initialisation, d'ajout, d'affichage et de retrait
 * @author Jordan PRADEL & Guilhem SERENE
 */
void testPile() {

    Pile p;
    int i=7, j=8, x=9, l=10, y=11;
    p = init_pile();
    ajout_elem(&p, &i);
    ajout_elem(&p, &j);
    ajout_elem(&p, &x);
    ajout_elem(&p, &l);
    ajout_elem(&p, &y);
    afficherPileEntiers(&p);
    retirer_elem(&p);
    printf("\n");
    afficherPileEntiers(&p);
    retirer_elem(&p);
    printf("\n");
    afficherPileEntiers(&p);
    retirer_elem(&p);
    printf("\n");
    afficherPileEntiers(&p);
    retirer_elem(&p);
    printf("\n");
    afficherPileEntiers(&p);
    retirer_elem(&p);
    printf("\n");
    afficherPileEntiers(&p);
}
