#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_TEXT 100

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

    return option;
}

/*  LLM USE:
    Utilizada para gerar a implementação base das funções dos menus.
    O auxílio consistiu na criação de funções com estrutura semelhante,
    alterando apenas as opções apresentadas em cada submenu.
*/

BookNode *registerBook(BookNode *books, int *nextId){
    BookNode *new = (BookNode*) malloc(sizeof(BookNode));

    new->data.id = generateBookId(nextId); // incremental automaticamente
    new->data.status = AVAILABLE; // default status
    strcpy(new->data.loanerEmail, ""); // default é vazio

    printf("\n");
    askTitle(new->data.title);
    askAuthor(new->data.author);
    new->data.publicationYear = askPublicationYear();

    // Adiciona sempre no início da lista
    new->next = books;
    books = new;

    printf("\nLivro ID %d cadastrado com sucesso!\n", new->data.id);

    return books;
}

UserNode *registerUser(UserNode *users){
    //Pede email e nome.
    //Antes de cadastrar, verifica se o email já existe usando findUserByEmail.
    //Se não existir, aloca um novo nó, insere na lista e retorna a lista atualizada.

    // Deve:
    // pedir os dados necessários (conforme definido na struct criada)
    // email deve ser unico => validar

    return users;
}

void listBooks(BookNode *books){
    //Percorre a lista de livros e imprime todos os dados de cada livro.
}

BookNode *findBookById(BookNode *books, int id){
    //Percorre a lista de livros procurando um livro com o ID recebido. 
    // Retorna o ponteiro para o nó encontrado ou NULL.
    return books;
}

void findBooksByAuthor(BookNode *books, char author[]){
    //Percorre a lista e imprime todos os livros cujo autor seja igual ao autor recebido. 
    // Se não encontrar nenhum, mostra “Livro não encontrado”.    
}

void listUsers(UserNode *users){
    //Percorre a lista de usuários e imprime email e nome de cada usuário.
}

UserNode *findUserByEmail(UserNode *users, char email[]){
    //Percorre a lista de usuários procurando o email recebido. 
    // Retorna o ponteiro para o nó encontrado ou NULL.
    return users;
}

void findUsersByName(UserNode *users, char name[]){
    //Percorre a lista e imprime todos os usuários cujo nome seja igual ao nome recebido.
    //Se não encontrar nenhum, mostra “Usuário não cadastrado”.
}

void findLoansByEmail(BookNode *books, char email[]){
    //Percorre a lista de livros e imprime todos os livros com status == LOANED e loanerEmail igual ao email recebido.
}

void updateBook(BookNode *books){
    //Pede o ID do livro, busca com findBookById. 
    //Se encontrar, permite alterar título, autor e ano de publicação.
}

void updateUser(UserNode *users){
    //Pede o email do usuário, busca com findUserByEmail.
    //Se encontrar, permite alterar o nome.
}

BookNode *deleteBook(BookNode *books){
    //Pede o ID, procura o livro na lista, remove o nó com free e retorna a lista atualizada.
    //Precisa tratar quando o livro removido é o primeiro nó.   
    //Só permite excluir se o livro não estiver emprestado. 
    return books;
}

int userHasLoans(BookNode *books, char email[]) {
    //Verifica se usuário tem empréstimos
    return 0;
}

UserNode *deleteUser(UserNode *users, BookNode *books){
    //Pede o email, procura o usuário na lista, remove o nó com free e retorna a lista atualizada.
    //Precisa tratar quando o usuário removido é o primeiro nó.
    //Só permite excluir se usuário não tiver empréstimos (userHasLoans)
    return users;
}

void loanBook(BookNode *books, UserNode *users){
    //Pede o ID do livro. Se o livro existir e estiver AVAILABLE, pede o email do usuário. 
    //Se o usuário existir, muda o livro para LOANED e copia o email para loanerEmail.
}

void returnBook(BookNode *books){
    //Pede o ID do livro. Se o livro existir e estiver LOANED, muda o status para AVAILABLE e limpa loanerEmail.
}

int askBookId(){
    int id;
    printf(">>> Informe o ID do livro: ");
    scanf("%d", &id);
    return id;
}

int askPublicationYear(){
    int year;
    printf(">>> Informe o ano de publicação: ");
    scanf("%d", &year);
    return year;
}

void askEmail(char email[]){
    //Pede um email e salva no vetor recebido.
}

void askName(char name[]){
    //Pede um nome e salva no vetor recebido.
}

void askTitle(char title[]){
    printf(">>> Informe o título: ");
    scanf(" %99[^\n]", title);
}

void askAuthor(char author[]){
    printf(">>> Informe o autor: ");
    scanf(" %99[^\n]", author);
}

/*
    LLM USE:
    Utilizada para sugerir o formato de leitura scanf(" %99[^\n]", ...).
    Permite ler linhas completas até o ENTER, incluindo espaços, sem a necessidade do fgets().
    Limita a entrada a 99 caracteres para evitar overflow.
*/

BookNode *freeBooks(BookNode *books){
    //Percorre a lista de livros, libera todos os nós com free e retorna NULL.
    return books;
}

UserNode *freeUsers(UserNode *users){
    //Percorre a lista de usuários, libera todos os nós com free e retorna NULL.
    return users;
}

int generateBookId(int *nextId) {
    int id = *nextId;
    (*nextId)++;
    return id;
}
