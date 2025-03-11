#ifndef _BIBLIO_H_
#define _BIBLIO_H_

#include <stdbool.h> 

#define MAX_TITRE 128
#define MAX_AUTEUR 80
#define MAX_EDITEUR 50

enum Genre {
    BANDE_DESSINEE,
    POESIE,
    THEATRE,
    ROMAN,
    ROMAN_HISTORIQUE,
    LITTERATURE_FRANCAISE,
    LITTERATURE_ETRANGERE,
    SCIENCES,
    INFORMATIQUE,
    SCIENCE_FICTION,
    SANTE,
    HISTOIRE
};

struct Livre {
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    long int isbn;
    char editeur[MAX_EDITEUR];
    int annee;
    enum Genre genre;
};

bool lireLivre(struct Livre* l);
enum Genre str2genre(char* str);
char* genre2str(enum Genre g);
char* livre2str(struct Livre* l);
void afficherBib(struct Livre* bib, int* taille);
bool ajouterLivre(struct Livre** bib, int* taille, struct Livre l);


#endif
