#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "ascii_acentos.h"

/* 26) Escreva um algoritmo em PORTUGOL que realize o produto de A (número real)
por B (número inteiro), ou seja, A * B, atravéss de adições (somas).
Esses dois valores são passados pelo usuário através do teclado. */

float produto_por_soma (float A, int B);

int main (){
    int B;
    float A;

    system ("cls");

    printf ("\nPrograma para realizar produto utilizando somas.\n");
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");
    
    printf ("Insira o primeiro n%cmero (pode ser um float): ", u_a);
    scanf  ("%f", &A);
    printf ("Insira o segundo n%cmero (apenas inteiro): ", u_a);
    scanf  ("%d", &B);

    printf ("\n->->->->->->->->->->->->->->->->->->->->->\n");
    printf (" O produto entre %.2f e %i %c = %5.2f", A, B, eh, produto_por_soma(A, B));
    printf ("\n->->->->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}

float produto_por_soma (float A, int B){
    float prod;
    bool is_pos;

    /* linha verifica se A ou B é negativo
    e aciona uma flag para falar se o resultado
    sera negativo ou positivo. 0 = true (+); 1 = false (-);
    ^ é o operador XOR em C*/
    is_pos = ((A < (float) 0)^(B < 0))? 0 : 1;

    A = fabs(A);
    B = abs(B);

    prod = 0; //inicia prod = 0 para não usar uma variavel 'suja'
    /* bloco realiza o produto por soma */
    for (int i = 0; i < B; i++){
        prod += A;
    }

    /* bloco transforma o resultado em negativo
    se tiver a flag is_pos = false */
    if (!is_pos){
        prod = (-1)*prod;
    }

    return (prod);
}