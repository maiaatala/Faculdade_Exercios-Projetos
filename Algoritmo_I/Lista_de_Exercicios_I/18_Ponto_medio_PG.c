#include <stdio.h>        //biblioteca padrao para C
#include <stdlib.h>
//#include <locale.h>     //usar setlocale   (LC_ALL, "pt-BR"); não funcionou
#include <windows.h>      //biblioteca do windows para que o apareca acentos no código no cmd.
#include <math.h>         //Biblioteca necessária para sqrt()

void preparacao_acentos(){           //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;         //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);  //muda a codificação do sistema para UFT-8
    system("cls");                   //comando para limpar a tela do cmd
}

float calculopm(float a, float c){    //funcao para calcular ponto medio
    //b = (a*c)^1/2
    return sqrt((a*c));
}

int main(){
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();    //armazena a codificação padrao do windows
    preparacao_acentos(0);    //chama o processo que prepara o sistema para mostrar acentos

    float   ponto1, ponto2;
    char    escolha = 's';

    //bloco de entrada de dados
    printf  ("Programa para calcular o ponto médio de uma Progressão Geométrica a partir de dois valores conhecidos\n");
    printf  ("---------------------------------------------------------------------------------------------------\n\n");
    while ((escolha == 's')||(escolha =='S')){
        printf  ("Insira o primeiro ponto:  ");
        scanf   ("%f",&ponto1);
        printf  ("Insira o segundo ponto:  ");
        scanf   ("%f",&ponto2);
        /* O calculo do ponto médio é feito atravez de função,
        foi utilizado fabs() para transformar numeros floats
        em valores absolutos (sem sinais), para que seja possível
        fazer a raiz quadrada. */
        printf  ("O Ponto médio dos pontos %5.2f e %5.2f é:  ±%5.3f\n\n", ponto1, ponto2, calculopm(fabs(ponto1),fabs(ponto2)));
    
        /* Bloco pergunta se o usuario quer calcular outro ponto médio,
        se a resposta for 's', o loop continua */
        printf  ("Deseja calcular outro ponto médio? (s/n):  ");
        scanf   (" %c", &escolha);
    }

    //fim  do codigo
    printf  ("\n---------------------------------");
    printf  ("\nObrigada por utilizar o programa. \n\nAutor:\t\tAna Atala  \nData:\t\tMaio 20, 2021  \nMateria:\tAlgoritmo I  \nFaculdade:\tUnemat  \n\n");   

    SetConsoleOutputCP(CPAGE_DEFAULT);  //comando para voltar à codificação padrão do windows.
    system ("pause");    //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}