#include <stdio.h>
#include <stdlib.h>
#include "cryptMorse.h" 
#include "../utils_v1.h"

int main() {
    char* message;
    printf("Entrez un message à chiffrer : ");
    message = readLine(); 
    char* encrypted_message = encryptMorse(message);
    printf("Message chiffré : %s\n", encrypted_message);

    return 0;
}