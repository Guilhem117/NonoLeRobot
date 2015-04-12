#include <stdio.h>
#include <stdlib.h>

#include "position.h"
#include "File.h"
#include "Pile.h"


/** Permet d’obtenir le parcours demandé par un probléme à l’aide d’un algorithme de parcours en largeur.
 * \author Salandini Steven
 * \param m, le problème contenant les sommets de départ/de fin et la map->
 * \return chemin la pile contenant les sommets constituants le parcours
 *         null si aucun chemin possible
 */
Pile parcours_largeur(Problem * p);


/**
 * Calcul un chemin qui va de la position de départ à la position d’arrivée
 * \author SERENE Guilhem & PRADEL Jordan
 * \param p, le probleme contenant la carte du labyrinthe (et ses obstacles), la position d’arrivée et la position de départ
 * \return une pile contenant les sommets constituant le parcours
 *                  ou une pile vide si le chemin n’a pas pu être trouvé
 */
Pile parcours_profondeur_R(Problem p, Pile chemin, char *marques);
