#include <stdlib.h>
#include <stdio.h>
#include "Pile.h"
#include "position.h"

/** Fonction qui intialise une pile
 * \return une pile avec un element null
 * \author Guilhem SERENE
 */
Pile init_pile() {

    Pile pile;

    pile.element = NULL; //TODO a revoir

    pile.suivant = NULL; //TODO a revoir

    return pile;
}

/** Permet d'ajouter un element � une pile
 * ATTENTION, INTERDIT d'ajouter NULL
 * \param p, la pile � ajouter l'element
 * \param element � ajouter
 * \author Guilhem SERENE & Jordan PRADEL
 */
void ajout_elem(Pile* p, void * element) {

    /* Controle de validit� du param�tre element */
    if (element == NULL) {
        return;
    }

    // Si la pile est vide, le premier �l�ment prend la valeur du param�tre �l�ment
    if (pile_vide(*p)) {
        p->element = element;

    // Sinon on cr�� une nouvelle pile copie de la pile actuelle,
    // l'�l�ment de la pile actuelle prend la valeur du param�tre �l�ment
    // et la pile copie vient s'ins�rer en dessous de la pile actuelle.
    } else {

        Pile * aAjouter;
        aAjouter = (Pile *)malloc(sizeof(Pile)); // Allocation d'espace m�moire
        if (aAjouter == NULL) {
            exit(1);
        }
        aAjouter->element = p->element; // Copie de
        aAjouter->suivant = p->suivant; // la pile actuelle
        p->element = element; // l'�l�ment de la pile actuelle prend la valeur du param�tre �l�ment
        p->suivant = aAjouter; // on ins�re la pile copie en dessous de la pile actuelle
    //printf("(%d;%d)\n", ((Coordonnee*)aAjouter->element)->num_ligne, ((Coordonnee*)aAjouter->element)->num_col);
    }

}

/** Permet de retirer un element de la pile
 * Si la pile est vide, rien ne change
 * \param  la pile o� il faut enlever le sommet
 * \author Guilhem SERENE & Jordan PRADEL
 */
void retirer_elem(Pile * p) {

    // Si l'�l�ment � retirer est le derneir de la liste, on le met � null
    if (p->suivant == NULL) {
        p->element = NULL;
    } else {//Sinon on le remplace par l'�l�ment suivant


        p->element = p->suivant->element;
        p->suivant = p->suivant->suivant;

    }

}

/** Permet d'inverser la pile le fond de la pile devient la tete
 * \param p, la pile � inverser
 * \return la pile invers�e
 *         si elle est vide, NULL est renvoy�
 * \author Guilhem SERENE
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
 * \param  p, la pile � calculer
 * \return La taille de la pile
 *         0 si la pile est vide
 * \author Guilhem SERENE
 */
int taille_pile(Pile p) {

    int taille;

    taille = 0;
    while (p.suivant != NULL) {
        taille++;
        p = *(p.suivant);
    }

    //Le dernier element != null, il contient un element spuppl�mentaire!
    if (p.element != NULL) {
        taille++;
    }

    return taille;

}

/** Permet de tester si la pile est vide
 * \param p, la pile � tester
 * \return 1 si la pile est vide
 *         0 si la pile n'est pas vide
 * \author Guilhem SERENE
 */
int pile_vide(Pile p) {
    return (p.element == NULL);
}

/**
 * Affiche les �l�ments d'une Pile de Coordonn�es
 * \author Jordan PRADEL
 */
void afficher_pile_coordonnees(Pile * p) {
    if (p->element == NULL) {
        return;
    }
    Pile * temp; // Pile temporaire
    temp = (Pile *)malloc(sizeof(Pile)); // Allocation d'espace m�moire
    // On copie les donn�es de la Pile p dans la Pile temp
    temp->element = p->element;
    temp->suivant = p->suivant;

    // On d�pile jusqu'au dernier �l�ment de la Pile
    while (temp->suivant != NULL) {
        if (temp->suivant->element == NULL) {
            return;
        }
        printf("(%d;%d)\n", ((Coordonnee*)temp->element)->num_ligne, ((Coordonnee*)temp->element)->num_col);
        // Passage � l'�l�ment suivant
        temp->element = temp->suivant->element;
        temp->suivant = temp->suivant->suivant;
    }

    // On n'oublie pas d'afficher le dernier �l�ment
    printf("(%d;%d)\n", ((Coordonnee*)temp->element)->num_ligne, ((Coordonnee*)temp->element)->num_col);
}

/**
 * Affiche les �l�ments d'une Pile d'entiers
 * \author Jordan PRADEL
 */
void afficher_pile_entiers(Pile * p) {
    Pile * temp; // Pile temporaire
    temp = (Pile *)malloc(sizeof(Pile)); // Allocation d'espace m�moire
    // On copie les donn�es de la Pile p dans la Pile temp
    temp->element = p->element;
    temp->suivant = p->suivant;

    // On d�pile jusqu'au dernier �l�ment de la Pile
    while (temp->suivant != NULL) {
        if (temp->suivant->element == NULL) {
            return;
        }
        printf("(%d;%d)\n", *(int*)temp->element, *(int*)temp->element);
        // Passage � l'�l�ment suivant
        temp->element = temp->suivant->element;
        temp->suivant = temp->suivant->suivant;
    }
    // On n'oublie pas d'afficher le dernier �l�ment
    printf("(%d;%d)\n", *(int*)temp->element, *(int*)temp->element);
    free(temp); // On lib�re l'espace m�moire utilis� par temp
}
