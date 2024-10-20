#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int n;
    printf("Entrez le nombre de données à encoder\n");
    scanf("%d", &n);

    int* buffer = malloc(n*sizeof(int));
    if(buffer==NULL){
        perror("Allocation dynamique de buffer impossible");
        exit(1);
    }

    printf("quels nombre voulez vous ajouter?\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &buffer[i]);
    }

    int pos=0;
    int neg=0;

    for (int i = 0; i < n; i++){
      if(buffer[i]>=0){
        pos++;
      }else{ 
        neg++;
      }
    }

    int* tabPos = malloc(pos*sizeof(int));
    int* tabNeg = malloc(neg*sizeof(int));

    if(tabPos == NULL || tabNeg == NULL){ 
        perror("Allocation dynamique de buffer impossible");
        free(buffer);
        exit(1);
    }

    int indicePos=0, indiceNeg=0;

    for (int i = 0; i < n; i++){
        if(buffer[i]>=0){
            tabPos[indicePos++]= buffer[i];
        }else{ 
            tabNeg[indiceNeg++]= buffer[i];
        }
    }

    printf("Résultats: ");
    printf("tableau de valeurs positives : ");
    for (int i = 0; i < pos; i++){
        printf("%d  ", tabPos[i]);
    }
    
    printf("\n");
    printf("tableau de valeurs négatives : ");
    for (int i = 0; i < neg; i++){
        printf("%d  ", tabNeg[i]);
    }
    

    free(buffer);
    free(tabPos);
    free(tabNeg);

    return 0;
}