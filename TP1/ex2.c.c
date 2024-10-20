#include <stdio.h>
#include <stdlib.h>


int main() {
    int x,y;
    printf("entre deux nombres entiers que vous voulez multiplier\n");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("les nombres que vous avez entré sont %d et %d\n", x, y);
    printf("aprés l'échange ça donne ...\n");
    printf("les nombres que vous avez entré sont %d et %d\n", y, x);
    return 0;
}
