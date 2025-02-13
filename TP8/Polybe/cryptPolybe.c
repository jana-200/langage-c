#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cryptPolybe.h"

static char square[8][8] =  {
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}, 
{'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'}, 
{'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'}, 
{'Y', 'Z', '0', '1', '2', '3', '4', '5'}, 
{'6', '7', '8', '9', ' ', '!', '"', '#'}, 
{'$', '%', '&', '\'', '(', ')', '*', '+'}, 
{',', '-', '.', '/', ':', ';', '<', '='}, 
{'>', '?', '@', '[', '\\', ']', '^', '_'}
};

char* encryptPolybe(char* msg){ 
    size_t len=strlen(msg);
    char* encrypted= malloc((len*2 + 1)*sizeof(char));
    if(encrypted==NULL) return NULL;
    
    int index=0;
    for(int i=0; i<len ; i++){
        char c= msg[i];
        for (int j = 0; j < 8; j++){
            for (int k = 0; k < 8; k++){
                if(toupper(c)==square[j][k]){ 
                    encrypted[index++]=j + '0'; //pr convertir en char
                    encrypted[index++]=k + '0';
                    break;
                }
            }
        }
    }

    encrypted[index] = '\0';
    return encrypted;
}


char* decryptPolybe(char* msg){ 
    size_t len=strlen(msg);
    char* decrypted= malloc((len/2 + 1)*sizeof(char));
    if(decrypted==NULL) return NULL;
    
    int index=0;
    for(int i=0; i<len ; i += 2){
        int one= msg[i]-'0'; //pr re convertir en int
        int two= msg[i+1] -'0';

        decrypted[index++]=tolower(square[one][two]);
         
    }
    decrypted[index] = '\0';
    return decrypted;
}




