typedef struct coordonnee {
    unsigned int num_ligne,num_col;
    } Coordonnee;

typedef struct problem {
    char nom[20];
    Coordonnee arrive, depart;
    int nb_ligne,nb_colonne;
    char **carte;
    } Problem;
