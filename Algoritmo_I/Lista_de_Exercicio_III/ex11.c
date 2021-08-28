#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/* 11) Criar um algoritmo em PORTUGOL que imprima todos os
números de 1 até 100, inclusive, e a soma de todos eles. */

int somatoria(int lim_inf, int lim_sup);

int main (){
    int i, soma = 0;

    system ("cls");

    printf ("\nPrograma para escrever os n%cmeros de 1 a 100 e a soma deles.\n", u_a);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    soma = somatoria(1,100); //1 e 100 escolhidos porque o exercicio era a somatoria de 1 a 100

    printf ("\n->->->->->->->->->\n");
    printf ("Somat%cria: %d", o_a,soma);
    printf ("\n->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}

int somatoria(int lim_inf, int lim_sup){
    int i, soma = 0;
    
    printf ("N%cmeros de %d a %d: \n", u_a, lim_inf, lim_sup);

    for (i = lim_inf; i <= lim_sup; i++){
        soma += i;
        printf ("%d,\t", i);
        if (i % 10 == 0){
            /* bloco para formatação */
            printf ("\n");
        }
    }
    return (soma);
}