#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


// Déclaration des fonctions fournies
void initPlateau(char** p, int n, int m, int nbRochers);
int entierAleatoire(int min, int max);
void afficherPlateau(char** p, int n, int m);

// Déclarations des fonctions à compléter
char** creerPlateau(int n, int m);
int nbRochers(char** p, int n, int m);
void placerUnRocher(char** p, int n, int m);
bool supprimerColonne(char*** p, int n, int *m, int colonne);
bool supprimerLigne(char*** p, int *n, int ligne);


//*********************
// PROGRAMME PRINCIPAL
//*********************

int main (int argc, char* argv[]) {
    char pseudo[50]="";
    char** p;
    // Vérification des arguments du programme
    if (argc != 3) {
        printf("Erreur: les deux dimensions du plateau de jeu doivent être fournis en arguments\n");
        exit(1);
    }

    // Récupération des dimensions du plateau de jeu
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // Lecture du pseudonyme du joueur
    printf("quel est votre pseudo : ");
    scanf("%s", pseudo);
    
    // Création du plateau de jeu
    p=creerPlateau(n,m);
    
    // Initialisation du plateau en plaçant nl*nc/3-1 rochers aléatoires 'R'
    srand((unsigned) time(NULL));
    initPlateau(p,n,m,n*m/3-1);
    int rochers=nbRochers(p,n,m);
    
    // Boucle de jeu

    int nb_bombes=0;
    int rochers_detruits=0;
    afficherPlateau(p,n,m);

    while ( rochers>0 && n>=3 && m>=3 && rochers!=n*m ) {
        int lb,cb;
        // Placement d'un rocher aléatoire 'R'
        printf("Ajout d'un rocher sur le plateau: \n");
        placerUnRocher(p,n,m);
        afficherPlateau(p,n,m);

        // Saisie des coordonnées de la bombe
        printf("Entrez les coordonnées de votre bombe: ");
        scanf("%d %d", &lb,&cb);
        
        lb--;
        cb--;
        // Placement de la bombe 'X'
        if(p[lb][cb]=='R'){ 
            printf("il y'a un rocher à cet endroit\n");
            continue;
        }
        p[lb][cb]='X';
        nb_bombes++;
        afficherPlateau(p,n,m);

                
        // Explosion de la bombe
        supprimerLigne(&p,&n,lb);
        supprimerColonne(&p,n,&m,cb);
        rochers_detruits+=rochers-nbRochers(p,n,m);
        rochers=nbRochers(p,n,m);
        
        printf("Après explosion de la bombe:\n");
        afficherPlateau(p,n,m);
    }

    // Affichage des statistiques
    if(rochers==0){ 
        printf("bravooo %s tu as gagné ", pseudo);
    }
    else printf("tu as perdu ):\n");

    printf("tu as posé %d bombes\n",nb_bombes);
    printf("tu as détruit %d rochers\n",rochers_detruits);
    printf("il reste %d rochers\n", rochers);
}


//***********************
// FONCTIONS A COMPLETER
//***********************

/**
 * PRE: n,m: entiers positifs
 * RES: renvoie un tableau de dimensions n x m où les éléments sont 
 *      initialisés avec des espaces ; NULL si une erreur s'est produite
 *      (le tableau renvoyé est dynamique et devra être libéré)
 */
char** creerPlateau (int n, int m) {
    char** p=(char**)malloc(n*sizeof(char*));
    if(p==NULL)exit(1);
    for(int i=0;i<n;i++){ 
        p[i]=(char*)malloc(m*sizeof(char));
        if(p[i]==NULL){ 
            for(int j=0;j<i;j++){ 
                free(p[j]);
            }
            free(p);
            exit(1);
        }
        for(int j=0;j<m;j++){ 
            p[i][j]=' ';
        }
    }

    return p;
}

/**
 * Compte le nombre de rochers dans le plateau
 * PRE: p: plateau de dimensions n x m
 * RES: renvoie le nombre de cases du plateau p qui sont occupées 
 *      par un rocher 'R'
 */
int nbRochers (char** p, int n, int m) {
    int nb=0;
    for(int i=0; i<n;i++){ 
        for(int j=0; j<m;j++){ 
            if(p[i][j]=='R')
                nb++;
        }
    }

    return nb;
}

/**
 * Place aléatoirement un rocher dans le plateau
 * PRE: p: plateau de dimensions n x m contenant au moins une case vide
 *         (càd différente de 'R')
 * POST: un rocher 'R' a été placé aléatoirement dans une case vide de p
 */
void placerUnRocher (char** p, int n, int m) {
    int l,c;
    bool found=false;
    while(!found){ 
        l= entierAleatoire(0,n-1);
        c= entierAleatoire(0,m-1);
        if(p[l][c]!='R'){ 
            p[l][c]='R';
            found=true;
        }
    }
}

/**
 * Supprime une ligne du plateau
 * PRE: p: plateau contenant n lignes, t.q. n > 1
 *      ligne: indice de ligne t.q. 0 <= ligne < n
 * POST: la ligne d'indice ligne de p a été supprimée et n décrémenté de 1;
 *       p comporte n lignes physiquement en mémoire (taille physique = taille logique)
 * RES: renvoie vrai si la taille physique du tableau a bien été modifiée; faux sinon
 */
bool supprimerLigne(char*** p, int* n, int ligne){ 
    (*n)--;
    for (int i=ligne; i<*n; i++) { 
        (*p)[i]=(*p)[i+1];
    }
    (*p)=(char**)realloc((*p),(*n)*sizeof(char*));
    if(*p==NULL) return false;
    return true;
}


/**
 * TODO specs
 */
bool supprimerColonne (char*** p, int n, int *m, int colonne) {
    (*m)--;
    for (int i=0; i<n; i++) {
        // Suppression de la colonne d'indice colonne dans la ligne i
        for (int j=colonne; j<*m; j++)
            (*p)[i][j] = (*p)[i][j+1];
        // Mise à jour des dimensions physiques de la ligne i
        (*p)[i] = realloc((*p)[i], *m * sizeof(char));
        if ((*p)[i] == NULL)
            return false;
    }
    return true;
}


//*************************************
// FONCTIONS FOURNIES (NE PAS MODIFIER)
//*************************************

/**
 * Place aléatoirement un rocher dans le plateau
 * PRE: p: plateau de dimensions n x m contenant au moins nbR cases vides
 *         (càd différente de 'R')
 *      nbR: le nombre de rochers à placer dans le plateau p
 * POST: nbR rochers 'R' ont été placés aléatoirement dans des cases vides de p
 */
void initPlateau (char** p, int n, int m, int nbR) {
    for (int i=0; i<nbR; i++)
        placerUnRocher(p,n,m);
}

/**
 * Génère une valeur entière aléatoire dans un intervalle
 * PRE: min, max: valeurs entières t.q. min < max
 * RES: renvoie une valeur entière aléatoire dans l'intervalle [min,max]
 */
int entierAleatoire (int min, int max) {
    return min + (int)(rand()/(RAND_MAX+1.0)*(max-min+1));
}

enum {BLACK_TEXT=30,RED_TEXT,GREEN_TEXT,YELLOW_TEXT,BLUE_TEXT,PURPLE_TEXT,CYAN_TEXT,WHITE_TEXT};
#define colorOn(mode,textColor) printf("\033[%d;%dm",mode,textColor)   // mode: 0 normal ; 1 bold
#define colorOff() printf("\033[0m");  // text color reset

/**
 * Affiche le plateau de jeu
 * PRE: p: plateau de dimensions n x m
 * POST: p a été affiché en indiquant les numéros des lignes et des colonnes
 */
void afficherPlateau (char** p, int n, int m) {
    colorOn(1,PURPLE_TEXT);
    printf("\n    ");
    for (int c=0; c<m; c++)
        printf("%3i", c+1);
    printf("\n     ");
    for (int c=0; c<m; c++)
        printf("---");
    printf("\n");
    for (int l=0; l<n; l++) {
        printf("%3i |", l+1);
        colorOn(1,CYAN_TEXT);
        for (int c=0; c<m; c++) {
            if (p[l][c] == 'X') {
                colorOn(1,YELLOW_TEXT);
                printf(" %c ", p[l][c]);
                colorOn(1,CYAN_TEXT);
            }
            else {
                printf(" %c ", p[l][c]);
            }
        }
        colorOn(1,PURPLE_TEXT);
        printf("| %i\n", l+1);
    }
    printf("     ");
    for (int c=0; c<m; c++)
        printf("---");
    printf("\n    ");
    for (int c=0; c<m; c++)
        printf("%3i", c+1);
    printf("\n\n");
    colorOff();
}