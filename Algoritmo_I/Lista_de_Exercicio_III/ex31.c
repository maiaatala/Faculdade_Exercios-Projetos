#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ascii_acentos.h"

/*31) Sendo H = 1 + 1/2 + 1/3 + 1/4 + ... + 1/N, faça um algoritmo,
para gerar o número H. O número N é lido do teclado;
 */

int main (){
    int N, i;
    float H = 0;
    system ("cls");

    printf ("\nPrograma para realizar o c%clculo de: H = %c = somat%cria(1%cN) \n", a_a, m_f, o_a, m_d);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("Insira o valor de N (inteiro positivo): ");
    scanf  ("%i", &N);

    while (N <= 0){
        printf ("O valor de N n%co pode ser negat%cvo ou zero.\n", a_t, i_a);
        printf ("Insira um valor correto: ");
        scanf  ("%i", &N);
    }

    for (i = 1; i <= N; i++){
        H += (float) 1/i;
    }

    printf ("\n->->->->->->->->->->->->->->->->->->\n");
    printf ("O valor de H para N = %i %c: %.4f", N, eh, H);
    printf ("\n->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}