#include <stdio.h>          //biblioteca padrao para C
#include <stdlib.h>
//#include <locale.h>       //usar setlocale   (LC_ALL, "pt-BR"); não funcionou
#include <windows.h>        //biblioteca do windows para que o apareca acentos no código no cmd.

void preparacao_acentos(){        //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;         //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);  //muda a codificação do sistema para UFT-8
    system("cls");           //comando para limpar a tela do cmd
}

float conversor_para_fah(float temp){
    //simplificado a equação fica F = 1.8C + 32
    return (1.8*temp + 32);
}

int main(){
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();    //armazena a codificação padrao do windows
    preparacao_acentos(0);                        //chama o processo que prepara o sistema para mostrar acentos
    //declaração de variaveis
    float   celcius;
    char    escolha = 's';
    //inicio do programa
    printf  ("Programa para converter a temperatura de celcius para Fahrenheit.\n");
    printf  ("-----------------------------------------------------------------\n\n");
    while   ((escolha == 's')||(escolha == 'S')){
        printf  ("Qual a temperatura em celcius?  ");
        scanf   ("%f",&celcius);
        printf  ("A temperatura em Fahrenheit é:  %5.1f°\n\n",conversor_para_fah(celcius));
    
        /* Bloco pergunta se o usuario quer utilizar o programa novamente
        se a resposta for 's' o loop continua */
        printf  ("Deseja converter outra temperatura? (s/n):  ");
        scanf   (" %c", &escolha);
        printf  ("\n");     //pra formatação na cmd
    }

    //fim  do codigo
    printf  ("\n-------------------------------------------------");
    printf  ("\nObrigada por utilizar o programa.");
    printf  ("\nObrigada por utilizar o programa. \n\nAutor:\t\tAna Atala  \nData:\t\tMaio 20, 2021  \nMateria:\tAlgoritmo I  \nFaculdade:\tUnemat  \n\n"); 

    SetConsoleOutputCP(CPAGE_DEFAULT);   //comando para voltar à codificação padrão do windows.
    system ("pause");    //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}