#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define TAILLE 254

int main(){ 
    char** coffres;
    int nbCoffres=0;
    char ligne[TAILLE];

    while(fgets(ligne,TAILLE, stdin)!=NULL){ 
        int trouve=0;
        ligne[strlen(ligne)-1]='\0';

        coffres=(char**)malloc(nbCoffres*sizeof(char*));
        if(coffres==NULL) exit(1);

        for(int i=0; i<nbCoffres;i++){ 
            if(strncmp(coffres[i], ligne,5)==0){ 
                coffres[i]=(char*)realloc(coffres[i],(strlen(coffres[i])+strlen(ligne+5)+1)*sizeof(char));
                if(coffres[i]==NULL) exit(1);
                strcat(coffres[i], ligne+5);
                trouve=1;
                break;
            }
        }

        if(trouve==0){ 
            coffres=(char**)realloc(coffres,nbCoffres*sizeof(char*));
            if(coffres==NULL) exit(1);

            coffres[nbCoffres]=(char*)malloc((strlen(ligne)+1)*sizeof(char));
            if(coffres[nbCoffres]==NULL) exit(1);

            for(int i = 0; i < strlen(ligne)-1; i++) {
                coffres[nbCoffres][i] = ligne[i];
            }
            nbCoffres++;
        }

        trouve=0;

    }

    for(int i=0;i<nbCoffres;i++){
        printf("%s\n", coffres[i]);
        free(coffres[i]); 
    }
    free(coffres);
    exit(0);
}