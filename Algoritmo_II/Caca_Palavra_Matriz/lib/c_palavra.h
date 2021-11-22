#ifndef CALC_H
#define CALC_H

// lib lists
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define c_max 10

typedef enum { false, true } bool;

/* struct que armazena a matriz do jogo e a palavra
char M[c_max][c_max]
bool m_exists
char word[c_max]*/
typedef struct Jogo{
    char m[c_max][c_max];
    bool m_exists;
    char word[c_max];
}Jogo;

/*Versão Atala™ do fflush*/
void clean_stdin();

/*Versão Atala™ do system("pause")*/
void pause();

/*Versão Atala™ do strlen
recebe uma string
retorna um int*/
unsigned int str_len(const char *s);

/*Gera o caça palavras usando numeros aleatorios
recebe Jogo
retorna Jogo*/
Jogo generate(Jogo M);

/*Le a matriz atraves do stdin
recebe Jogo
retorna Jogo*/
Jogo input_Jogo(Jogo M);

/*Mostra o caça palavras atual, com grid das linhas e colunas
recebe Jogo*/
void show(Jogo M);

/*Le a palavra a ser procurada do stdin
recebe Jogo
retorna Jogo*/
Jogo nova_palavra(Jogo M);

/*Faz a busca esquerda -> direita
recebe Jogo*/
void esqdir(Jogo M);

/*Faz a busca direita -> esquerda
recebe Jogo*/
void diresq(Jogo M);

/*Faz a busca Cima -> Baixo
recebe Jogo*/
void cimabaixo(Jogo M);

/*Faz a busca Baixo -> Cima
recebe Jogo*/
void baixocima(Jogo M);

/*Faz a busca inferior esquerda -> superior direita
recebe Jogo*/
void diagsupdir(Jogo M);

/*Faz a busca superior esquerda -> inferior direita
recebe Jogo*/
void diaginfdir(Jogo M);

/*Faz a busca inferior direita -> superior esquerda
recebe Jogo*/
void diagsupesq(Jogo M);

/*Faz a busca superior direita -> inferior esquerda
recebe Jogo*/
void diaginfesq(Jogo M);

// roda todas as funcoes de busca
void pesquisa(Jogo M);


#endif