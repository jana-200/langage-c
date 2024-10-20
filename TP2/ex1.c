#include <stdlib.h>
#include <stdio.h>

#define MAX 50

int main() {
    float tab[MAX];
    float val;
    int taille = 0;
    float somme = 0;
    int e = 0;

    printf("Entrez les notes des etudiants (Ctrl+Z pour terminer) :\n");
    while (scanf("%f", &val) != EOF && e < MAX) {
        tab[e] = val;
        e++;
        taille++;
        somme += val;
        if (e == MAX)
            break;
    }

    printf("Moyenne = %f \n", somme / e);
    printf("Ecarts des etudiants par rapport à la moyenne : \n");
    for (int i = 0; i < taille; i++) {
        printf(" Etudiant %d: %f - %f = %f\n", i + 1, tab[i], somme / e, tab[i] - (somme / e));
    }

    return 0;
}
