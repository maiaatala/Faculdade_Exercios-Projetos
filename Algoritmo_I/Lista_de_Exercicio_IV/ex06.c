#include <stdlib.h>
#include <stdio.h>
#include "ascii_acentos.h"

/* 6) Escreva um algoritmo, em pseudocódigo do Visualg ou na Linguagem C, que armazene em um vetor todos os números múltiplos de 5, no intervalo fechado de 1 a 500. Após isso, o algoritmo deve imprimir todos os valores armazenados. */

#define range 500 
#define size (range/5) //tamanho do vetor vai ser o range/multiplo

int main(){

    int i, c = 0, vetor[size];

    system ("cls");

    printf ("\nPrograma para armazenar os m%cltiplos de 5 entre 1 e 500\n", u_a);
    printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");

    //bloco para achar e armazenar os numeros multiplos de 5
    for (i = 1; i <= range; i++){
        if (i % 5 == 0){
            vetor[c] = i;
            c++;
        }
    }
    //bloco para imprimir os multiplos
    printf ("\n--><--><--><--><--><--><--><--><--><--><--><--><--\n");
    printf ("\t\tM%cltiplos de 5:\n", u_a);
    for (c = 0; c < size; c++){
        printf ("%-5i", vetor[c]);
        if ((c+1) % 10 == 0){
            printf ("\n");
        }
    }
    printf ("--><--><--><--><--><--><--><--><--><--><--><--><--\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}