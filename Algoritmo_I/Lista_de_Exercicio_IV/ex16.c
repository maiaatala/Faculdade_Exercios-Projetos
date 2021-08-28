#include <stdlib.h>
#include <stdio.h>
#include "ascii_acentos.h"

/* 16) Escreva um algoritmo, em pseudocódigo do Visualg ou na Linguagem C,
que receba a altura de 10 atletas. Esse algoritmo deve imprimir a
altura daqueles atletas que tem altura maior que a média. */

int main(){

    int i;
    float vetor[10], media = 0;

    system ("cls");

    printf ("\nPrograma para verificar a altura de atletas\n", eh);
    printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");

    //bloco de entrada
    for (i = 0; i < 10; i++){
        printf ("Informe a altura do %2i%c atleta: ", i+1, m_o);
        scanf  ("%f", &vetor[i]);
        while (vetor[i] < 0){
            printf ("n%co existe altura negativa,\ninforme a altura correta: ", a_t);
            scanf ("%f", &vetor[i]);
        }
        media += vetor[i];
    }
    //bloco para imprimir o resultado
    media /= 10;
    printf ("\n\n--><--><--><--><--><--><--><--><--><--\n");
    printf ("A altura m%cdia %c: %.2f\n", eh, eh, media);
    printf ("Atletas com altura maior que a m%cdia: \n",eh);
    for (i = 0; i < 10; i++){
        if (vetor[i] > media){
            printf ("O %2i%c atleta com altura de: %4.2f\n", i+1, m_o, vetor[i]);
        }
    }
    printf ("--><--><--><--><--><--><--><--><--><--\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}