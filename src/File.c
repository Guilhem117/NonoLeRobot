#include <stdlib.h>
//Fichier contenant les outils n�cessaire pour manipuler une File

typedef struct chainonF{

     void* valElement;
     struct chainonF* nextElement;
     struct chainonF* precElement;

}chainonF;

typedef struct File{

    chainonF* teteFile;
    chainonF* queueFile;

}File;

//Indique si une file est vide
int FileVide(File aTester){
    return (aTester.teteFile==NULL);
}

//Ajoute un element en queue de la file donn�e
File AjouterElemF(void* Elem,File cible){
    chainonF aAjouter;
    aAjouter.nextElement=cible.queueFile;
    aAjouter.nextElement.precElement=&(aAjouter);
    aAjouter.precElement=NULL;
    aAjouter.valElement=Elem;

    cible.queueFile=&aAjouter;
    return cible;
}

//retire un element en t�te de la file donn�e et retourne sa valeur
void* RetirerElemF(File* cible){
    chainonF aRetirer = *File.teteFile;
    *cible.teteFile=aRetirer.precElement;
    return aRetirer.valElement;
}
