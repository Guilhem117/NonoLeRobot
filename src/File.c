#include "File.h"
#include <stdlib.h>

/**
 * Initialise une file
 * @return une file vide
 */
File init_File() {

	File* fileC;
	fileC = (File*) malloc(sizeof(File));
	fileC->teteFile =NULL;
	fileC->queueFile = (chainonF*) malloc(sizeof(chainonF));


	return *fileC;
}

/**
 *Indique si une file est vide
 *@param aTester la file a tester
 *@return 1 si la file est vide
 *        0 sinon
 */
int FileVide(File aTester){
    return (aTester.teteFile==NULL);
}

/**
 *Ajoute un element en queue de la file donnée
 *@param cible un pointeur sur la file a incrémentée
 *       Elem la donnée a stocker
 *@return File la nouvelle file
 */
File AjouterElemF(File* cible, void* Elem){
    chainonF* aAjouter;
	aAjouter = (chainonF*) malloc(sizeof(chainonF));

    aAjouter->nextElement = cible->queueFile;
    aAjouter->nextElement->precElement = aAjouter;
    aAjouter->precElement=NULL;
    aAjouter->valElement=Elem;

    cible->queueFile=aAjouter;
    if(cible->teteFile==NULL){
        cible->teteFile = (chainonF*) malloc(sizeof(chainonF));
        cible->teteFile=aAjouter;
    }
    return *cible;
}

/**
 *Retire un element en tête de la file donnée et retourne sa valeur
 *@param cible un pointeur sur la cible dont on veut la tête
 *@return NULL si la file est vide
 *        la valeur associé au chainon en tête sinon
 */

void* RetirerElemF(File* cible){
    void* aRetourner;
    if(FileVide(*cible)){
	    return NULL;
	}

    chainonF* aRetirer = (cible->teteFile);
    cible->teteFile=aRetirer->precElement;

    //Si la tete n'est pas NULL, rendre le prochain élément de la prochain tête NULL
    //SINON rendre la queue NULL (la file devient vide)
    if(cible->teteFile!=NULL){
        cible->teteFile->nextElement = NULL;
    }else{
        cible->queueFile = NULL;
    }

    aRetourner = aRetirer->valElement;
    //On libère le maillon enlevé
    free(aRetirer);
    return aRetourner;

}

/**
 * Permet de supprimer une file vide
 * @param la file vide a supprimer
 * @return 0 si la file a été supprimer
 *         -1 sinon (file non vide
 */
int supprimerFile(File* aSupprimer){

if(!FileVide(*aSupprimer)){
    return -1;
}

free(aSupprimer);
return 0;
}
