#ifndef LISTA_H
#define LISTA_H

#define MAX 50 // tamanho

typedef struct aluno
{
    int matricula;
    // MAIS DADOS
} Aluno; // tipo dado

struct lista
{
    int qtd;          // quantidade de valores armazenados atualmente
    Aluno dados[MAX]; // vetor dados de tipo aluno
};

typedef struct lista Lista;

// Criar lista
Lista *criarLista();

// Inserir um elemento na lista
int inserirLista(lista *l, Aluno a); // int para se os dados foram inseridos ou nao

// verificar tamanho da lista
int tamanhoLista(Lista *l);

// imprimir lista
void exibirLista(Lista *l);

// excluir a lista
void excluirLista(Lista *l);

// Excluir um elemento da lista
int excluirElementoLisa(Lista *l, Aluno a);

// Busca Linear
int buscaLinear(Lista *l, int m);

#endif