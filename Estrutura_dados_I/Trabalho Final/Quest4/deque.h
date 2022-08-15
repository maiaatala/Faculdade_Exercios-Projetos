#include <stdio.h>
#include <stdlib.h>

// discounted booleans
typedef enum
{
  False = 0,
  True = 1
} boolean;

typedef struct no
{
  char letter;
  struct no *prox;
  struct no *ant;
} No;

typedef struct deque
{
  No *ini;
  No *fim;
} Deque;

// cria um deque apontando para nulo (vazio)
Deque *criaDeque(void);

// funcao retorna true se o deque estiver vazio
boolean estaVazio(Deque *d);

// funcao para imprimir do comeco pro fim
void imprimeComecoFim(Deque *d);
// funcao para imprimir do fim para o comeco
void imprimeFimComeco(Deque *d);

// funcao que auxilia a funcao insereInicio
No *auxiliarInsereInicio(No *ini, char c);
// Insere um novo no no comeco do deque
void insereInicio(Deque *d, char c);

// funcao que auxilia a funcao insereFim
No *auxiliarInsereFim(No *fim, char c);
// insere um novo no no fim do deque
void insereFim(Deque *d, char c);

// funcao que auxilia a funcao retiraInicio
No *auxiliarRetiraInicio(No *ini);
// Remove um no do comeco do deque
char retiraInicio(Deque *d);

// funcao que auxilia a funcao retiraFim
No *auxiliarRetiraFim(No *fim);
// remove um No do fim do deque
char retiraFim(Deque *d);

// funcao retorna true se os chars no deque no deque representam uma palavra palindromo.
boolean ehSimetrico(Deque *d);

// libera o deque
void liberaDeque(Deque *d);