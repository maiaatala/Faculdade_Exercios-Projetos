#include <stdlib.h>
#include <stdio.h>
#include "ascii_acentos.h"

/* 11) Escreva um algoritmo, em pseudocódigo do Visualg ou na Linguagem C,
que receba dez números do usuário e armazene em um vetor a metade de cada número.
Após isso, o algoritmo deve imprimir todos os valores armazenados. */

int main(){

    int i;
    float vetor[10];

    system ("cls");

    printf ("\nPrograma para armazenar em um vetor os input do usu%crio\n", a_a);
    printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");

    //bloco de entrada
    for (i = 0; i < 10; i++){
        printf ("insira o %2i%c n%cmero: ", i+1, m_o, u_a);
        scanf  ("%f", &vetor[i]);
        vetor[i] /= 2;
    }

    //bloco para imprimir o resultado
    printf ("\n\n--><--><--><--><--><--><--><--\n");
    for (i = 0; i < 10; i++){
        printf ("metade do %2i%c n%cmero: %.2f\n", i+1, m_o, u_a, vetor[i]);
    }
    printf ("--><--><--><--><--><--><--><--\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}