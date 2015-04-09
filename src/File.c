//#include "File.h"
//
//#include <stdlib.h>
//
////Fichier contenant les outils nécessaire pour manipuler une File
//File init_File() {
//	File* fileC;
//	fileC = (File*) malloc(sizeof(File));
//	fileC->teteFile = NULL;
//	fileC->queueFile = NULL;
//
//	return *fileC;
//}
//
////Indique si une file est vide
//int FileVide(File aTester){
//    return (aTester.teteFile==NULL);
//}
//
////Ajoute un element en queue de la file donnée
//File AjouterElemF(File* cible,void* cible) {
//    chainonF* aAjouter;
//	aAjouter = (chainonF*) malloc(sizeof(chainonF));
//    aAjouter->nextElement=(cible.queueFile);
//    aAjouter->nextElement.precElement=&aAjouter;
//    aAjouter->precElement=NULL;
//    aAjouter->valElement=Elem;
//
//    *cible->queueFile=*aAjouter;
//    return *cible;
//}
//
////retire un element en tête de la file donnée et retourne sa valeur
//void* RetirerElemF(File* cible){
//
//    if(FileVide(*cible)){
//	    return NULL;
//	}
//
//    chainonF aRetirer = *(cible->teteFile);
//    cible->teteFile=aRetirer.precElement;
//    return aRetirer.valElement;
//}
