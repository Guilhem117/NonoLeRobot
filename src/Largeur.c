 /**
    *Permet d’obtenir le parcours demandé par un probléme à l’aide d’un algorythme de parcours en largeur.
    *@author Salandini Steven
    *@param m, le problème contenant le sommet de dép/de fin et la map.
    *@return P la pile contenant les sommet constituants le parcours


Pile RechercheLarg(Struct propleme m){

    Pile P;
    Struct File F;
    int marques[m.nbLignes*m.nbColonnes];
    int i;
    int suivants[]
    void* u;
    P = créerPile();
    AjouterElemF(F,s);
    AjouterElemP(P,s);
    while(FileVide(F)){
        v = RetirerElemF(F);
        if( v = m.sommetfin){
            return P;
        }
        suivants =  pos_suiv(M,V)
        int DegreExt=0;
        for(i=0;i<4;i++){
            u = pos_suiv(m,v) +i;
            numU = NumSommet(M,u);
            if(!Marque[numU] && posSuivante[numU-1]==0 ){
                DegreExt++;
                Marque[numU] = vrai;
                AjouterElemF(F,u);
                AjouterElemP(P,u);
            }
        }

        if(DegreExt == 0 || toutMarque(M,v,Marque){
        RetirerElem(P);
        }
    }
}
*/
