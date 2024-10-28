#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int choix;
    int lignes;
    int colonnes;
    int **image;
    while (1) {
        printf("Menu des opérations sur les images :\n");
        printf("1) Création d'une image avec des valeurs aléatoires\n");
        printf("2) Création d'une image avec des valeurs prédéfinies\n");
        printf("3) Affichage de l'image\n");
        printf("4) Changement de la taille de l'image\n");
        printf("5) Affichage de l'histogramme de l'image\n");
        printf("6) Suppression de l'image\n");
        printf("7) Quitter le programme\n");
        printf("Entrez vontre choix : ");
        
        scanf("%d", &choix);
        if( choix == 1){ 
            printf("Entrez les dimensions de l'image (nbr de lignes puis de colonnes) : ");
            scanf("%d%d",&lignes ,&colonnes);
            int profondeur;
            printf("Entrez la profondeur de bits de l'image : ");
            scanf("%d", &profondeur);

            int max_valeur_pixel = (1 << profondeur) - 1;

            image = (int **)malloc(lignes * sizeof(int *)); // Réservation pour les lignes
            for (int i = 0; i < lignes; i++) {
                 image[i] = (int *)malloc(colonnes * sizeof(int)); // Réservation pour les colonnes
            }

            for (int i = 0; i < lignes; i++) {
                for (int j = 0; j < colonnes; j++) {
                    image[i][j] = rand() % (max_valeur_pixel + 1); // Valeur aléatoire entre 0 et max_valeur_pixel
                }
            }

        }
        if( choix == 2){ 
            printf("Entrez les dimensions de l'image (nbr de lignes puis de colonnes) : ");
            scanf("%d%d",&lignes ,&colonnes);
            int profondeur;
            printf("Entrez la profondeur de bits de l'image : ");
            scanf("%d", &profondeur);

            int max_valeur_pixel = (1 << profondeur)-1;

            if (lignes > max_valeur_pixel + 1) {
                printf("Le nombre de lignes ne peut pas dépasser %d. ou alors  vous devez augmenter la profondeur de bits de l'image\n", max_valeur_pixel + 1);
                continue;
            }

            image = (int **)malloc(lignes * sizeof(int *)); // Réservation pour les lignes
            for (int i = 0; i < lignes; i++) {
                 image[i] = (int *)malloc(colonnes * sizeof(int)); // Réservation pour les colonnes
            }

            for (int i = 0; i < lignes; i++) {
                for (int j = 0; j < colonnes; j++) {
                    image[i][j] = i+1;  
                }
            }
        }
        if( choix == 3){ 
            for (int i = 0; i < lignes; i++) {
                for (int *ptr = image[i]; ptr < image[i] + colonnes; ptr++) {
                    printf("%d ", *ptr); 
                }
                printf("\n");
            }
        }
        if( choix == 4){ 

        }
        if( choix == 5){ 

        }
        if( choix == 6){ 

        }
        if( choix == 7){ 
            free(image);
            exit(0);
        }
        else{ 
            printf("Vous devez choisir un nombre entre 1 et 7\n");
            continue;
        }

    }

    exit(0);
}


