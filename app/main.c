#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {
    printf("\n*****************************\n");
    printf("GERENCIAMENTO DE BIBLIOTECA\n");
    printf("*****************************\n");

    BookNode *books = NULL;
    UserNode *users = NULL;
    int nextBookId = 1;

    // Função temporária para testes de desenvolvmento
    //test(books, users, nextBookId);

    books = freeBooks(books);
    users = freeUsers(users);

    return 0;
}

void test(BookNode *books, UserNode *users, int nextBookId) {
    // BOOKS
    printf("\n=== TESTE CADASTRO DE LIVROS ===\n");
    books = registerBook(books, &nextBookId);
    books = registerBook(books, &nextBookId);

    printf("\n=== TESTE LISTAR LIVROS ===\n");
    listBooks(books);

    printf("\n=== TESTE BUSCAR LIVRO POR ID ===\n");
    int id = askBookId();
    BookNode *bookFound = findBookById(books, id);
    if (bookFound != NULL) {
        printBook(bookFound->data);
    } else {
        printf("\nLivro nao encontrado.\n");
    }

    printf("\n=== TESTE BUSCAR LIVROS POR AUTOR ===\n");
    char author[MAX_TEXT];
    askAuthor(author);
    findBooksByAuthor(books, author);

    // USERS
    printf("\n=== TESTE CADASTRO DE USUARIOS ===\n");
    users = registerUser(users);
    users = registerUser(users);

    printf("\n=== TESTE LISTAR USUARIOS ===\n");
    listUsers(users);

    printf("\n=== TESTE BUSCAR USUARIO POR EMAIL ===\n");
    char email[MAX_TEXT];
    askEmail(email);

    UserNode *userFound = findUserByEmail(users, email);
    if (userFound != NULL) {
        printUser(userFound->data);
    } else {
        printf("\nUsuario nao cadastrado.\n");
    }

    printf("\n=== TESTE BUSCAR USUARIOS POR NOME ===\n");
    char name[MAX_TEXT];
    askName(name);
    findUsersByName(users, name);
}
