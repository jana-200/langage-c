#include <stdio.h>
#include <stdlib.h>


int main() {
    int x,y;
    printf("entre deux valeurs que vous voulez multiplier");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("le produit de %d et de %d est %d\n", x, y, x*y);
    return 0;
}
