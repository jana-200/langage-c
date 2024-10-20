#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int x = 1;
    int y = 2;
    int *t;
    int z = 5;
    int zz = 6;

    t=0;

    //malloc + vérification ???

    for (int i = 0; i < 10; i++){
        t[i] = i;
    }
    
    printf("x = %d, y = %d, z = %d, zz = %d; t[2] = %d\n", x, y, z, zz, t[2]);

}

