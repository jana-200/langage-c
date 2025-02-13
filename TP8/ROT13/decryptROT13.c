#include <stdio.h>
#include <stdlib.h>
#include "cryptROT13.h" 
#include "../utils_v1.h" 

int main() {
    char* message;
    printf("Entrez un message à déchiffrer : ");
    message = readLine(); 
    char* decrypted_message = decrypt(message);
    printf("Message chiffré : %s\n", decrypted_message);

    return 0;
}