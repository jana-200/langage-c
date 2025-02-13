#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cryptMorse.h"


#define MAX_INPUT_SIZE 2000

int main() {
    char morse_message[MAX_INPUT_SIZE];

    if (fgets(morse_message, MAX_INPUT_SIZE, stdin) == NULL) {
        exit(1);
    }


    char* decrypted_message = decryptMorse(morse_message);
    if (decrypted_message == NULL) {
        exit(1);
    }

    printf("Message déchiffré : %s\n", decrypted_message);
    free(decrypted_message);

    return 0;
}
