#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ascii_acentos.h"
#include <stdbool.h>

/* 26) Um armazém trabalha com 100 mercadorias diferentes identificadas pelos números inteiros de 1 a 100. O dono do armazém anota a quantidade de cada mercadoria vendida durante o mês. Ele tem uma tabela que indica, para cada mercadoria, o preço de venda. Escreva um algoritmo, em pseudocódigo do Visualg ou na Linguagem C, para calcular o faturamento mensal do armazém. A tabela de preços é fornecida seguida pelos números das mercadorias e as quantidades vendidas. Quando uma mercadoria não tiver nenhuma venda, é informado o valor zero no lugar da quantidade. */

struct mercadoria{ 
    //possui informaçao dos produtos
    short int id; //primary key
    float preco;
};

struct vendas{
    //possui informação sobre a venda dos produtos
    short int id; //primary key
    short int merc_id; //forreign key
    int qnd_vend;
    float valor;
};

void precos(struct mercadoria * P, short int max, short int qnt){
    short int i;

    srand((unsigned) time(NULL));

    for (i = 0; i < qnt; i++){
        P[i].id = i;
        P[i].preco = rand() % max;
        P[i].preco += ((float)rand()/(float)(RAND_MAX));
    }
}

int main(){
    //delcaracao de constantes para determinação do programa
    const short int qnt = 100, qnt_vendas_max = 30, preco_max = 150;
    int i;

    //declaração das struct
    struct mercadoria produtos[qnt];
    struct vendas vendas[qnt];

    system ("cls");
    
    printf ("\nPrograma para calcular o faturamento mensal de uma loja\n");
    printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");

    precos(&produtos[0], preco_max, qnt);
    for (i = 0; i < qnt; i++){
        printf("%3i    %.2f\n",produtos[i].id,produtos[i].preco);
    }

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;

}