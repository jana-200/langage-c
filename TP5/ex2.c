#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 27

int main(int argc, char *argv[]){

    for(int i=1; i<argc; i++){
        printf("%d . %s\n",i, argv[i]);
    }

    int absent_count=0;
    char ligne[TAILLE];

    printf("\nEntrez un mot (ou CTRL-D pour arrêter): " );
    while(fgets(ligne, TAILLE, stdin)!=NULL){

        
        ligne[strlen(ligne)-1] = '\0'; // pr retrier \n si y'en a
        printf("\nle mot lu est %s (longueur = %ld) et il est ... ", ligne, strlen(ligne));

        int present=0;
        for(int i=1; i<argc; i++){
            if(strcmp(argv[i], ligne)==0){
                present=1;
                break;
            }
        }
        if(present==0){ 
            printf("absent\n");
            absent_count++;
        }
        else{ 
            printf("présent !!! \n");
        }

        printf("\nEntrez un mot (ou CTRL-D pour arrêter): " );
        
    }

    printf("\nLe programme prend fin.\nIl ya eu %d mots absents\n\n", absent_count);
    exit(0);
}
