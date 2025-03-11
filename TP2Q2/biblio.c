#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "biblio.h"
#include "utils_v1.h"

bool lireLivre (struct Livre *l) {
    // buffer de lecture
    char ligne[MAX_TITRE+2];
    // lecture du titre
    if (readLimitedLine(ligne,MAX_TITRE+2) <= 0) return false;
    strcpy(l->titre, ligne);
   
    // lecture de l'auteur
    if (readLimitedLine(ligne,MAX_AUTEUR+2) <= 0) return false;
    strcpy(l->auteur, ligne);
    // lecture de l'isbn
    if (scanf("%ld\n",&l->isbn) != 1) return false;
    
    // lecture de l'éditeur
    if (readLimitedLine(ligne,MAX_EDITEUR+2) <= 0) return false;
    strcpy(l->editeur, ligne);
    // lecture de l'année
    if (scanf("%d\n",&l->annee) != 1) return false;
    // lecture du genre
    if (readLimitedLine(ligne,MAX_TITRE+2) <= 0) return false;
    if ((l->genre = str2genre(ligne)) == -1) return false;
    return true;
}

enum Genre str2genre(char* str){
    if (strcasecmp(str, "bande dessinée") == 0) return BANDE_DESSINEE;
    if (strcasecmp(str, "poésie") == 0) return POESIE;
    if (strcasecmp(str, "théâtre") == 0 || strcasecmp(str, "theatre") == 0) return THEATRE;
    if (strcasecmp(str, "roman") == 0) return ROMAN;
    if (strcasecmp(str, "roman historique") == 0) return ROMAN_HISTORIQUE;
    if (strcasecmp(str, "littérature française") == 0) return LITTERATURE_FRANCAISE;
    if (strcasecmp(str, "littérature étrangère") == 0) return LITTERATURE_ETRANGERE;
    if (strcasecmp(str, "sciences") == 0) return SCIENCES;
    if (strcasecmp(str, "informatique") == 0) return INFORMATIQUE;
    if (strcasecmp(str, "science-fiction") == 0 || strcasecmp(str, "science fiction") == 0) return SCIENCE_FICTION;
    if (strcasecmp(str, "santé") == 0 || strcasecmp(str, "sante") == 0) return SANTE;
    if (strcasecmp(str, "histoire") == 0) return HISTOIRE;
    return -1;
}

char* genre2str(enum Genre g){ 
    if(g == BANDE_DESSINEE) return "bande dessinée";
    if(g == POESIE) return "poésie";
    if(g == THEATRE) return "théâtre";
    if(g == ROMAN) return "roman";
    if(g == ROMAN_HISTORIQUE) return "roman historique";
    if(g == LITTERATURE_FRANCAISE) return "littérature française";
    if(g == LITTERATURE_ETRANGERE) return "littérature étrangère";
    if(g == SCIENCES) return "sciences";
    if(g == INFORMATIQUE) return "informatique";
    if(g == SCIENCE_FICTION) return "science-fiction";
    if(g == SANTE) return "santé";
    if(g == HISTOIRE) return "histoire";
    return "inconnu";
}

char* livre2str(struct Livre* l){
    int taille= strlen(l->titre) + strlen(l->auteur) + strlen(l->editeur) + 100;
    char* str = (char*)malloc(taille);
    if (str == NULL) return NULL;

    sprintf(str, "%s\n%s\n%ld\n%s\n%d\n%s\n",l->titre, l->auteur, l->isbn, l->editeur, l->annee, genre2str(l->genre));

    return str;
}

void afficherBib(struct Livre* bib, int* taille) { 
    for (int i = 0; i < *taille; i++) {
        char* str = livre2str(&bib[i]);
        if (str) {
            printf("%s\n", str);
            free(str); 
        }
    }
}


bool ajouterLivre(struct Livre** bib, int* taille, struct Livre l) {
    (*taille)++;
    struct Livre* temp = (struct Livre*)realloc(*bib, (*taille) * sizeof(struct Livre));
    if (temp == NULL) {
        return false;
    }

    *bib = temp;
    (*bib)[(*taille)-1] = l;  
    return true;
}
