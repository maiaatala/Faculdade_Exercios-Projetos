#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct elemento {
    Aluno dados;
    Elemento* prox;
};

struct lista{
    Elemento* inicio;
    int qtd;
};

Lista* iniciar_lista(){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->qtd = 0;
    return l;
}

int tamanho_lista(Lista* l){
    return l-> qtd;
}


void inserir_lista (Lista* l, Aluno a){
    Elemento* novo = (Elemento* )malloc(sizeof(Elemento));
    novo->dados = a;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->qtd++;
}

void imprime_lista (Lista* l){
    Elemento* end = l->inicio;
    printf("Lista: \" ");
    while(end != NULL){
        printf("%i", end->dados.matricula);
        end = end->prox;
    }
    printf("\" \n");
}

void limpar_lista (Lista* l){
    Elemento *end = l->inicio;
    Elemento* apagar = NULL;
    while (end != NULL){
        apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
    l->qtd = 0;
}

void excluir_lista(Lista* l){
    limpar_lista(l);
    free(l);
}