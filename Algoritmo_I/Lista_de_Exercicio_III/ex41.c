#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/*41) Escreva um algoritmo em PORTUGOL que receba números do
usuário e imprima o triplo  de cada número. O algoritmo
deve encerrar quando o número –999 for digitado.*/

int main (){

    float number;

    printf ("\nPrograma para responder o triplo de n%cmeros ate que -999 seja escrito.\n", u_a);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    do{
        printf ("\nInsira um n%cmero: ", u_a);
        scanf  ("%f", &number);
        printf ("%c%c Triplo: %.2f", a_r, a_r, number*3);
    }while (number != (float)-999);

    printf ("\n\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}