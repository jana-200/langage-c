#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int x = 1;
    int y = 2;
    int t[2] = {3,4};
    int z = 5;
    int zz = 6;
    
    printf("x = %d, y = %d, z = %d, zz = %d; t[2] = %d\n", x, y, z, zz, t[2]);

    // t[2] n'existe pas, car le tableau "t" a une taille de 2, donc les indices valides sont t[0] et t[1].
    // Accéder à t[2] dépasse les limites du tableau, ce qui provoque un comportement indéfini.
    // Cela peut retourner n'importe quelle valeur présente en mémoire à cet emplacement, 
    // mais cette valeur ne sera pas forcément liée aux variables x, y, z ou zz.
}

