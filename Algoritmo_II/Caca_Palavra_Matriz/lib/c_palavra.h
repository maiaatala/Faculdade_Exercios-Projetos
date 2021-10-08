#ifndef CALC_H
#define CALC_H

// lib lists
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// #include <stdbool.h>

#define c_max 10

typedef enum { false, true } bool;
// methods prototype lists
// Jogo struct


// lines and column struct
// typedef struct where{
//     int l;
//     int c;
// }where;

// caça palavras
typedef struct search{
    char word[c_max];
    bool w_exists;
    // where esq_dir;
    // where dir_esq;
    // where top_down;
    // where down_top;
    // where cross_up;
    // where cross_down;
}search;

typedef struct Jogo{
    char m[c_max][c_max];
    bool m_exists;
    search caca;
}Jogo;

// inits/resets the structs
Jogo init_struct(Jogo M, char op);
// Generates a random 10x10 Jogo
Jogo generate(Jogo M);
// inputs the 10x10 matriz
Jogo input_Jogo(Jogo M);
// prints a 10x10 Jogo
void show(Jogo M);
// inputs the word to search for
Jogo nova_palavra(Jogo M);
// does and shows the search esq->dir
void esqdir(Jogo M);
// does and shows the search dir->esq
void diresq(Jogo M);
// does and shows the search top->down
void cimabaixo(Jogo M);
// does and shows the search down->top
void baixocima(Jogo M);
// does and shows the search vertically down left->up right
void diagsupdir(Jogo M);
// does and shows the search vertically down right->up left
void diagsupesq(Jogo M);
// does and shows the search vertically up right -> left down
void diaginfesq(Jogo M);
// does and shows the search vertically up left -> right down
void diaginfdir(Jogo M);
// calls all the search void
void pesquisa(Jogo M);

#endif