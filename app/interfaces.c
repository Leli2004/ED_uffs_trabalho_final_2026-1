#include <stdio.h>
#include <stdlib.h>
#include "interfaces.h"

void showMainMenu(){
    //Mostra o menu principal e controla as opções: cadastro, consulta, atualização, exclusão, empréstimo, devolução e sair.
}

void showRegistrationMenu(){
    //Mostra o submenu de cadastro: cadastrar livro, cadastrar usuário ou voltar.
}

void showSearchMenu(){
    //Mostra o submenu de consulta: livros, usuários, empréstimos ou voltar.
}

void showUpdateMenu(){
    //Mostra o submenu de atualização: atualizar livro, atualizar usuário ou voltar.
}

void showDeleteMenu(){
    //Mostra o submenu de exclusão: excluir livro, excluir usuário ou voltar.
}

BookNode *registerBook(BookNode *books, int *nextId){
    //Aloca um novo nó com malloc, pede título, autor e ano. O ID deve vir de *nextId.
    //O status inicia como AVAILABLE e loanerEmail inicia vazio. 
    //Insere o livro na lista e retorna a lista atualizada.
}

UserNode *registerUser(UserNode *users){
    //Pede email e nome.
    //Antes de cadastrar, verifica se o email já existe usando findUserByEmail.
    //Se não existir, aloca um novo nó, insere na lista e retorna a lista atualizada.
}

void listBooks(BookNode *books){
    //Percorre a lista de livros e imprime todos os dados de cada livro.
}

BookNode *findBookById(BookNode *books, int id){
    //Percorre a lista de livros procurando um livro com o ID recebido. 
    // Retorna o ponteiro para o nó encontrado ou NULL.
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
}

void findUsersByName(UserNode *users, char name[]){
    //Percorre a lista e imprime todos os usuários cujo nome seja igual ao nome recebido.
    //Se não encontrar nenhum, mostra “User not registered”.
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
}

UserNode *deleteUser(UserNode *users){
    //Pede o email, procura o usuário na lista, remove o nó com free e retorna a lista atualizada.
    //Precisa tratar quando o usuário removido é o primeiro nó.
}

void loanBook(BookNode *books, UserNode *users){
    //Pede o ID do livro. Se o livro existir e estiver AVAILABLE, pede o email do usuário. 
    //Se o usuário existir, muda o livro para LOANED e copia o email para loanerEmail.
}

void returnBook(BookNode *books){
    //Pede o ID do livro. Se o livro existir e estiver LOANED, muda o status para AVAILABLE e limpa loanerEmail.
}

int askBookId(){
    //Pede e retorna um ID de livro.
}

int askPublicationYear(){
    //Pede e retorna o ano de publicação.
}

void askEmail(char email[]){
    //Pede um email e salva no vetor recebido.
}

void askName(char name[]){
    //Pede um nome e salva no vetor recebido.
}

void askTitle(char title[]){
    //Pede um título e salva no vetor recebido.
}

void askAuthor(char author[]){
    //Pede um autor e salva no vetor recebido.
}

BookNode *freeBooks(BookNode *books){
    //Percorre a lista de livros, libera todos os nós com free e retorna NULL.
}

UserNode *freeUsers(UserNode *users){
    //Percorre a lista de usuários, libera todos os nós com free e retorna NULL.
}
