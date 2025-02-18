#include <stdio.h>
#include <stdlib.h>
#include "cryptPolybe.h" 
#include "../utils_v1.h"

int main() {
    char* message;
    printf("Entrez un message à déchiffrer : ");
    message = readLine(); 
    char* decrypted_message = decryptPolybe(message);
    printf("Message déchiffré : %s\n", decrypted_message);

    return 0;
}