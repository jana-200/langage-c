#include <stdlib.h>
#include <stdio.h>

int main(){ 
    int x;
    printf("Entrez un entier dont vous voulez avoir la factorielle : \n");
    scanf("%d", &x);

    int fact=1;
    for(int i=2 ; i <= x ; i++){ 
        fact*=i;
    }
    printf("la factorielle de %d est %.0f\n", x, fact);
}
