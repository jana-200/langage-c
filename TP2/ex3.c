#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c;
    printf("Entrez le nombre de lignes et de colonnes:\n");
    scanf("%d %d", &l, &c);

    char tableLignes[10][10]; // ça ne marche pas si on met l et c
    char tableLignes2[10][10];

    char ch = 'A';
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            tableLignes[i][j] = ch;
            ch++;
            if (ch > 'Z')
                ch = 'A'; // retour à A
        }
    }

    ch = 'A'; // on remet ch à A pour recommencer mais en colonne cette fois
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < l; j++) {
            tableLignes2[i][j] = ch + (int)(rand()/(RAND_MAX+1.0)*('Z'-'A'+1));
        }
    }

    printf("\nCaractères identiques aux mêmes positions:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (tableLignes[i][j] == tableLignes2[i][j]) {
                printf("%c en ligne %d et colonne %d\n", tableLignes[i][j], i, j);
            }
        }
    }

    return 0;
}
