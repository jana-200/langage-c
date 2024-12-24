
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/** CONSTANTS **/

// indexes of ticket information
#define NBR_INFOS   4
#define USERID_IDX  0
#define FROM_IDX    1
#define TO_IDX      2
#define DATE_IDX    3

#define MAX_LENGTH    50 // maximal number of characters for ticket information
#define DATE_LENGTH   8  // fixed length of date format (i.e. "20190628")

#define DB_SIZE 10



/** DECLARATION OF FUNCTIONS **/

bool get_data_from_user(char* buffer, int size);
char** create_ticket(char* user_id, char* from, char* to, char* date);
bool add_ticket_to_db(char*** db, int db_sz, int* nbr_tickets, char** ticket);
int find_ticket(char*** db, int nbr_tickets, char* user_id, char* date);
bool update_ticket(char** ticket, char* from, char* to);
void free_db(char*** db, int* nbr_tickets);
void print_all_tickets(char*** db, int nbr_tickets);
// given functions
void print_ticket(char** ticket);
int menu();
void printErrMsg(char* msg, int option);


/** MAIN PROGRAM **/

int main(int argc, char const *argv[])
{
  // main variables
  int index = -1;
  // declare here: the db, the number of tickets
  char*** db=(char***)malloc(DB_SIZE*sizeof(char**));
  int nbr_tickets=0;

  // buffers to read from stdin
  // declare here all the buffers to record data from stdin

  char* userID =(char*)malloc((MAX_LENGTH+1)*sizeof(char));
  char* from  =(char*)malloc((MAX_LENGTH+1)*sizeof(char));
  char* to  =(char*)malloc((MAX_LENGTH+1)*sizeof(char));
  char* date =(char*)malloc((DATE_LENGTH+1)*sizeof(char));


  char** ticket;

  // main interactive loop
  int user_choice = -1;
  while (user_choice != 0) {
    user_choice = menu();
    switch (user_choice) {
    case 1 :
      //1. ADD A TICKET IN DB
      //1.a collect ticket information from user
      printf("What is the user ID ?\n");
      get_data_from_user(userID,MAX_LENGTH+2);
      printf("What is the departure train station ?\n");
      get_data_from_user(from,MAX_LENGTH+2);
      printf("What is the destination train station ?\n");
      get_data_from_user(to,MAX_LENGTH+2);
      printf("What is the date ?\n");
      get_data_from_user(date,DATE_LENGTH+2);

      //1.b create ticket with collected information
      ticket=create_ticket(userID,from,to,date);

      //1.c add ticket to DB
      add_ticket_to_db(db,DB_SIZE,&nbr_tickets,ticket);

      printf("Ticket added with success!\n");
      print_ticket(ticket);
      break;

    case 2:
      //2. MODIFY A TICKET
      //2.a collect user ID and date of ticket
      printf("What is the user id ?\n");
      get_data_from_user(userID,MAX_LENGTH+2);

      printf("What is the date?\n");
      get_data_from_user(date,DATE_LENGTH+2);

      //2.b find ticket in DB
      index=find_ticket(db,nbr_tickets,userID,date);

      if (index == -1) {
        printf("erreur, on n'a pas trouvé le ticket");
        break;
      }

      //2.c collect new ticket information
      printf("Ready to modify ticket at index %d\n", index);
      printf("Modify the FROM station ? (press Enter with empty response to unchange)\n");
      get_data_from_user(from,MAX_LENGTH+2);
      printf("Modify the TO station ? (press Enter with empty response to unchange)\n");
      get_data_from_user(to,MAX_LENGTH+2);

      //2.d update ticket information in DB
      if(update_ticket(db[index],from,to)) printf("Ticket updated with success!\n");
      else printf("erreur lors de l'update");
      break;

    case 3:
      //3. PRINT ALL TICKETS FROM DB
      print_all_tickets(db,nbr_tickets);

      break;

    case 0:
      //0. FREE DB AND QUIT
      free_db(db,&nbr_tickets);

      printf("Bye bye!\n\n");
      break;

    default:
      printErrMsg("\n!! WARN: '%d' is not a valid option !!\n", user_choice);
      break;
    }
  }
}


/** FUNCTIONS TO IMPLEMENT **/

/**
 * PRE: buffer is a string of size sz
 * POST: reads at most sz-1 characters from stdin, stores them into buffer,
 *       and removes the '\n' from buffer if it is present
 * RES: returns true in case of success, false otherwise
 */
bool get_data_from_user(char* buffer, int sz){
    if (buffer == NULL || sz <= 0) return false; // Vérification de base

    if (fgets(buffer, sz-1, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remplacer '\n' par '\0'
        }
        return true;
    }



    return false;
}

/**
 * PRE: userID, from, to: pointers to strings of maximal MAX_LENGTH characters
 *      date: pointer to a string of exactly MAX_DATE characters
 * POST: creates a valid ticket and deeply copies all the given strings
 *       into expected locations in the new ticket
 * RES: returns a pointer to the new ticket or NULL in case of error
 */
char** create_ticket(char* userID, char* from, char* to, char* date) {
    char** ticket = (char**)malloc(NBR_INFOS*sizeof(char*));
    if(ticket == NULL) exit(1);
    if(userID==NULL || strlen(userID) >MAX_LENGTH) exit(1);
    if(from==NULL || strlen(from) >MAX_LENGTH) exit(1);
    if(to==NULL || strlen(to) >MAX_LENGTH) exit(1);
    if(date==NULL || strlen(date)!=DATE_LENGTH) exit(1);

    ticket[USERID_IDX] = (char*)malloc((strlen(userID) + 1) * sizeof(char));
    if(ticket[USERID_IDX] == NULL) exit(1);
    strcpy(ticket[USERID_IDX],userID);

    ticket[FROM_IDX] = (char*)malloc((strlen(from) + 1) * sizeof(char));
    if (ticket[FROM_IDX] == NULL) exit(1);
    strcpy(ticket[FROM_IDX],from);


    ticket[TO_IDX] = (char*)malloc((strlen(to) + 1) * sizeof(char));
    if (ticket[TO_IDX] == NULL) exit(1);
    strcpy(ticket[TO_IDX],to);

    ticket[DATE_IDX] = (char*)malloc((strlen(date) + 1) * sizeof(char));
    if (ticket[DATE_IDX] == NULL) exit(1);
    strcpy(ticket[DATE_IDX],date);

  return ticket;
}

/**
 * PRE: db: a pointer to a list of capacity db_sz, containing nbr_tickets tickets
 *      ticket: a pointer to a valid ticket
 * POST: the ticket is added at the end of the db, and the number of tickets
 *       is updated
 * RES: returns true in case of success, false if db is full
 */
bool add_ticket_to_db(char*** db, int db_sz, int* nbr_tickets, char** ticket) {
  if(ticket==NULL) exit(1);
  // check if bd is not full
  if(db_sz==(*nbr_tickets)) return false;


  // add the new ticket
  db[*nbr_tickets]=(char**)malloc(NBR_INFOS*sizeof(char*));
  if(db[*nbr_tickets] == NULL) exit(1);
  db[*nbr_tickets]=ticket;
  (*nbr_tickets)++;

  return true;
}

/**
 * PRE: db: list of nbr_tickets tickets
 *      userID, date: pointers to strings
 * RES: returns the index of the first ticket in db with both userID and date matching
 *      -1 if no match is found
 */
int find_ticket(char*** db, int nbr_tickets, char* userID, char* date) {

    for(int i=0; i<nbr_tickets; i++){
        if(strcmp(db[i][USERID_IDX],userID)==0 && strcmp(db[i][DATE_IDX],date)==0)
            return i;
    }

  return -1;
}

/**
 * PRE: ticket: pointer to a valid ticket
 *      from, to: pointers to strings of maximal MAX_LENGTH characters
 * POST: if from's size > 0, the corresponding emplacement in given ticket
 *          is resized and the content of 'from' is deeply copied into the ticket
 *       if to's size > 0, the corresponding emplacement in given ticket
 *          is resized and the content of 'to' is deeply copied into the ticket
 * RES: returns true in case of success, false otherwise
 */
bool update_ticket(char** ticket, char* from, char* to) {
  if(strlen(from)<0) return false;
  if(strlen(to)<0) return false;

  ticket[FROM_IDX]=(char*)realloc(ticket[FROM_IDX],(strlen(from)+1)*sizeof(char));
  if(ticket[FROM_IDX]==NULL) exit(1);

  ticket[TO_IDX]=(char*)realloc(ticket[TO_IDX],(strlen(to)+1)*sizeof(char));
  if(ticket[FROM_IDX]==NULL) exit(1);

  strcpy(ticket[FROM_IDX],from);
  strcpy(ticket[TO_IDX],to);


  return true;
}

/**
 * PRE: db: list of nbr_tickets tickets
 * POST: all the tickets and their data are freed ; nbr_tickets is set to 0
 */
void free_db(char*** db, int* nbr_tickets){
  for(int i=0 ; i<*nbr_tickets;i++){
    for(int j=0; j<NBR_INFOS; j++){
        free(db[i][j]);
    }
    free(db[i]);
  }

  free(db);

  *nbr_tickets=0;

}

/**
 * PRE: db: list of nbr_tickets tickets
 * POST: prints all the tickets on stdout
 */
void print_all_tickets(char*** db, int nbr_tickets){
  printf("Database of the tickets:\n");
  for(int i=0 ; i<nbr_tickets; i++){
    print_ticket(db[i]);
  }

}


// =====================================================
//        DO NOT MODIFY THESE FUNCTIONS/MACROS
// =====================================================

/**
 * PRE: ticket: pointer to a ticket
 * POST: prints all the information of the ticket on stdout
 */
void print_ticket(char** ticket){
  printf(
    "Ticket:\n\tClientID: %s\n\tFROM: %s\n\tTO: %s\n\tDate: %s\n",
    ticket[USERID_IDX], ticket[FROM_IDX], ticket[TO_IDX], ticket[DATE_IDX]
    );
}

enum {BLACK_TEXT=30,RED_TEXT,GREEN_TEXT,YELLOW_TEXT,BLUE_TEXT,PURPLE_TEXT,CYAN_TEXT,WHITE_TEXT};
#define colorOn(mode,textColor) printf("\033[%d;%dm",mode,textColor)   // mode: 0 normal ; 1 bold
#define colorOff() printf("\033[0m");  // text color reset

/**
 * POST: displays the menu and the uers's choice on stdout
 * RES: returns the user's choice
 */
int menu() {
  colorOn(1,PURPLE_TEXT);
  printf("\n" \
    "1. Add a ticket\n" \
    "2. Modify a ticket\n" \
    "3. Cancel a ticket\n" \
    "4. Print all tickets\n" \
    "0. Quit\n");
  colorOn(1,CYAN_TEXT);
  printf("What is your choice ? ");
  int choice = 0;
  scanf("%d", &choice);
  getchar(); // get EOL
  printf("\n>> You wisely choose: %d\n", choice);
  colorOff();
  return choice;
}

void printErrMsg(char* msg, int option) {
  char buf[256];
  sprintf(buf, msg, option);
  colorOn(1,RED_TEXT);
  printf("%s", buf);
  colorOff();
}