#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/* 21) Criar um algoritmo em PORTUGOL que leia os limites inferior e superior
de um intervalo e imprima todos os números pares no intervalo aberto e seu somatório.
Suponha que os dados digitados são para um intervalo crescente,
ou seja, o primeiro valor é menor que o segundo.*/


int main (){
    int lim_inf, lim_sup, i, soma = 0;

    //system ("cls");

    printf ("\nPrograma para encontrar os n%cmeros pares em um intervalo aberto\n",u_a);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("Insira o limite inferior do intervalo: ");
    scanf  ("%d",&lim_inf);
    printf ("Insira o limite superior do intervalo: ");
    scanf  ("%d",&lim_sup);

    printf ("\nN%cmeros pares entre %d e %d:", u_a, lim_inf, lim_sup);
    printf ("\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");
    for (i = lim_inf; i <= lim_sup; i++){
        
        if (i % 2 == 0){
            printf ("%4d,\t", i);
            soma += i;
        }

        /* bloco para formatação */
        if ((i+1) % 16 == 0){
            printf("\n");
        }
    }
    printf ("\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");
    printf ("Soma de todos os n%cmeros pares entre %d e %d %c: %d", u_a, lim_inf, lim_sup, eh, soma);
    printf ("\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}