#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>   // utiliser l'option "-lm" pour lier la la librairie mathematique au programme

#define LIMIT 100

int main() 
{
    int nbre;
    bool valid = false;
    int count=0;

    /// Lecture d'un nombre entier positif nbre, strictement inferieur a 100
    while (!valid) {
        printf("Enter a positive integer value inferior to %d: ", LIMIT);
        if (scanf("%d",&nbre) != 1) {
            fprintf(stderr, "Error: invalid data\n");
        }
        else if (nbre < 0 || nbre > LIMIT) {
            fprintf(stderr, "Error: invalid integer value\n");
        } else {
            valid = true;
        }
    }

    /// Calcul des nombres premiers inferieurs a nbre
    bool table[LIMIT] = {false};
    for (int i=2; i<=sqrt(nbre); i++){
        if (!table[i]){
            for (int j=i+i; j<=nbre; j+=i){
                table[j] = true;
                count++;
            }
        }
    }
    printf("there is %d prime numbers.", count);
    // todo later

    printf("Nombres premiers inferieurs a %d: \n",nbre);
    for (int i=2; i<=nbre; i++){
        if (!table[i]){
            printf("%4d", i);
        }
    }
    printf("\n");
}
