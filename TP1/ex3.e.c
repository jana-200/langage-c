#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(){ 
    int x;
    printf("Entrez un entier dont vous voulez avoir al factorielle : \n");
    scanf("%d", &x);

    int fact=1;
    int i=2;
    while( i <= x){ 
        if(fact> INT_MAX/i){
            printf("Error : integer overflow\n");
            exit(EXIT_FAILURE);
        }
        fact*=i;
        i++;
    }
    printf("la factorielle de %d est %d\n", x, fact);
    exit(EXIT_SUCCESS);
}
