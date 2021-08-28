#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/* 1) Escreva um algoritmo em PORTUGOL que imprima todos
os números múltiplos de 5, no intervalo fechado de 1 a 500. */

int main (){
    int i, multiplo;

    system ("cls");
    printf ("\nPrograma para imprimir todos os m%cltiplos de x em um intervalo de 1 a 500\n", u_a);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("Escreva qual o m%cltiplo desejado: ", u_a);
    scanf  ("%d", &multiplo);

    printf ("\n\nM%cltiplos de %d existentes entre 1 e 500:\n", u_a, multiplo);
    printf ("->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");
    for (i = 1; i <= 500; i++){
        if (i % multiplo == 0){
            printf ("%d,\t", i);
        }
        if (i % (10*multiplo) == 0){
            /* bloco para formatação */
            printf ("\n");
        }
    }
    printf ("\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}