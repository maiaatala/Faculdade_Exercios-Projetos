#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/* 51) Dado um país A, com 5000000 de habitantes e uma taxa de natalidade
de 3% ao ano, e um país B com 7000000 de habitantes e uma taxa de natalidade
de 2% ao ano, escrever um algoritmo em PORTUGAL que seja capaz de calcular
e iterativamente e no fim imprimir o tempo necessário para que a população
do país A ultrapasse a população do país B */

int main (){

    float paisA, paisB, natA, natB;
    int ano = 0;

    printf ("\nPrograma para calcular quando o pais com 7000000 habitantes e 2%% de natalidade sera\n" );
    printf ("passado pelo pais com 5000000 habitantes e 3%% de natalidade.\n" );
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    paisA = (float) 5000000;
    natA  = (float) 3/100;
    paisB = (float) 7000000;
    natB  = (float) 2/100;
    printf ("%3i%c Ano %c%c%c \tPa%cs A: %.1f \tPa%cs B: %.1f \tA-B: %-11.1f\n", ano, m_o, a_r, a_r, a_r, i_a, paisA, i_a, paisB, paisA - paisB);

    while (paisA <= paisB){
        ano++;
        paisA = paisA * (1 + natA);
        paisB = paisB * (1 + natB);
        printf ("%3i%c Ano %c%c%c \tPa%cs A: %.1f \tPa%cs B: %.1f \tA-B: %11.1f\n", ano, m_o, a_r, a_r, a_r, i_a, paisA, i_a, paisB, paisA - paisB);
    }


    printf ("\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");
    printf ("O pa%cs A conseguiu outrapassar a popula%c%co do pa%cs B\n", i_a, cs, a_t, i_a);
    printf ("    depois de %i anos, com diferen%ca de %.1f habitantes.\n", ano, cs, paisA - paisB);
    printf ("->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}