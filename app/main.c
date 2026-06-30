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

    int option;
    // LLM USE: utilizada para montar a estrutura do switch/case do loop
    // principal, conectando cada opção do menu (e seus submenus) às
    // funções já implementadas em library.c.
    do {
        option = getMainMenu();

        switch (option) {
            case 1: { // Cadastro
                int sub = getRegistrationMenu();
                if (sub == 1) {
                    books = registerBook(books, &nextBookId);
                } else if (sub == 2) {
                    users = registerUser(users);
                }
                break;
            }
            case 2: { // Consulta
                int sub = getSearchMenu();
                if (sub == 1) {
                    int searchOption;
                    printf("\nBuscar por: 1 - Codigo | 2 - Autor\n");
                    printf("Digite a opção escolhida: ");
                    scanf("%d", &searchOption);

                    if (searchOption == 1) {
                        int id = askBookId();
                        BookNode *found = findBookById(books, id);
                        if (found != NULL) {
                            printBook(found->data);
                        } else {
                            printf("\nLivro nao encontrado\n");
                        }
                    } else if (searchOption == 2) {
                        char author[MAX_TEXT];
                        askAuthor(author);
                        findBooksByAuthor(books, author);
                    }
                } else if (sub == 2) {
                    int searchOption;
                    printf("\nBuscar por: 1 - Email | 2 - Nome\n");
                    printf("Digite a opção escolhida: ");
                    scanf("%d", &searchOption);

                    if (searchOption == 1) {
                        char email[MAX_TEXT];
                        askEmail(email);
                        UserNode *found = findUserByEmail(users, email);
                        if (found != NULL) {
                            printUser(found->data);
                        } else {
                            printf("\nUsuario nao cadastrado\n");
                        }
                    } else if (searchOption == 2) {
                        char name[MAX_TEXT];
                        askName(name);
                        findUsersByName(users, name);
                    }
                } else if (sub == 3) {
                    char email[MAX_TEXT];
                    askEmail(email);
                    findLoansByEmail(books, email);
                }
                break;
            }
            case 3: { // Atualização
                int sub = getUpdateMenu();
                if (sub == 1) {
                    updateBook(books);
                } else if (sub == 2) {
                    updateUser(users);
                }
                break;
            }
            case 4: { // Exclusão
                int sub = getDeleteMenu();
                if (sub == 1) {
                    books = deleteBook(books);
                } else if (sub == 2) {
                    users = deleteUser(users, books);
                }
                break;
            }
            case 5: // Empréstimo
                loanBook(books, users);
                break;
            case 6: // Devolução
                returnBook(books);
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while (option != 0);

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
