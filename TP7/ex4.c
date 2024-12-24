
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** copierArgs (char** tab, int n, int* ncp);
void trier (char** tab, int n);
void afficher (char** tab, int n);


int main (int argc, char* argv[]) {
   int ncp;
   char** tab=copierArgs(argv+1,argc-1,&ncp);


   printf("affichage du tableau avant le tri : \n");
   afficher(tab,ncp);
   
   trier(tab,ncp);

   printf("affichage du tableau aprés le tri : \n");
   afficher(tab,ncp);


   for(int i=0;i<ncp; i++){
       free(tab[i]);
   }
   free(tab);

   exit(0);

}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: *ncp: nombre de chaînes dans le tableau renvoyé
 * RES: renvoie un tableau contenant les chaînes de tab sans doublon
 *      (taille logique = taille physique); NULL si une erreur s'est produite
 */
char** copierArgs (char** tab, int n, int* ncp) {
    char** ret= (char**)malloc(n*sizeof(char*));
    if(ret==NULL) exit(1);
    int retSize=0;

    bool trouve=false;

    for(int i=0 ; i<n; i++){
        for(int j=0; j<retSize;j++){
            if(strcmp(tab[i],ret[j])==0){
                trouve=true;
                break;
            }
        }

        if(!trouve){
            int taille= strlen(tab[i]);
            ret[retSize]=(char*)malloc((taille+1)*sizeof(char));
            if(ret[retSize]==NULL) exit(1);
            strcpy(ret[retSize], tab[i]);
            retSize++;
        }
        trouve=false;

    }


    ret=(char**)realloc(ret,retSize*sizeof(char*));
    if(ret==NULL) exit(1);
    *ncp=retSize;
    return ret;

}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: les n chaînes de tab sont triées par ordre alphabétique
 *       (algorithme: tri par sélection)
 */
void trier (char** tab, int n) {

   int minIndex=0 ;

   for(int i=0 ; i<n-2 ; i++){
       minIndex=i;
       for(int j=i+1; j<n; j++){
           if(strcmp(tab[j],tab[minIndex])<0) minIndex=j;
       }
       if(minIndex!=i){
           char* temp=tab[i];
           tab[i]=tab[minIndex];
           tab[minIndex]=temp;

       }
   }


}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: affiche les chaînes de tab (à raison d'une par ligne,
 *       précédée par leur numéro)
 */
void afficher (char** tab, int n) {

   for(int i=0; i<n ; i++){
       printf("%d . %s\n",i+1, tab[i]);
   }
}
