#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int h,l;
    printf("Hauteur = ");
    scanf("%d", &h);
    printf("Largeur = ");
    scanf("%d", &l);

    char **m=(char**)malloc(h * sizeof(char*));
    
    if (m == NULL) exit(1);
    
    for (int i = 0; i < h; i++) {
        m[i] = (char*) malloc(l * sizeof(char));
        if (m[i] == NULL) exit(1);
    }


    for (int i = 0; i < h; i++){
      for (int j = 0; j < l; j++){
        m[i][j]='.';
      }  
    }
    

    int colonne;
    int yes=0;
    char joueur='X';

    do{
        printf("Colonne joueur %c ?", joueur);
        scanf("%d", &colonne);

        if (colonne > 0 && colonne-1 < l) {
            for (int i = h - 1; i >= 0; i--) {
                if (m[i][colonne-1] == '.') {
                    m[i][colonne-1] = joueur;
                    yes=1;
                    break;
                }
            }
            if(yes==0){ 
               printf("toute la colonne est remplie veuillez chooisir une autre colonne :");
               continue;
            } 
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < l; j++) {
                    printf("%c ", m[i][j]);
                }  
                printf("\n");
            }
            yes=0;
        }
        joueur = (joueur == 'X') ? 'O' : 'X';
        
    } while (colonne>0);
    

    for (int i = 0; i < h; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
    

} 