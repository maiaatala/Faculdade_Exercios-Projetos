#include <stdlib.h>
#include <stdio.h>
#include "ascii_acentos.h"

/* 1) Escreva um algoritmo, em pseudocódigo do Visualg ou na Linguagem C,
que armazene em um vetor todos os números inteiros de 0 a 50.
Após isso, o algoritmo deve imprimir todos os valores armazenados. */

int main(){

    int i, vetor[51];

    system ("cls");

    printf ("\nPrograma para armazenar, em um vetor, os n%cmeros de 0 a 50\n",u_a);
    printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");

    //bloco para escrever os valores de 0 a 50
    for (i = 0; i < 51; i++){
        vetor[i] = i;
    }

    printf ("\n--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--\n");
    printf ("\t\t\t\tN%cmeros de 0 a 50: \n", u_a);
    //bloco para mostrar os valores do vetor
    for (i = 0; i < 51; i++){
        printf ("%-5i", vetor[i]);
        if ((i+1) % 17 == 0){
            printf ("\n");
        }
    }
    printf ("--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--><--\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}