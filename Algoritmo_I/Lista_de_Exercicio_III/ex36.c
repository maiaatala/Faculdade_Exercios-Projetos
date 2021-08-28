#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"
#include <math.h>

#define qntAlunos 50 //para facilitar o teste do codigo, usei a constant para mudar os valores.


/* 36) Escreva um algoritmo em PORTUGOL, que leia um conjunto de 50 fichas, cada uma contendo,
a altura e o código do sexo de uma pessoa (código = 1 se for masculino e 2 se for feminino), e calcule e imprima:
A maior e a menor altura da turma;
A média de altura das mulheres;
A média de altura da turma. */


int main (){

    float altura[qntAlunos], mediaF, mediaG;
    int i, pos_maior, pos_menor, qntF, sexo[qntAlunos];

    printf ("\nPrograma para calcular a m%cdia de altura em uma sala\n", eh);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("codigo referente ao sexo: 1 = M | 2 = F\n");

    //entrada de dados
    for (i = 0; i < qntAlunos; i++){  
        printf ("insira a altura do %i%c aluno(a): " , i+1, m_o);
        scanf  ("%f", &altura[i]);
        printf ("insira o sexo do %i%c aluno(a): ", i+1, m_o);
        scanf  ("%i", &sexo[i]);
    }
    
    /* //bloco para verificacao dos dados
    printf ("\n");
    for (i = 0; i <= qntAlunos; i++){
        printf ("%.1fm: %i,", altura[i], sexo[i]);
        //formatacao
        ((i+1) % 10 == 0)? printf("\n") : printf ("\t");
    } */

    //processamento dos dados
    qntF = 0;
    pos_maior = 0;
    pos_menor = 0;
    mediaF = 0;
    mediaG = 0;
    for (i = 0; i < qntAlunos; i++){
        //bloco para alturar maior e menor
        if (altura[i] > altura[pos_maior]){
            pos_maior = i;
            //printf ("flag");
        }
        if (altura[i] < altura[pos_menor]){
            pos_menor = i;
            //printf ("%i, menor: %f\n", pos_menor, altura[pos_menor]);
        }

        //Soma das altura da sala
        mediaG += altura[i];
        
        //bloco para soma das altura das mulheres
        if (sexo[i] == 2){
            qntF++;
            mediaF += altura[i];
        }
        
    }
    //printf ("%f \t %f \t %i\n", mediaG, mediaF, qntF);
    //calculo das médias
    mediaG = (float) mediaG / qntAlunos;
    mediaF = (float) mediaF / qntF;


    //pritnf dos resultados
    printf ("\n->->->->->->->->->->->->->->->->->->->->\n");
    printf ("A maior altura da turma %c: %.2f\n", eh, altura[pos_maior]);
    printf ("A menor altura da turma %c: %.2f\n", eh, altura[pos_menor]);
    printf ("A altura m%cdia das mulheres %c: %.2f\n", eh, eh, mediaF);
    printf ("A altura m%cdia da turma %c: %.2f\n", eh, eh, mediaG);
    printf ("->->->->->->->->->->->->->->->->->->->->\n");

    printf ("\n\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}