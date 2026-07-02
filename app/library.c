#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_TEXT 100

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getMainMenu(){
    int option=0;

    printf("\n----------MENU----------\n");
    printf("1 - Cadastro\n");
    printf("2 - Consulta\n");
    printf("3 - Atualizacao\n");
    printf("4 - Exclusao\n");
    printf("5 - Emprestimo\n");
    printf("6 - Devolucao\n");
    printf("0 - Sair\n");

    printf("\nDigite a opção escolhida: ");
    scanf("%d", &option);
    limparBuffer();

    return option;
}

int getRegistrationMenu(){
    int option=0;

    printf("\n----------CADASTRO----------\n");
    printf("1 - Livros\n");
    printf("2 - Usuarios\n");
    printf("0 - Voltar\n");

    printf("\nDigite a opção escolhida: ");
    scanf("%d", &option);
    limparBuffer();

    return option;
}

int getSearchMenu(){
    int option=0;

    printf("\n----------CONSULTA----------\n");
    printf("1 - Livros\n");
    printf("2 - Usuarios\n");
    printf("3 - Emprestimos\n");
    printf("0 - Voltar\n");

    printf("\nDigite a opção escolhida: ");
    scanf("%d", &option);
    limparBuffer();

    return option;
}

int getUpdateMenu(){
    int option=0;

    printf("\n----------ATUALIZAÇÃO----------\n");
    printf("1 - Livros\n");
    printf("2 - Usuarios\n");
    printf("0 - Voltar\n");

    printf("\nDigite a opção escolhida: ");
    scanf("%d", &option);
    limparBuffer();

    return option;
}

int getDeleteMenu(){
    int option=0;

    printf("\n----------EXCLUSÃO----------\n");
    printf("1 - Livros\n");
    printf("2 - Usuarios\n");
    printf("0 - Voltar\n");

    printf("\nDigite a opção escolhida: ");
    scanf("%d", &option);
    limparBuffer();

    return option;
}

/*  LLM USE:
    Utilizada para gerar a implementação base das funções dos menus.
    O auxílio consistiu na criação de funções com estrutura semelhante,
    alterando apenas as opções apresentadas em cada submenu.
*/

void printDivider(){
    printf("\n*********************************\n");
}

BookNode *registerBook(BookNode *books, int *nextId){
    BookNode *new = (BookNode*) malloc(sizeof(BookNode));

    new->data.id = generateBookId(nextId); // incremental automaticamente
    new->data.status = AVAILABLE; // default status
    strcpy(new->data.loanerEmail, ""); // default é vazio

    askTitle(new->data.title);
    askAuthor(new->data.author);
    new->data.publicationYear = askPublicationYear();

    // Adiciona sempre no início da lista
    new->next = books;
    books = new;

    printDivider();
    printf("\nLivro ID %d cadastrado com sucesso!\n", new->data.id);

    return books;
}

UserNode *registerUser(UserNode *users){
    char email[MAX_TEXT];
    askEmail(email);

    if (findUserByEmail(users, email) != NULL) {
        printDivider();
        printf("\nERROR: Usuário com email já cadastrado!\n");
        return users;
    }

    UserNode *new = (UserNode*) malloc(sizeof(UserNode));

    strcpy(new->data.email, email);
    askName(new->data.name);

    new->next = users;
    users = new;

    printDivider();
    printf("\nUsuário '%s' cadastrado com sucesso!\n", new->data.email);

    return users;
}

void printBook(Book book) {
    printf("\n");
    printf("id: %d\n", book.id);
    printf("título: %s\n", book.title);
    printf("autor: %s\n", book.author);
    printf("ano: %d\n", book.publicationYear);
    printf("status: %d\n", book.status);
    if (book.status == LOANED) {
        printf("emprestado para: %s\n", book.loanerEmail);
    }
    printf("\n");
}

void listBooks(BookNode *books){
    if (books == NULL) {
        printf("\n=> Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n=> Lista de livros cadastrados:\n");

    for (BookNode *aux=books; aux!=NULL; aux=aux->next) {
        printBook(aux->data);
    }
}

BookNode *findBookById(BookNode *books, int id){
    BookNode *aux = books;

    while (aux != NULL) {
        if (aux->data.id == id) {
            return aux;
        }
        aux = aux->next;
    }
    
    return NULL; // caso não encontre
}

void findBooksByAuthor(BookNode *books, char author[]){
    int found = 0;

    for (BookNode *aux=books; aux!=NULL; aux=aux->next) {
        if (strcmp(aux->data.author, author) == 0) {
            printBook(aux->data);
            found = 1;
        }
    }

    if (!found) {
        printf("\n=> Livro nao encontrado.\n");
    }
}

void printUser(User user) {
    printf("\n");
    printf("email: %s\n", user.email);
    printf("nome: %s\n", user.name);
    printf("\n");
}

void listUsers(UserNode *users){
    if (users == NULL) {
        printf("\n=> Nenhum usuario cadastrado.\n");
        return;
    }

    printf("\n=> Lista de usuarios cadastrados:\n");

    for (UserNode *aux=users; aux!=NULL; aux=aux->next) {
        printUser(aux->data);
    }
}

UserNode *findUserByEmail(UserNode *users, char email[]){
    UserNode *aux = users;

    while (aux != NULL) {
        if (strcmp(aux->data.email, email) == 0) {
            return aux;
        }
        aux = aux->next;
    }

    return NULL; // se não encontrar email
}

void findUsersByName(UserNode *users, char name[]){
    int found = 0;

    for (UserNode *aux=users; aux!=NULL; aux=aux->next) {
        if (strcmp(aux->data.name, name) == 0) {
            printUser(aux->data);
            found = 1;
        }
    }
    
    if (!found) {
        printf("\n=> Usuário não cadastrado.\n");
    }
}

void findLoansByEmail(BookNode *books, char email[]){
    int found = 0;

    for(BookNode *aux=books; aux!=NULL; aux=aux->next) {
        if (aux->data.status == LOANED && strcmp(aux->data.loanerEmail, email) == 0) {
            printBook(aux->data);
            found = 1;
        }
    }

    if (!found) {
        printf("\n=> Nenhum empréstimo encontrado para este email.\n");
    }
}

void updateBook(BookNode *books){
    int id = askBookId();

    BookNode *book = findBookById(books, id);

    printDivider();

    if (book == NULL) {
        printf("\n=> Livro nao encontrado.\n");
        return;
    }

    printf("\nInforme os novos dados do livro:\n");
    askTitle(book->data.title);
    askAuthor(book->data.author);
    book->data.publicationYear = askPublicationYear();

    printDivider();
    printf("\n=> Livro ID %d atualizado com sucesso!\n", book->data.id);
}

void updateUser(UserNode *users){
    char email[MAX_TEXT];
    askEmail(email);

    UserNode *user = findUserByEmail(users, email);

    printDivider();

    if (user == NULL) {
        printf("\n=> Usuário não cadastrado.\n");
        return;
    }

    printf("\nInforme o novo nome:\n");
    askName(user->data.name);

    printDivider();
    printf("\nUsuário '%s' atualizado com sucesso!\n", user->data.email);
}

BookNode *deleteBook(BookNode *books){
    BookNode *aux;
    BookNode *previous = NULL;

    int id = askBookId();

    printDivider();

    for (aux=books; aux!=NULL; aux=aux->next) {
        if (aux->data.id == id) {

            if (aux->data.status == LOANED) {
                printf("\nERROR: Livro emprestado não pode ser excluído.");
                return books;
            }

            if (aux==books) {
                books = books->next;
            } else {
                previous->next = aux->next;
            }
        
            break;
        }

        previous = aux;
    }

    if (aux!=NULL) {
        free(aux);
        printf("\n=>Livro Id %d excluído com sucesso.", id);
    } else {
        printf("\n=> Livro não encontrado.");
    }

    return books;
}

int userHasLoans(BookNode *books, char email[]) {
    for(BookNode *aux=books; aux!=NULL; aux=aux->next) {
        if(aux->data.status == LOANED && strcmp(aux->data.loanerEmail, email) == 0) {
            return 1; // usuário tem empréstimos
        }
    }
    return 0; // usuário não tem empréstimos
}

UserNode *deleteUser(UserNode *users, BookNode *books){
    char email[MAX_TEXT];
    askEmail(email);

    printDivider();

    if (userHasLoans(books, email)) {
        printf("\nERROR: Usuário possui emprestimos e não pode ser excluído!\n");
        return users;
    }

    UserNode *aux;
    UserNode *previous = NULL;

    for (aux=users; aux!=NULL; aux=aux->next) {
        if (strcmp(aux->data.email, email) == 0) {

            if (aux==users) {
                users = users->next;
            } else {
                previous->next = aux->next;
            }

            break;
        }

        previous = aux;
    }

    if(aux!=NULL) {
        free(aux);
        printf("\n=>Usuário '%s' excluído com sucesso.", email);
    } else {
        printf("\n=> usuário não encontrado.");
    }

    return users;
}

/*  LLM USE
    Utilizada para revisar as funções de remoção e cadastro, verificando possíveis 
    problemas relacionados à alocação dinâmica de memória e atualização dos
    ponteiros na lista simplesmente encadeada.
*/

void loanBook(BookNode *books, UserNode *users){
    int id = askBookId();
    BookNode *book = findBookById(books, id);

    printDivider();

    if (book == NULL) {
        printf("\nERROR: Livro não encontrado.\n");
        return;
    }

    if (book->data.status == LOANED) {
        printf("\nERROR: Livro já está emprestado para '%s'.\n", book->data.loanerEmail);
        return;
    }

    char email[MAX_TEXT];
    askEmail(email);
    UserNode *user = findUserByEmail(users, email);

    printDivider();

    if (user == NULL) {
        printf("\nERROR: Usuário não cadastrado.\n");
        return;
    }

    book->data.status = LOANED;
    strcpy(book->data.loanerEmail, email);

    printf("\nLivro ID %d emprestado para '%s' com sucesso!\n", book->data.id, email);
}

void returnBook(BookNode *books){
    int id = askBookId();
    BookNode *book = findBookById(books, id);

    printDivider();

    if (book == NULL) {
        printf("\nERROR: Livro não encontrado.\n");
        return;
    }

    if (book->data.status == AVAILABLE) {
        printf("\nERROR: Livro não está emprestado.\n");
        return;
    }

    book->data.status = AVAILABLE;
    strcpy(book->data.loanerEmail, "");

    printf("\nLivro ID %d devolvido com sucesso!\n", book->data.id);
}

int askBookId(){
    int id;
    printf(">>> Informe o ID do livro: ");
    scanf("%d", &id);
    limparBuffer();
    return id;
}

int askPublicationYear(){
    int year;
    printf(">>> Informe o ano de publicação: ");
    scanf("%d", &year);
    limparBuffer();
    return year;
}

void askEmail(char email[]){
    printf("\n");
    printf(">>> Informe o e-mail: ");
    fgets(email, MAX_TEXT, stdin);
    email[strcspn(email, "\n")] = '\0'; // tira o \n que o fgets deixa no final
}

void askName(char name[]){
    printf(">>> Informe o nome: ");
    fgets(name, MAX_TEXT, stdin);
    name[strcspn(name, "\n")] = '\0';
}

void askTitle(char title[]){
    printf("\n");
    printf(">>> Informe o título: ");
    fgets(title, MAX_TEXT, stdin);
    title[strcspn(title, "\n")] = '\0';
}

void askAuthor(char author[]){
    printf(">>> Informe o autor: ");
    fgets(author, MAX_TEXT, stdin);
    author[strcspn(author, "\n")] = '\0';
}

BookNode *freeBooks(BookNode *books){
    BookNode *aux;

    while (books != NULL) {
        aux = books;
        books = books->next;
        free(aux);
    }

    return books;
}

UserNode *freeUsers(UserNode *users){
    UserNode *aux;

    while (users != NULL) {
        aux = users;
        users = users->next;
        free(aux);
    }

    return users;
}

int generateBookId(int *nextId) {
    int id = *nextId;
    (*nextId)++;
    return id;
}
