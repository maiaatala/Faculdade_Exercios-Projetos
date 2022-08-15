#include "./pilhasEmVetor.h"

//Inicializa a pilha 
Pilha CriarPilhas(void){
  Pilha p;
  p.topoA = -1;       //Topo de uma pilha vazia
  p.topoB = maxSize;  //Outra extremidade da pilha (tamanho máximo)
  return p;
}

int ContarEspacosUsados(Pilha p){
  return (maxSize - p.topoB + (p.topoA + 1));  //Função que considera o tamanho máximo da pilha e
}                                              //calcula quantos espaços foram utilizados

int ContarEspacosLivres(Pilha p){
  return maxSize - ContarEspacosUsados(p);     //Funções que usam os espaços usados pra calcular os livre
}                                              //e se ainda pode empilhar elementos

boolean PodeEmpilhar(Pilha p){
  return (ContarEspacosLivres(p) > 0);
}


boolean vaziaA(Pilha p){                        //Retorna um valor booleano se as pilhas estão vazias
  return (p.topoA == -1);
}

boolean vaziaB(Pilha p){
  return (p.topoB == maxSize);
}

void ImprimePilha(Pilha p){
  int i;
  int espacosVazios = ContarEspacosLivres(p);
  
  printf("\npilha: \n");
  
  for(i = 0; i<= p.topoA; i ++){        //Loop for que percorre de os elementos da pilha, nesse caso
    printf("\t%.3f\n", p.vector[i]);    //imprimindo os valores contidos na pilha de um topo e de outro
  }

  for(i = 0; i < espacosVazios; i++){   
    printf("\t  --  \n");
  }

  for(i = p.topoB ; i < maxSize; i++ ){
    printf("\t%.3f\n", p.vector[i]);
  }  
}

void EmpilhaA(Pilha* p, float v){
  if(!PodeEmpilhar(*p)){
    printf("Pilha Cheia! Operacao nao concluida\n");    //Confere a disponibilidade a partir da função
    return;                                             //de empilhar
  }
  p->topoA++;               //Adiciona 1 no contador de topo
  p->vector[p->topoA] = v;  //Adiciona o valor desejado no topo
  printf("Operacao realizada com sucesso");
}

void EmpilhaB(Pilha* p, float v){
  if(!PodeEmpilhar(*p)){
    printf("Pilha Cheia! Operacao nao concluida\n");
    return;
  }
  p->topoB--;               //Remove na outra ponta
  p->vector[p->topoB] = v;
  printf("Operacao realizada com sucesso");
}

float DesempilhaA(Pilha* p){
  float v;
  
  if(vaziaA(*p)){
    printf("lado A da pilha ja esta vazio\n");      //Confere se tem o que ser desempilhado
    return 0;
  }
  v = p->vector[p->topoA--];    //Desempilha um item do topo
    return(v);
}

//A operação só é invertida para desempilhar na outra ponta
float DesempilhaB(Pilha* p){
  float v;
  
  if(vaziaB(*p)){
    printf("lado B da pilha ja esta vazio\n");
    return 0;
  }
  v = p->vector[p->topoB++];
    return(v);
}