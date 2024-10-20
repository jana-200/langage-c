#include <stdlib.h>
#include <stdio.h>

int main() {
    int x;
    printf("entrez un entier\n");
    scanf("%d", &x);
    if (x < 0)
        printf("L'entier ne peut être inférieur à zéro\n");
    else {
        for (int i = 2; i <= x / 2; i++) {
            if (x % i == 0)
                printf("%d ", i);
        }
        printf("\n");
    }
}
