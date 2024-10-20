#include <stdlib.h>
#include <stdio.h>

int main(){ 
    int a,b;
    printf("Entrez deux nombres entiers positifs: \n");
    scanf("%d%d", &a,&b);
    while(a<=0 || b<=0){ 
        printf("Entrez deux nombres entiers strictement positifs: \n");
        scanf("%d%d", &a,&b);
    }
    if(b>a){ 
        int temp=a;
        a=b;
        b=temp;
    }
    int q=0;
    int somme=0;
    while(somme+b <= a){ 
        somme+=b;
        q++;
    }
    printf("%d / %d = %d ; reste = %d\n", a,b,q,a-somme);
}