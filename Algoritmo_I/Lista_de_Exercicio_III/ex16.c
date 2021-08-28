#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

/*16) Criar um algoritmo em PORTUGOL que leia um número (NUM),
e depois leia NUM números inteiros e imprima o maior deles.
Suponha que todos os números lidos serão positivos.*/

void entrada_dados (int N);

int main (){
    int n;

    system ("cls");

    printf ("\nPrograma para identificar o maior numero entre N n%cmeros\n", u_a);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("Quantos n%cmeros deseja e inserir?  ", u_a);
    scanf  ("%d", &n);

    /* Uso uma função para poder criar um vetor com exatos N numeros,
    caso contrário, teria que gastar memoria criando um vetor
    muito grande */
    entrada_dados (n);

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}

void entrada_dados (int N){
    int i, posicao_m = 0; //inicia posicao com zero, porque o maior numero no começo sempre sera o primeiro inserido
    float numeros[N]; 

    printf ("\n");
    for (i = 0; i < N; i++){
        printf ("Insira o %d%c n%cmero: ", i+1, m_o, u_a);
        scanf  ("%f", &numeros[i]);
        if (numeros[i] > numeros[posicao_m]){
            /* faz a verificacao se o novo numero inserido é maior que 
            o maior antigo numero */
            posicao_m = i;
        }
    }

    printf ("\n->->->->->->->->->->->->->->->->->->->->->->\n");
    printf ("O maior n%cmero inserido foi: \n\tO %d%c n%cmero com valor: %-10.2f", u_a, posicao_m+1, m_o, u_a, numeros);
    printf ("\n->->->->->->->->->->->->->->->->->->->->->->\n");
}