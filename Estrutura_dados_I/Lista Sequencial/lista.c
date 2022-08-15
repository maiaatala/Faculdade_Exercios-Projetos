#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// criar a lista
Lista* criarLista (){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if (l!=NULL){
        l->qtd = 0;
    }
    return l;
}

int inserirLista (Lista *l, Aluno a){
    if(l->qtd == MAX){
        return 0;
    }
    l->dados[l->qtd++] = a;
    return l;
}

int tamanhoLista (Lista *l){
    return l->qtd;
}

//excluir a lista
void excluirLista (Lista *l){
    free(l);
}

//excluir um elemento da list
int excluirElementoLista (Lista *l, Aluno a){
    int posicao;
    posicao = buscaLinear(l, a.matricula);
    if(posicao <0){
        return 0;
    }
    for (int i =posicao; i< l->qtd;i++){
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
    return l;
}


int buscaLinear (Lista *l, int m ){
}