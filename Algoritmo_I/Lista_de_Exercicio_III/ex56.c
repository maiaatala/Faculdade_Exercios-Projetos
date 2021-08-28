#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/* 56) Criar um algoritmo em PORTUGOL que receba vários números
inteiros e positivos e imprima o produto dos números ímpares
digitados e a soma dos pares. O algoritmo encerra quando o
zero ou um número negativo é digitado. */

int main (){

    long unsigned int soma_pares = 0, produto_impares = 1;
    int entrada = 0;

    printf ("\nPrograma para calcular a soma dos numeros pares e o produto dos numeros impares\n" );
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("Digite os numeros desejados,\ndigitar um numero menor ou igual a zero termina o programa.\n");

    do{
        if (entrada % 2 == 0){
            //bloco par
            soma_pares += entrada;
        }else{
            //bloco impar
            produto_impares *= entrada;
        }
        scanf ("%i", &entrada);
    }while (entrada > 0);

    printf ("\n->->->->->->->->->->->->->->->->->->->->->->\n");
    printf ("Soma dos numeros pares: %i\n", soma_pares);
    printf ("Produto dos numeros impares: %i\n", produto_impares);
    printf ("->->->->->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}