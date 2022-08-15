#include "./Lista.h"

Lista* criaLista(void){
  Lista* f = (Lista*) malloc(sizeof(Lista));
  if (f==NULL){
    printf("\nComprar memoria.\n");
    exit(1);
  }
  f->inicio = NULL;
  return f;
}

void insereLista(Lista* l, int v){
  No* novoNo = (No*) malloc(sizeof(No));
  if (novoNo==NULL){
    printf("\nComprar memoria.\n");
    exit(1);
  }
  novoNo->value = v;
  novoNo->prox = l->inicio;
  //sempre insere no comeco
  l->inicio = novoNo;
  printf("\nvalor inserido com sucesso\n");
}

void insereListaFim(Lista* l, int v){
  No* novoNo = (No*) malloc(sizeof(No));
  No* curr = l->inicio;
  if (novoNo==NULL){
    printf("\nComprar memoria.\n");
    exit(1);
  }
  novoNo->value = v;
  //verifica se a lista esta vazia e insere o elemento no comeco
  if (curr == NULL){
    novoNo->prox = l->inicio;
    l->inicio = novoNo;
    return;
  }
  //procura o fim da fila para inserir o elemento no fim
  while(curr->prox != NULL){
    curr = curr->prox;
  }
  curr->prox = novoNo;
  novoNo->prox = NULL;
}

void imprimeLista(Lista* l){
  No *aux;
  for(aux = l->inicio; aux != NULL; aux = aux->prox){
    printf("\t%i\n",aux->value);
  }
}

//funcao ira retornar NULL caso o elemento nao for encontrado
No* buscaElemento(Lista* l, int v){
  No* aux = l->inicio;
  
  while (aux != NULL && aux->value != v){
    aux = aux->prox;
  }
  return aux;
}


No* buscaElementoEAnterior(Lista* l, int v, No** ant){
  //precisa passar o ponteiro para o ponteiro anterior;
  No* aux = l->inicio;
  *ant = NULL;
  while (aux != NULL && aux->value != v){
    //armazena o no anterior ao elemento desejado
    *ant = aux;
    aux = aux->prox;
  }
  return aux;
}

void removeElemento(Lista* l, int v){
  No* elemAnterior;
  No* elemRemover = buscaElementoEAnterior(l, v, &elemAnterior);
  if(elemRemover == NULL){
    printf("\nElemento nao exista na lista\n");
    return;
  }
  //se o elemento anterior for nulo, significa que queremos retirar o primeiro elemento da lista, e devemos aponta-la corretamente para um novo primeiro no.
  if(elemAnterior == NULL){
    l->inicio = elemRemover->prox;
  }else{
    //elemento a ser removido esta no meio da lista
    elemAnterior->prox = elemRemover->prox;
  }
  free(elemRemover); // apaga o elemento da memoria
  printf("\nElemento removido com sucesso da lista\n");
}

void apagaLista(Lista* l){
  No* curr = l->inicio;
  //enquanto houver elementos, libere eles da memoria
  while (curr != NULL){
    No* prox = curr->prox;
    free(curr);
    curr = prox;
  }
  free(curr);
  //apaga os elementos da lista, mas nao apaga a lista
  l->inicio = NULL;
}

void copiaLista (Lista* origen, Lista* destino){
  apagaLista(destino); //apaga a lista de destino para nao ter "lixo" nela ou no heap.
  No* aux = origen->inicio;
  while (aux != NULL){
    // a copia e feita inserindo elementos no fim da lista destino, para que eles sejam uma copia, e nao uma referencia.
    insereListaFim(destino, aux->value);
    aux = aux->prox;
  }
  printf("\nLista Copiada com sucesso.\n");
}

// funcao vai por o comeco da lista 2 ultimo elemento->prox da lista 1
void concatenaLista (Lista* destino, Lista* agrupar){
  No* fim = destino->inicio;
  while(fim->prox != NULL && fim != NULL){
    fim = fim->prox;
  }
  fim->prox = agrupar->inicio;
  // faz com que a lista 2 nao aponte para a metade da lista 1 agora concatenada
  agrupar->inicio = NULL;
  printf("\nLista concatenada com sucesso.\n");
}