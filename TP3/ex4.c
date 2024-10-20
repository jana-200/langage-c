#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int n;
    do{ 
        printf("Entrez le nombre de données à encoder\n");
        scanf("%d", &n);

        if(n<=0){ 
            exit(1);
        }

        int* buffer = malloc(n*sizeof(int));
        if(buffer==NULL){
            perror("Allocation dynamique de buffer impossible");
            exit(1);
        }

        printf("quels nombre voulez vous ajouter?\n");
        for (int *ptr = buffer; ptr-buffer < n; ptr++){
            scanf("%d", &*ptr);
        }

        int pos=0;
        int neg=0;

        for (int *ptr = buffer; ptr-buffer < n; ptr++){
        if(*ptr>=0){
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

        for (int *ptr = buffer; ptr-buffer < n; ptr++){
            if(*ptr>=0){
                tabPos[indicePos++]= *ptr;
            }else{ 
                tabNeg[indiceNeg++]= *ptr;
            }
        }

        printf("Résultats: ");
        printf("tableau de valeurs positives : ");
        for (int *ptr = tabPos; ptr-tabPos < pos; ptr++){
            printf("%d  ", *ptr);
        }
        
        printf("\n");
        printf("tableau de valeurs négatives : ");
        for (int *ptr = tabNeg; ptr-tabNeg < neg; ptr++){
            printf("%d  ", *ptr);
        }
        

        free(buffer);
        free(tabPos);
        free(tabNeg);
    }while(n>0);

    return 0;
}