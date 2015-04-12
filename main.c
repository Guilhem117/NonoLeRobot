#include "Algorithme.h"

void lire_fichier(FILE *f, Problem *p);
void Affiche_matrice(Problem *p);
void libere_matrice(Problem *p);
void lire_coordonnee(FILE *f, Coordonnee *c);
void afficher_chemin(Pile p);


int main() {
    FILE* file;
    file = fopen("map.txt", "r" );
    if(file == NULL) {
        printf("\n Erreur ouverture fichier\n");
    } else {
        Problem probleme;
        Pile chemin;
        lire_fichier(file,&probleme);
        Affiche_matrice(&probleme);

        char *marques;
        ajout_elem(&chemin, &probleme.depart);
        marques = (char *) malloc(probleme.nb_colonne * probleme.nb_ligne * sizeof(char));
        chemin = parcours_profondeur_R(probleme, chemin, marques);
        afficher_chemin(chemin);

//        chemin = parcours_profondeur(probleme);
//        afficher_chemin(chemin);

        libere_matrice(&probleme);
    }

    return 0;
}

void lire_fichier(FILE *f, Problem *p) {
    char c;
    fscanf(f,"%s\n",p->nom);
    lire_coordonnee(f,&p->depart);
    lire_coordonnee(f,&p->arrive);
    fscanf(f,"%i\n",&p->nb_ligne);
    fscanf(f,"%i\n",&p->nb_colonne);
    p->carte = (char **) malloc(sizeof(char *)*p->nb_ligne);
    if(p->carte==NULL) {
        printf("\nallocation impossible, pas assez de mémoire\n");
        exit (1);
        }
    else {
        int i;
        for (i = 0; i < p->nb_ligne; i++) {
            p->carte[i] = (char*)malloc(sizeof(char)*p->nb_colonne);
            if (p->carte[i]==NULL) {
                printf("\nallocation impossible, pas assez de mémoire\n");
                exit (1);
                }
            }
        }
    int i;
    for (i = 0; i < p->nb_ligne; i++) {
        int j;
        for(j=0; j< p->nb_colonne; j++) {
            fscanf(f,"%c",&p->carte[i][j]);
            }
        fscanf(f,"%c",&c);  // enlève le \n
        }
    }
void Affiche_matrice(Problem *p) {
    printf("nom du labyrinthe : %s\n", p->nom);
    printf("position de depart : %i;%i\n",p->depart.num_ligne,p->depart.num_col);
    printf("position de arrivee : %i;%i\n",p->arrive.num_ligne,p->arrive.num_col);
    printf("nb_ligne : %i; nb_colonne : %i\n", p->nb_ligne, p->nb_colonne);
    int i;
    for (i = 0; i < p->nb_ligne; i++) {
        //printf("\nligne %i :\n", i);
        int j;
        for (j = 0; j < p->nb_colonne; j++) {
            printf("%c",p->carte[i][j]);
            }
        // printf("f\n");
        }
    }

void lire_coordonnee(FILE *f, Coordonnee *c) {
    fscanf(f,"%i\t%i\n",&c->num_ligne,&c->num_col);
    }

void libere_matrice(Problem *p){
    int i;
    for (i = 0; i < p->nb_ligne; i++) {
       free(p->carte[i]);
    }
    free(p->carte);
}

void afficher_chemin(Pile p) {

    while(!pile_vide(p)) {
        printf(" (%d/%d) -> ",(*(Coordonnee *)p.element).num_ligne,(*(Coordonnee *)p.element).num_col);
        retirer_elem(&p);
    }

}
