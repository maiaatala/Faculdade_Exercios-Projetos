#include <stdlib.h>
#include <stdio.h>
#include "ascii_acentos.h"

/* 31) Faça um algoritmo, em pseudocódigo do Visualg ou na Linguagem C, que leia um valor N (N <= 20) e os N valores de uma variável composta. Ordene os valores recebidos em forma crescente e imprima a variável composta ordenada */

int main(){
    
    int N, i, j, menor;
    float *vetor, temp;

    system ("cls");
    
    printf ("\nPrograma para ordenar um vetor de entrada\n");
    printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");

    printf ("Informe quantos numeros, de 0 a 20, deseja inserir: ");
    scanf ("%i", &N);
    //bloco de verificação de N
    while ((N < 0) || (N>20)){
        printf ("O valor deve ser entre 0 e 20: ");
        scanf ("%i", &N);
    }

    vetor = (float *) malloc(N * sizeof(float)); //cria um vetor usando a memoria do heap

    //entrada de dados
    for (i = 0; i < N; i++){
        printf ("Insira o %i%c Valor: ", i+1, m_o);
        scanf ("%f", &vetor[i]);
    }
    
    //processamento de dados
    for (i = 0; i < N; i++){
        temp = vetor[i]; //armazena o valor que esta na posicao i
        menor = i; //começa na posicao i
        for (j = i; j < N; j++){
            if (vetor[j] < vetor[menor]){ //verifica se a posicao j e menor que a antiga posicao
                menor = j; //armazena onde esta o menor valor
            }
        }
        vetor[i] = vetor[menor]; //passa o valor menor para o lugar de i
        vetor[menor] = temp; //passa o antigo valor de i para a posicao onde encontra-se o menor valor
    }
    
    //saida de dados
    printf ("\n--><--><--><--><--\n");
    printf ("Vetor ordenado: \n");
    for (i = 0; i < N; i++){
        printf ("%.2f\n",vetor[i]);
    }
    printf ("\n--><--><--><--><--\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    free(vetor); //libera a memoria do heap
    return 0;
}