#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

int charToIndex(char c) {
    c=tolower(c);
    if (c >= 'a' && c <= 'z') return c - 'a';
    return -1;  
}


char* encryptMorse(char* msg){ 
    size_t len = strlen(msg);
    char* encrypted = malloc((len * 5 + 1)*sizeof(char)); 
    if (encrypted==NULL) return NULL;


    encrypted[0] = '\0';
    for (int i = 0; i < len; i++) {
        int index = charToIndex(msg[i]);
        if(index != -1){ 
            strcat(encrypted,morse[index]);
            strcat(encrypted," ");
        }
        else if(msg[i] == ' '){ 
            strcat(encrypted,"   ");
        }
       
    }

    return encrypted;
}

char morseToChar(char* m){ 
    for (int i = 0; i < 26; i++) {
        if (strcmp(morse[i], m) == 0) return 'a' + i;
    }
    return '\0';
}


char* decryptMorse(char* msg){ 
    size_t len = strlen(msg);
    char* decrypted = malloc((len)*sizeof(char)); 
    if (decrypted==NULL) return NULL;


    int i=0;
    int index=0;
    int indexBuffer=0;
    char buffer[6];
    int espaces=0;

    while(msg[i]!='\0'){

        if(msg[i]==' '){
            if (indexBuffer > 0) {
                buffer[indexBuffer] = '\0';
                decrypted[index++] = morseToChar(buffer);
                indexBuffer = 0;
            }
            espaces++;

        }else{ 
            if (espaces >= 3) { 
                decrypted[index++] = ' ';
            }
            espaces = 0;
            buffer[indexBuffer++] = msg[i];
        }
        i++;

    }

    if (indexBuffer > 0) {
        buffer[indexBuffer] = '\0';
        decrypted[index++] = morseToChar(buffer);
    }

    return decrypted;

}


