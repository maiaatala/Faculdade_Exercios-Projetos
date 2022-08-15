#ifndef LISTA_H
#define LISTA_H

// replit @jeffersonparzano

struct aluno
{
    int matricula;
    // mais dados
};

typedef struct aluno Aluno;
typedef struct elemento Elemento; // a struct ta no .c
typedef struct lista Lista;

// iniciar lista
Lista *iniciar_lista();

int tamanho_lista(Lista l);

void inserir_lista(Lista *l, Aluno a);

// Imprimir lista
void imprime_lista(Lista *l);

// limpar a lista
void limpar_lista(Lista *l);

void excluir_lista(Lista *l);

#endif