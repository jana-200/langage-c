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

    int freqs[10][26] = {0};

    for(int i=0; i < l; i++){ 
        for (int j= 0; j < c; j++){
            freqs[i][tableLignes[i][j]-'A']++;
        }
    }

    printf("\n          ");
    for(char c = 'A' ; c <= 'Z' ; c++){ 
        printf(" %c ", c);
    }
    printf("\n");
    for (int i = 0; i < l; i++){
        printf("Ligne %d : ", i+1);
        for (int j = 0; j < 26; j++){
            printf(" %d ", freqs[i][j]);
        }
        printf("\n");
    }
    

    ch = 'A'; // on remet ch à A pour recommencer mais en colonne cette fois
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < l; j++) {
            tableLignes2[i][j] = ch + (int)(rand()/(RAND_MAX+1.0)*('Z'-'A'+1));
        }
    }

    int freqs2[10][26] = {0};

    for(int i=0; i < l; i++){ 
        for (int j= 0; j < c; j++){
            freqs2[i][tableLignes2[i][j]-'A']++;
        }
    }

    printf("\n          ");
    for(char c='A' ; c<='Z' ; c++){ 
        printf(" %c ", c);
    }
    printf("\n");
    for (int i = 0; i < l; i++){
        printf("Ligne %d : ", i+1);
        for (int j = 0; j < 26; j++){
            printf(" %d ", freqs2[i][j]);
        }
        printf("\n");
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
