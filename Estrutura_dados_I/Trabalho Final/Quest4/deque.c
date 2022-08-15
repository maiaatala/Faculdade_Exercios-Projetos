#include "./deque.h"

Deque* criaDeque(void){
  Deque* d = (Deque*) malloc(sizeof(Deque));        //Cria o deque alocando a memória necessária para o TAD
  if (d == NULL){
    printf("\nPor favor, comprar mais memoria.\n");
    exit(1);
  }
  d->ini = d->fim = NULL;       //Atribui os valores de início e fim da pilha, NULL por estar vazia
  return d;
}

boolean estaVazio(Deque* d){    //Flag booleano para identificar se está vazio ou não
  return( d->ini == NULL );
}

void imprimeComecoFim (Deque* d){
  No* aux;
  printf("\nDeque comeco -> fim:\n");
  for (aux = d->ini; aux != NULL; aux = aux->prox){     //Percorre os elementos do começo ao fim do deque
    printf("\t%c", aux->letter);
  }
  printf("\n");
}

void imprimeFimComeco (Deque* d){
  No* aux;
  printf("\nDeque fim -> comeco:\n");
  for(aux = d->fim; aux != NULL; aux = aux->ant){       //Faz o inverso 
    printf("\t%c", aux->letter);
  }
  printf("\n");
}

No* auxiliarInsereInicio(No* ini, char c){
  No* novo = (No*) malloc(sizeof(No));
  novo->letter = c;
  novo->prox = ini;
  novo->ant = NULL;
  //verifica se a lista tinha conteudo
  if(ini != NULL){
    //associa o elemento novo correntamente na ordem.
    ini->ant = novo;
  }
  return novo;
}

void insereInicio(Deque* d, char c){
  d->ini = auxiliarInsereInicio(d->ini, c); //Modifica o início da pilha com o resultado da função anterior
  if (d->fim == NULL){
    d->fim = d->ini;
  }
  printf("\nChar inserido no comeco com sucesso\n");
}

No* auxiliarInsereFim(No* fim, char c){
  No* novo = (No*) malloc(sizeof(No));
  novo->letter = c;
  novo->prox = NULL;
  novo->ant = fim;
  //verifica se a lista tinha conteudo
  if(fim != NULL){
    //associa o elemento novo correntamente na ordem.
    fim->prox = novo;
  }
  return novo;
}

void insereFim(Deque* d, char c){
  d->fim = auxiliarInsereFim(d->fim, c);
  if (d->ini == NULL){
    d->ini = d->fim;
  }
  printf("\nChar inserido no fim com sucesso\n");
}

No* auxiliarRetiraInicio(No* ini){
  No* novoInicio = ini->prox;
  //verifica se a lista ficou vazia
  if(novoInicio != NULL){
    novoInicio->ant = NULL;     //Se estiver vazio, o novo início deve ser NULL
  }
  free(ini);
  return novoInicio;
}

char retiraInicio (Deque* d){
  char c;
  if (estaVazio(d)){
    printf("\nfila Vazia, nada foi retirado.\n");
    return '\0';
  }
  c = d->ini->letter;       //Faz a atribuição dos elementos reduzindo um na contagem total
  d->ini = auxiliarRetiraInicio(d->ini);
  //verifica se a lista ficou vazia
  if (d->ini == NULL){
    d->fim = NULL;
  }
  return c;
}


No* auxiliarRetiraFim(No* fim){
  No* novoFim = fim->ant;
  //verifica se a lista ficou vazia
  if(novoFim != NULL){
    novoFim->prox = NULL;
  }
  free(fim);
  return novoFim;
}

char retiraFim (Deque* d){
  char c;
  if (estaVazio(d)){
    printf("\nfila Vazia, nada foi retirado.\n");
    return '\0';
  }
  c = d->fim->letter;
  d->fim = auxiliarRetiraFim(d->fim);
  //verifica se a lista ficou vazia
  if (d->fim == NULL){
    d->ini = NULL;
  }
  return c;
}

boolean ehSimetrico(Deque* d){
  boolean flag = True;
  if (estaVazio(d)){
    return False;
  }

  No* esq = d->ini;   //Realiza a contagem de elementos do lado esquerdo e direito, a partir do número
  No* dir = d->fim;   //de elementos inseridos nas pontas

  while(esq != dir){
    if (esq->letter != dir->letter){        //Verifica se os valores de dir e esq são iguais ou não
      flag = False;
      break;
    }
    esq = esq->prox;
    if (esq == dir){
      break;
    }
    dir = dir->ant;
  }
  return flag;
}

void liberaDeque(Deque*d){
  // armazena o elemento atual
  No* curr = d->ini;
  //loop nos elementos da fila
  while (curr != NULL){
    //armazena o prox elemento
    No* next = curr->prox;
    free (curr);
    curr = next;
  }
  //apaga a fila
  free(d);
}