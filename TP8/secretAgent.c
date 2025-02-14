#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./ROT13/cryptROT13.h"
#include "./Polybe/cryptPolybe.h"
#include "./Morse/cryptMorse.h"
#include "utils_v1.h" 


// généré avec chatgpt

void menu() {
    printf("\n=== Secret Agent ===\n");
    printf("1. Cryptage\n");
    printf("2. Décryptage\n");
    printf("Entrez votre choix (Ctrl-D pour terminer) : ");
}

void menuCrypto() {
    printf("\nChoisissez un mode de cryptage/décryptage :\n");
    printf("1. ROT13\n");
    printf("2. Polybe\n");
    printf("3. Morse\n");
    printf("Entrez votre choix : ");
}

int main() {
    char *input, *message;
    int mode, choix;

    while (1) {
        menu();
        input = readLine();
        if (input == NULL) break;  // Gestion EOF (Ctrl-D)
        
        mode = atoi(input);  // Convertit en entier
        free(input); 

        if (mode != 1 && mode != 2) {
            printf("Entrée invalide. Réessayez.\n");
            continue;
        }

        menuCrypto();
        input = readLine();
        if (input == NULL) break;

        choix = atoi(input);
        free(input);

        if (choix < 1 || choix > 3) {
            printf("Choix invalide. Réessayez.\n");
            continue;
        }

        printf("Entrez votre message : ");
        message = readLine();
        if (message == NULL) break;  // Gestion EOF (Ctrl-D)

        char* resultat = NULL;
        switch (choix) {
            case 1: // ROT13
                resultat = (mode == 1) ? encrypt(message) : decrypt(message);
                break;
            case 2: // Polybe
                resultat = (mode == 1) ? encryptPolybe(message) : decryptPolybe(message);
                break;
            case 3: // Morse
                resultat = (mode == 1) ? encryptMorse(message) : decryptMorse(message);
                break;
        }

        if (resultat) {
            printf("Résultat : %s\n", resultat);
            free(resultat);
        }
        free(message);
    }

    printf("\nProgramme terminé.\n");
    return 0;
}
