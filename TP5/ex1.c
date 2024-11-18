#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){ 

    char **maj = (char**)malloc((argc-1)*sizeof(char*));
    if (maj == NULL) exit(1);

    for(int i=1 ; i<argc; i++){ 

        size_t len= strlen(argv[i]); // len il prend pas le \0
        maj[i-1]= malloc((len + 1) * sizeof(char));

        if (maj[i - 1] == NULL) exit(1);

        for(size_t j=0 ;j<len+1;j++){ 
            maj[i-1][j]=toupper(argv[i][j]);
        }

    }

    for (int i = 0; i < argc - 1; i++) {
        printf("%s ", maj[i]);
        printf("\n");
    }
    //liberation de la memoire
    for(int i=0;i<argc-1;i++){
        free(maj[i]);
    }
    free(maj);

    printf("\n");
}