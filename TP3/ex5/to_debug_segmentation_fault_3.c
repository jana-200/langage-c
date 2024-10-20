#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int x = 1;
    int y = 2;
    double *t;
    int t2[10];
    int z = 5;
    int zz = 6;

    t = (double *)t2;

    // Problème : "t2" est un tableau d'entiers (int), et "t" est un pointeur vers des doubles.
    // La conversion de pointeur de "int" vers "double" est dangereuse parce que les tailles diffèrent : 
    // "int" occupe 4 octets (en général) et "double" 8 octets.
    // Cela signifie que l'accès à "t[i]" pourrait dépasser les limites de "t2" ou interpréter les données incorrectement.

    for (int i = 0; i < 10; i++){
        t[i] = i;
    }
    
    printf("x = %d, y = %d, z = %d, zz = %d; t[2] = %d\n", x, y, z, zz, t[2]);

}

