#include <stdio.h>                               //biblioteca padrao para C
#include <stdlib.h>
//#include <locale.h>                            //usar setlocale   (LC_ALL, "pt-BR"); não funcionou
#include <windows.h>                             //biblioteca do windows para que o apareca acentos no código no cmd.

void preparacao_acentos(){                       //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;                     //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);              //muda a codificação do sistema para UFT-8
    system("cls");                               //comando para limpar a tela do cmd
}

int main(){
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();    //armazena a codificação padrao do windows
    preparacao_acentos(0);                        //chama o processo que prepara o sistema para mostrar acentos

    float   numero;
    char    escolha = 's';  //inicia a variavel com s para continuar no loop

    printf  ("Programa para calcular a terça parte de um número\n");
    printf  ("-------------------------------------------------\n");
    while((escolha == 's')||(escolha == 'S')){
        printf  ("\nInsira o número desejado:  ");
        scanf   ("%f", &numero);
        printf  ("A terça parte é: %4.3f\n\n",numero/3);

        //bloco pergunta se o usuario gostaria de usar o programa novamente
        printf  ("Deseja calcular outro número? (s/n):  ");
        scanf   (" %c",&escolha);
    }
    
    //fim  do codigo
    printf  ("\n-------------------------------------------------");
    printf  ("\nObrigada por utilizar o programa. \n\nAutor:\t\tAna Atala  \nData:\t\tMaio 20, 2021  \nMateria:\tAlgoritmo I  \nFaculdade:\tUnemat  \n\n");   

    SetConsoleOutputCP(CPAGE_DEFAULT);  //comando para voltar à codificação padrão do windows.
    system ("pause");  //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}