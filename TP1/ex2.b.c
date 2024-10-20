#include <stdio.h>
#include <stdlib.h>


int main() {
    float x,y;
    printf("entre deux nombres réels que vous voulez multiplier");
    scanf("%f", &x);
    scanf("%f", &y);
    printf("le produit de %f et de %f est %f\n", x, y, x*y);
    return 0;
}
