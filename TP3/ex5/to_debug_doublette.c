#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc, char **args){ 
    int i;
    int *t1, *t2, *t3;
    int *ptr;

    t1 = (int*)malloc(SIZE*sizeof(int));
    t2 = (int*)malloc(SIZE*sizeof(int));
    t3 = (int*)malloc(SIZE*sizeof(int));

    if(t1 == NULL || t2 ==NULL || t3 == NULL){ 
        perror("out of mem\n");
        exit(1);
    }

    ptr = t1;
    for ( i = 0; i < SIZE; i++){
        *ptr = t2[i] = t3[i] = i;
    }
    ptr-=i;

    free(t1);
    free(t2);
    free(ptr);
    //je pense qu'il ne faut pas free le ptr car il n'a pas prit de place en mémoire avce malloc, calloc ou realloc
    
}