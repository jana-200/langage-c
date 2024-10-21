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
    
    //on alloue mémoire dynamique
    for (int i = 0; i < h; i++) {
        m[i] = (char*) malloc(l * sizeof(char));
        if (m[i] == NULL) exit(1);
    }

    //on rempli les cases de la mat 
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

        //on test si on est dans le cas basic ou pas
        //si non
        if (colonne < 0 || colonne-1 >= l) {

            if(colonne<0){ 
                if(l+colonne>0)colonne=l+colonne;
                else{ 
                    printf("cela ne va pas être possible , le jeu s'arrête ici");
                    exit(1);
                }  
            }
            //redimension
            for (int i = 0; i < h; i++) {
                m[i] = (char*) realloc(m[i],colonne * sizeof(char));
                if (m[i] == NULL) exit(1);                    
                
            }
            if(colonne>=l){ 
                //on rempli les nouvelles cases si besoin
                for (int i = 0; i < h; i++){
                    for (int j = l; j < colonne; j++){
                        m[i][j]='.';
                    }
                }
            }
            l=colonne;
            
        }

        //remplacement d'une case par X ou O
        for (int i = h - 1; i >= 0; i--) {
            if (m[i][colonne-1] == '.') {
                m[i][colonne-1] = joueur;
                yes=1;
                break;
            }
        }

        //colonne compléte
        if(yes==0){ 
           printf("toute la colonne est remplie veuillez chooisir une autre colonne :");
           continue;
        } 
        //affichage de la grille
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                printf("%c ", m[i][j]);
            }  
            printf("\n");
        }
        yes=0;
        joueur = (joueur == 'X') ? 'O' : 'X';
        
    } while (colonne>0);
    
    //on libére la mémoire qu'on a utilisé
    for (int i = 0; i < h; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
    

} 