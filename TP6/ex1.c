#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/**
 * PRE : n : nombre entier positif
 * RES : vrai si n est premier ; faux sinon
 */

bool isPrime(int n){
    if(n<2) return false;
    for(int i=2; i<n;i++){
        if(n%i==0)return false;
    }
    return true;
}


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

/**
 * PRE : t : tableau de longueur sz
 * POST : t représente un tableau trié contenant les sz premiers nombres premiers.
 * RES : vrai en cas de succès ; faux sinon
 */
bool first_prime_numbers (int* t, int sz){

    int n = 2;
    int szr;
    int* pn = prime_numbers(n, &szr);
    while (szr < sz) {
        n = n * 2;
        pn = prime_numbers(n, &szr);
        if (!pn) return false; 
    }
    for(int i=0;i<sz;i++){
        t[i]=pn[i];
    }
    free(pn);
    return true;

}


int main() {
    int n;
    //1.1
    printf("Entrez un nombre pour vérifier s'il est premier : ");
    scanf("%d", &n);

    if (isPrime(n)) {
        printf("%d est un nombre premier.\n", n);
    } else {
        printf("%d n'est pas un nombre premier.\n", n);
    }

    //1.2
    printf("\nCombien de chiffres premiers voulez vous faire afficher ? ");
    scanf("%d", &n);

    int sz;
    int* primes = prime_numbers(n, &sz);
    if (primes != NULL) {
        printf("Nombres premiers inférieurs à %d : ", n);
        for (int i = 0; i < sz; i++) {
            printf("%d ", primes[i]);
        }
        printf("\n");
        free(primes);  
    } else {
        printf("Erreur lors de la génération des nombres premiers.\n");
    }

    //1.3
    printf("\nEntrez le nombre de nombres premiers que vous souhaitez : ");
    scanf("%d", &n);

    int* first_primes = malloc(n * sizeof(int));
    if (first_primes != NULL && first_prime_numbers(first_primes, n)) {
        printf("Les %d premiers nombres premiers sont : ", n);
        for (int i = 0; i < n; i++) {
            printf("%d ", first_primes[i]);
        }
        printf("\n");
        free(first_primes);  
    } else {
        printf("Erreur lors de la génération des premiers nombres premiers.\n");
        if (first_primes) free(first_primes);
    }

    return 0;
    
}