#ifndef Lista_Atala
#define Lista_Atala

#include <stdio.h>
#include <stdlib.h>

//discounted booleans
typedef enum {False = 0, True = 1} boolean;

typedef struct no {
  int value;
  struct no* prox;
}No;

typedef struct lista{
  No* inicio;
}Lista;

// Cria a lista
Lista* criaLista(void);

// Insere elementos no comeco da lista
void insereLista(Lista* l, int v);

// Insere elementos no fim da lista, usada na funcao copiaLista
void insereListaFim(Lista* l, int v);

// Imprime a lista
void imprimeLista(Lista* l);

// Busca um valor na lista e retorna seu Endereco
No* buscaElemento(Lista* l, int v);

// Busca um valor na lista, com o diferencial de retornar o elemento anterior para facilitar na remocao. funcao usada em "removeElemento"
No* buscaElementoEAnterior(Lista* l, int v, No** ant);

// Remove um elemento na lista se o encontrar.
void removeElemento(Lista* l, int v);

// Libera todos os nos da lista e a deixa apontando pra NULL
void apagaLista(Lista* l);

// Copia os valores da lista origem para a lista destino
void copiaLista (Lista* origen, Lista* destino);

// Junta as duas listas em apenas uma
void concatenaLista (Lista* destino, Lista* agrupar);

#endif