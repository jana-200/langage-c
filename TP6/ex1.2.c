#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/**
 * PRE : n >= 2
 * POST : sz est égal à la taille (physique et logique) du tableau renvoyé
 * RES : un tableau trié contenant tous les nombres premiers plus petits que n si aucune erreur n’est survenue ; 
 *       NULL si une erreur est survenue
 */
int* prime_numbers (int n, int* sz){
    if(n<2){ 
        *sz=0;
        return NULL;
    }

    int* table= malloc(n*sizeof(int));
    if(table==NULL) return NULL;
    *sz=0;
    bool is_prime=true;
    for(int i=2; i<n ;i++){
        bool is_prime=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){ 
                is_prime=false;
                break;
            }  
        }
        if (is_prime) {
            table[*sz] = i;
            (*sz)++;
        }
    }
    table = realloc(table, (*sz) * sizeof(int));
    if(table==NULL) return NULL;

    return table;
}

int main(){ 
    int n;
    printf("Entrez un nombre : ");
    scanf("%d",&n);
    int sz;
    int* table=prime_numbers(n,&sz);
    if (table != NULL) {
        printf("Voici les nombres premiers avant %d :\n", n);
        for (int i = 0; i < sz; i++) {
            printf("%d ", table[i]);
        }
        printf("\n");

        free(table); 
    } else {
        printf("Erreur lors de la génération des nombres premiers.\n");
    }

    exit(0);

}