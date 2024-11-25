#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 254

int main() {
    char ligne[TAILLE];
    char **coffres = NULL;
    int nb_coffres = 0;

    while (fgets(ligne, TAILLE, stdin) != NULL) {
        int trouve = 0;

        for (int i = 0; i < nb_coffres; i++) {
            if (strncmp(coffres[i], ligne, 5) == 0) {
                ligne[strlen(ligne)-1]='\0';
                coffres[i] = realloc(coffres[i], (strlen(coffres[i]) + strlen(ligne+5) +1) * sizeof(char));
                if (coffres[i] == NULL) exit(1);
                strcat(coffres[i], ligne+6);
                trouve = 1;
                break;
            }
        }

        if (!trouve) {
            coffres = realloc(coffres, (nb_coffres + 1) * sizeof(char*));
            if (coffres == NULL) exit(1);

            coffres[nb_coffres] = malloc((strlen(ligne) + 1) * sizeof(char));
            if (coffres[nb_coffres] == NULL) exit(1);

            for(int i = 0; i < strlen(ligne)-1; i++) {
                coffres[nb_coffres][i] = ligne[i];
            }
            nb_coffres++;
        }
    }

    for (int i = 0; i < nb_coffres; i++) {
        printf("%s\n", coffres[i]);
        free(coffres[i]); 
    }
    free(coffres); 

    exit(0);
}
