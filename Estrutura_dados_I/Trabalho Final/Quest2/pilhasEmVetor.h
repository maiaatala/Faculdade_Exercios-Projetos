#include <stdio.h>
#include <stdlib.h>

#define maxSize 10

//Declaração de um nó
typedef struct pilha{           
  float vector[maxSize];  //Tamanho máximo da pilha
  int topoA;              //Topos da pilha  
  int topoB;
}Pilha;

//discounted booleans
typedef enum {False = 0, True = 1} boolean;

//Cria a struct para as pilhas
Pilha CriarPilhas(void);

//Exibe a Pilha
void ImprimePilha(Pilha p);

//retorna a quantidade de espacos livres no vetor
int ContarEspacosLivres(Pilha p);

//retorna a quantidade de espacos usadnos no vetor
int ContarEspacosUsados(Pilha p);

//Retorna verdadeiro se a pilha A estiver vazia
boolean vaziaA(Pilha p);

//Retorna verdadeiro se a pilha B estiver vazia
boolean vaziaB(Pilha p);

//Retorna verdadeiro se tiver espaco no vetor para o procedimento de empilhar
boolean PodeEmpilhar(Pilha p);

//Realiza o processo de empilhar pelo lado A
void EmpilhaA(Pilha* p, float v);

//Realiza o processo de empilhar pelo lado B
void EmpilhaB(Pilha* p, float v);

//Realiza o processo de desempilhar pelo lado A
float DesempilhaA(Pilha* p);

//Realiza o processo de desempilhar pelo lado B
float DesempilhaB(Pilha* p);