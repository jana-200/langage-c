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

int main(){
    int n;

    printf("enter a number : ");
    if(isPrime(n)) printf("%d is a prime", n);
    else printf("%d is not a prime", n);

    exit(0);
    
}