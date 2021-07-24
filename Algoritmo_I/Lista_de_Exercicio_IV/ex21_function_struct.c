#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ascii_acentos.h"

/* 21) Em uma cidade do interior, sabe-se que, de janeiro a abril de 1976 (121 dias), não ocorreu temperatura inferior a 15ºC nem superior a 40ºC. As temperaturas verificadas em cada dia estão disponíveis em uma unidade de entrada de dados. Fazer um algoritmo, em pseudocódigo do Visualg ou na Linguagem C, que calcule e
imprima:
- A menor temperatura ocorrida;
- A maior temperatura ocorrida;
- A temperatura média;
- O número de dias nos quais a temperatura foi inferior à temperatura média. */

//tutorial: https://dyclassroom.com/c/c-function-returning-structure

struct stats{
    short int * dailyTemp;
    short int menor;
    short int maior;
    short int diasFrios;
    float media;
};

struct stats entrada_dados(struct stats T, const short int D);
float media(struct stats T, const short int D);
struct stats calcstats(struct stats T, const short int D);
void display(struct stats T, const short int D);

int main(){

    const short int dias = 121;
    //escolhi usar const short int ao invez de define por... motivos? eu poderia ter feito #define dias 121 no começo do programa e feito a struct com shrot int dailyTemp[dias]... mas dai não iria usar o malloc.
    
    struct stats temp;
    //eu inicio o vetor aqui devido ao malloc.
    temp.dailyTemp = (short int *) malloc(dias * (sizeof(short int)));
    //pointer, allocar a memoria do heap dias * (qualquer seja o tamanho do short int) = temp.dailyTemp[dias];

    system ("cls");
    printf ("\nPrograma para analisar temperaturas de uma cidade\n");
    printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");

    //insere os valores das temperaturas diarias
    temp = entrada_dados(temp, dias);
    //calcula a media
    temp.media = media(temp, dias);
    //calcula as estatisticas
    temp = calcstats(temp, dias);
    //mostra os resultados
    display(temp, dias);

    //creditos
    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);

    free(temp.dailyTemp); //libera a memoria do heap
    system ("pause");
    return 0; //não sei falar exatamente o porque eu utilizo return no main de um programa C.
}

//Struct stats porque é isso que a função ira retornar.
struct stats entrada_dados(struct stats T, const short int D){
    //Eu tentei fazer função retornar array, mas as unicas formas que eu encontrei foram com gambiarra, portanto eu decidi deixar no struct, ja que mandar e receber struct para função em C é mil vezes mais fácil e correto.
    short int i;
    T.menor = 0;
    T.maior = 0;
    T.media = 0;
    T.diasFrios = 0;
    
    srand(time(NULL)); //inicializador do srand

    //bloco atribiu valores de temperatura usando um random
    for (i = 0; i < D; i++){
        T.dailyTemp[i] = (rand() % 26) + 15;
        //0 + 15 = 15 & 25 + 15 = 40
    }

    return(T);
}

float media(struct stats T, const short int D){
    int soma = 0;
    short int i;

    for (i = 0; i < D; i++){
        soma += T.dailyTemp[i];
    }
    return (soma/(float)D);
}

struct stats calcstats(struct stats T, const short int D){
    short int i;

    for (i = 0; i < D; i++){
        /* verifica se temp atual é menor que a menor
        ou, se nao, se é maior que a maior */
        if (T.dailyTemp[i] < T.dailyTemp[T.menor]){
            T.menor = i; //aponta a posição da menor
        }else if(T.dailyTemp[i] > T.dailyTemp[T.maior]){
            T.maior = i;
        }
        //calcula a quantidade de dias mais frio que a media
        if (T.dailyTemp[i] < T.media){
            T.diasFrios++;
        }
    }
    return (T);
}

//tu pode declarar que ira receber uma struct lol
void display(struct stats T, const short int D){
    short int i;

    //bloco para mostrar as temp diarias
    printf ("As temperaturas entre Janeiro e Abril de 1976: \n");
    for (i = 0; i < D; i++){;
        printf ("%i%cC \t", T.dailyTemp[i],g_s);
        if ((i+1) % 10 == 0){
            printf ("\n");
        }
    }

//bloco para mostrar os resultados.
    printf ("\n\n--><--><--><--><--><--><--><--><--><--><--><--><--><--\n");
    printf ("Estast%csticas sobre os 121 dias: \n", i_a);
    printf ("A menor temperatura foi: %i%cC\n", T.dailyTemp[T.maior], g_s);
    printf ("A maior temperatura foi: %i%cC\n", T.dailyTemp[T.menor],g_s);
    printf ("A temperatura m%cdia foi: %.1f%cC\n", eh, T.media, g_s);
    printf ("O n%cmero de dias mais frios que a m%cdia foram: %i\n", u_a, eh, T.diasFrios);
    printf ("--><--><--><--><--><--><--><--><--><--><--><--><--><--\n");
}