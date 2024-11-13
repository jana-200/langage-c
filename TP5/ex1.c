#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){ 
    char* maj[argc-1];

    for(int i=1 ; i<argc; i++){ 
        size_t len= strlen(argv[i]);
        maj[i-1]= malloc((len + 1) * sizeof(char));
        if (maj[i - 1] == NULL) {
            exit(1);
        }

        for(size_t  j=0;j<len;j++){ 
            maj[i-1][j]=toupper(argv[i][j]);
        }

        maj[i - 1][len] = '\0';
        
    }

    for (int i = 0; i < argc - 1; i++) {
        printf("%s ", maj[i]);
    }
    printf("\n");
}