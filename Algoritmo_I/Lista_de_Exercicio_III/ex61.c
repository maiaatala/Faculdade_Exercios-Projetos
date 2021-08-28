#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"

#define max_turmas 3

/* 61) Numa universidade, os alunos das turmas de informática fizeram uma prova de algoritmos.
Cada turma possui um número de alunos. Criar um algoritmo em PORTUGOL que imprima para cada turma:
    Quantidade de alunos aprovados;
    Média de cada turma;
    Percentual de reprovados. 

Considere aprovado aluno com nota igual ou superior a 7.0.
O programa deve ler o número de alunos de cada turma e só finalizar o
programa quando um número não positivo de alunos for digitado. 

matriz  qnt_ap  soma  qnt_alunos

turma1  

quantidade alunos = dados_turmas[turma][0];
media             = dados_turmas[turma][1]/dados_turmas[turma][2];
% reprovados      = (dados_turmas[turma][2]-dados_turmas[turma][0])/dados_turmas[turma][2]

*/
int main (){

    float dados_turmas[max_turmas][3] = {0}, nota, soma;
    int turma = -1, qnt_alunos, i, qnt_ap;

    printf ("\nPrograma para calcular estatisticas de turma de algoritmo.\n" );
    printf ("Durante o uso do programa: \n");
    printf ("\t- Inserir quantidade de aluno < 0: O programa mostra os resultados e termina.\n");
    printf ("\t- Inserir notas < zero: o programa passa pra prox turma\n");
    printf ("\t- Inserir notas > 10: a nota %c convertida para 10\n",eh);
    printf ("<<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>>\n\n");

    printf ("Informe quantos alunos tem na %i%c turma: ", turma+2, f_o);
    scanf  ("%d", &qnt_alunos);
    
    while ((qnt_alunos > 0) && (turma + 1 < max_turmas)){
        //acrescenta a turma ja que qnt_alunos > 0;
        turma++;
        //reseta as variaveis de acumulação
        qnt_ap = 0;
        soma = 0;

        //bloco para ler as notas das turmas, armazena a soma e  quantidade de aprovados
        for (i = 0; i < qnt_alunos; i++){
            //entrada de dados
            printf ("Nota do %i%c aluno: ", i+1, m_o);
            scanf ("%f", &nota);

            //bloco de tratamento de dados
            if (nota > (float) 10){
                nota = 10.0;
            }else if (nota < (float) 0){
                qnt_alunos = i; //porque saiu do loop antes, diminuiu a qnt de alunos
                break;
            }

            //calculo da soma para media e da quantidade de aprovados
            soma += nota;
            if (nota >= (float) 7){
                qnt_ap++;
            }
        }
        //armazenamento dos dados na matriz
        dados_turmas[turma][0] = (float) qnt_ap;
        dados_turmas[turma][1] = soma;
        dados_turmas[turma][2] = (float) qnt_alunos;
        
        //entrada de dados para a prox turma e possivel saída do loop.
        printf ("\nInforme quantos alunos tem na %i%c turma: ", turma+2, f_o);
        scanf  ("%d", &qnt_alunos);
    }

    if (turma + 1 >= max_turmas){
        printf ("\tdesculpa, o limite de turmas por professor foi atingido\n");
    }

    printf ("\n\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");
    //tabela resultados
    printf ("Turma \tqnt.Aprovados \tMedia Geral \t%% Reprovados\n");
    for (i = 0; i <= turma; i++){
        printf("%4d%c \t%13.1f \t%11.1f \t%12.1f\n",
            i+1, m_o, dados_turmas[i][0], (dados_turmas[i][1]/dados_turmas[i][2]),
            ((dados_turmas[i][2]-dados_turmas[i][0])/dados_turmas[i][2])*100);
    }
    printf ("->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");

    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
    system ("pause");
    return 0;
}