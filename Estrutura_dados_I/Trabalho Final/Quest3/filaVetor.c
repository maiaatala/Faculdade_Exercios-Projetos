#include "./filaVetor.h"


Fila criarFila(void){           //Criação do nó com os valores de próximo e anterior, bem como com os
  Fila f;                       //atributos de cheio e vazio
  f.frente = 0;
  f.final = 0;
  f.estaCheia = False;
  f.estaVazia = True;
  return f;
}

boolean fila_vazia(Fila* f){
  return (f->estaVazia);        //Retorna o valor vazio
}

int incrementaVetor(int index){
  return (index+1)%maxSize;     //Incrementa no vetor a partir do tamanho máximo
}

int espacosLivres(Fila* f){
  int count, auxFinal, auxFrente;
  if (f->estaCheia){
    return 0;
  }
  auxFinal = f->final;          //Variáveis que são utilizados para "segurar" os valores do final e da frente de pilha
  auxFrente = f->frente;
  count = 0;
  
  do{
    auxFinal = incrementaVetor(auxFinal);   //O valor final passa pela função de incremento de vetor
    count++;                                
  }while(auxFinal != auxFrente);
  return count;                             //Retorna a contagem de elementos livres
}

void imprimeFila(Fila* f){
  int i = f->frente;
  printf("\nFila:\n");
  if(!f->estaVazia){    //Confere se está vazia e prossegue para o loop de impressão
    do{
      i = incrementaVetor(i);
      printf("\t%.3f\n",f->vector[i]);      //Utiliza a função de incremento para circular pela fila
    }while(i != f->final);
  }
  for(i = 0; i < espacosLivres(f); i++){
    printf("\t  --  \n");
  }
}

void insereFila(Fila* f, float v){
  f->estaVazia = False;
  if(f->estaCheia){
    printf("\nFila cheia, valor nao inserido\n");
    return;
  }
  f->final = incrementaVetor(f->final);         //Modifica o índice do final e depois adiciona o elemento no vetor
  f->vector[f->final] = v;

  if(f->final == f->frente){                    //Identifica se está cheia e sinaliza no atributo
    f->estaCheia = True;
  }
}

float removeFila(Fila* f){
  int valor;
  f->estaCheia = False;
  
  if(f->estaVazia){                             //Confere se está vazia e prossegue
    printf("\nFila vazia, nenhum valor foi retirado\n");
    return 0;
  }
  
  f->frente = incrementaVetor(f->frente);       //Incrementa o valor da frente e depois iguala o
  valor = f->vector[f->frente];                 //elemento anterior ao atual, removendo um da ponta

  if(f->frente == f->final){
    f->estaVazia = True;
  }
  return valor;
}