
//Fichier contenant les outils nécessaire pour manipuler une File
typedef struct chainonF{

     void* valElement;
     struct chainonF* nextElement;
     struct chainonF* precElement;

}chainonF;

typedef struct File{

    chainonF* teteFile;
    chainonF* queueFile;

}File;

File init_File();

//Indique si une file est vide
int FileVide(File aTester);

//Ajoute un element en queue de la file donnée
File AjouterElemF(File* cible, void* Elem);

//retire un element en tête de la file donnée et retourne sa valeur
void* RetirerElemF(File* cible);
