#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define TAILLE 256

/**
 * PRE : t : tableau de n chaînes de caractères ne contenant pas de chaînes nulles.
 * POST : Les n chaînes de caractères de t sont affichées sur stdout dans l’ordre
 * des indices à raison d’une chaine par ligne, précédée du numéro de ligne.
 */
void impTable (char** t, int n){
    for(int i=1 ; i<n; i++){
        printf("%d . %s\n",i, t[i]);
    }
}

/**PRE : chaines: tableau de chaînes de caractères de taille n ne contenant pas de chaînes nulles 
 *mot: chaîne de caractères
 *RES : renvoie vrai si mot se trouve dans le tableau chaines ; faux sinon.
 */
bool rechercher (char** chaines, int n, char* mot){
    int present=0;
    for(int i=1; i<n; i++){
        if(strcmp(chaines[i], mot)==0){
            present=1;
            break;
        }
    }

    if(present==0){ 
        return false;
    }
    else return true;
    
}

/**
 * PRE : inv : chaîne de caractères
 * s : tableau de char de taille sz
 * POST : La fonction a affiché le message d’invitation inv sur stdout, ensuite elle a lu 
 * sur stdin une chaîne de caractère d’au plus sz – 1 caractères, a vérifié qu’elle n’est 
 * ni vide, ni trop longue et répété l’opération tant qu’une chaîne valide n’est pas 
 * introduite, puis elle a remplacé le ‘\n’ par ‘\0’. La chaîne valide a été placée dans s.
 * RES : renvoie le nombre de caractères de la dernière chaîne lue ; -1 si fin de fichier 
 * [Ctrl-D] atteinte 
 */
int litEtValideChaine (char* inv, char* s, int sz){

    while (true) {
        printf("%s", inv); 

        if (fgets(s, sz, stdin) == NULL) {
            return -1;
        }

        if (s[strlen(s) - 1] == '\n') {
            s[strlen(s) - 1] = '\0';
        }

        if (strlen(s) > 0 && strlen(s) < sz - 1) {
            return strlen(s);
        }

        printf("Chaîne invalide. Veuillez réessayer.\n");
    }
}



int main(int argc, char *argv[]){

    impTable(argv,argc);

    int absent_count=0;
    char ligne[TAILLE];

while (true) {
        int res = litEtValideChaine("\nEntrez un mot : ", ligne, TAILLE);

        if (res == -1) {
            printf("\nFin du programme (Ctrl+D détecté).\n");
            break;
        }
        printf("\nle mot lu est %s il est de longueur = %ld et il est ... ", ligne, strlen(ligne));

        if(!rechercher(argv, argc,ligne)){
            printf("absent\n");
            absent_count++;
        }
        else printf("présent !!! \n");

    }
    printf("il ya eu %d mots absents\n\n", absent_count);
    exit(0);
}
