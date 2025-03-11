#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "biblio.h"

int main(int argc, char* argv[]){

    struct Livre* bib = NULL;
    int taille = 0;
    struct Livre l;
    int count=0;

    while (1) {
        if(!lireLivre(&l)) count++;
        if (!ajouterLivre(&bib, &taille, l)) {
            free(bib);
            exit(1);
        }
        if(!lireLivre(&l)) count++;
        if (count == 2) break;
        else count = 0;
    }

    printf("Bibliothèque :\n");
    afficherBib(bib, &taille);
    free(bib);
    exit(0);
    
}