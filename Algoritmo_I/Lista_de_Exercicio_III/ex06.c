#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/* 6) Escreva um algoritmo em PORTUGOL que receba dez
números do usuário e imprima a metade de cada número.  */

int main (){
    float input[10], metade[10];
    int i;
    
    system ("cls");

    printf ("\nPrograma receber 10 n%cmeros e imprimir metade de cada.\n", u_a);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    for (i = 0; i < 10; i++){
        printf ("Insira o %d%c numero: ", i+1, m_o);
        scanf  ("%f", &input[i]);
        metade[i] = input[i]/2;
    }

    printf ("\n->->->->->->->->->->->->->->\n");
    for (i = 0; i <= 9; i++){
        printf ("%10.2f %c 2 = %-10.2f\n", input[i], m_d, metade[i]);
    }
    printf ("->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}