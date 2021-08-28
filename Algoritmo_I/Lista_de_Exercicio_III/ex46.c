#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/* 46) Construa um algoritmo em PORTUGOL para calcular a média
de valores PARES e ÍMPARES, que serão digitados pelo usuário.
Ao final, o algoritmo deve mostrar estas duas médias.
O algoritmo deve mostrar também o maior número PAR digitado
e o menor número ÍMPAR digitado. Para finalizar o usuário
irá digitar um valor negativo. 

media pares; media impares; maior par; menor impar*/

int main (){

    int number = 0, soma_pares = 0, soma_impares = 0, maior_par = 0,
        menor_impar, qnt_pares = 0, qnt_impares = 0;

    //maior par 0 pois o programa nao recebe valores negativos.

    printf ("\nPrograma para receber n%cmeros pares e impares e responder informa%coes sobre eles\n", u_a, cs);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("Insira o %i%c n%cmero: ", qnt_pares+qnt_impares+1, m_o, u_a);
    scanf  ("%i", &number);

    while (number >= 0){
        if (number % 2 == 0){
            //bloco para numeros pares
            qnt_pares++;
            soma_pares += number;
            if (number > maior_par){
                maior_par = number;
            }
        }else {
            //bloco para numeros impares
            if (!qnt_impares){
                menor_impar = number;
            }
            qnt_impares++;
            soma_impares += number;
            if (number < menor_impar){
                menor_impar = number;
            }
        }
        //inserir um novo numero.
        printf ("Insira o %i%c n%cmero: ", qnt_pares+qnt_impares+1, m_o, u_a);
        scanf  ("%i", &number);
    }
    
    //escrever resultados
    printf ("\n->->->->->->->->->->->->->->->->->->\n");
    printf ("M%cdia dos valores PARES: %.2f \n", eh, (float) (soma_pares/qnt_pares));
    printf ("M%cdia dos valores IMPARES: %.2f \n", eh, (float) (soma_impares/qnt_impares));
    printf ("Maior n%cmero PAR: %i\n", u_a, maior_par);
    printf ("Menor n%cmero IMPAR: %i\n", u_a, menor_impar);
    printf ("->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}