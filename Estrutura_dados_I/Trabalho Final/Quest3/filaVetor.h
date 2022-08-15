#include <stdio.h>
#include <stdlib.h>

//discounted booleans
typedef enum {False = 0, True = 1} boolean;

#define maxSize 10

typedef struct fila{
  float vector[maxSize];
  int frente;
  int final;
  boolean estaCheia;
  boolean estaVazia;
}Fila;

// funcao para criar uma fila apontado para NULL
Fila criarFila(void);

// funcao auxiliar usada para incrementar a posicao do vetor sem sair do vetor
int incrementaVetor(int index);

// conta quantos espacos livres tem no vetor
int espacosLivres(Fila* f);

// funcao imprime a fila
void imprimeFila(Fila* f);

// funcao retorna verdadeiro se a fila estiver vazia
boolean fila_vazia(Fila* f);

// funcao insere um elemento no fim da fila
void insereFila(Fila* f, float v);

// funcao remove um valor do comeco da fila
float removeFila(Fila* f);