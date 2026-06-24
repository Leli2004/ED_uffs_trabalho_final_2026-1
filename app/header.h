#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**************************************
// Constantes

#define MAX_TEXT 100
#define AVAILABLE 0
#define LOANED 1

//**************************************
// Structs

struct user {
    char email[MAX_TEXT];
    char name[MAX_TEXT];
};
typedef struct user User;

struct book {
    char title[MAX_TEXT];
    char author[MAX_TEXT];
    int publicationYear;
    int id; // identificador único
    int status; // 0 = available, 1 = loaned
    char loanerEmail[MAX_TEXT];
};
typedef struct book Book;

// Structs para lista simplesmente encadeada
struct userNode {
    User data;
    struct userNode *next;
};
typedef struct userNode UserNode;

struct bookNode {
    Book data;
    struct bookNode *next;
};
typedef struct bookNode BookNode;

//**************************************
// Interfaces

// menu
int getMainMenu();
int getRegistrationMenu();
int getSearchMenu();
int getUpdateMenu();
int getDeleteMenu();

// cadastro - registration
BookNode *registerBook(BookNode *books, int *nextId);
UserNode *registerUser(UserNode *users);

// consulta - search
void listBooks(BookNode *books);
BookNode *findBookById(BookNode *books, int id);
void findBooksByAuthor(BookNode *books, char author[]);

void listUsers(UserNode *users);
UserNode *findUserByEmail(UserNode *users, char email[]);
void findUsersByName(UserNode *users, char name[]);

void findLoansByEmail(BookNode *books, char email[]);

// atualização - update
void updateBook(BookNode *books);
void updateUser(UserNode *users);

// exclusão - delete
BookNode *deleteBook(BookNode *books);
UserNode *deleteUser(UserNode *users, BookNode *books);

// empréstimo - loan
void loanBook(BookNode *books, UserNode *users);

// devolução - return
void returnBook(BookNode *books);

// funções auxiliares com scanf
int askBookId();
int askPublicationYear();
void askEmail(char email[]);
void askName(char name[]);
void askTitle(char title[]);
void askAuthor(char author[]);

// funções auxiliares para memória
BookNode *freeBooks(BookNode *books);
UserNode *freeUsers(UserNode *users);

// funções auxiliares
int userHasLoans(BookNode *books, char email[]);
int generateBookId(int *nextId);
