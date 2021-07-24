#include <stdio.h>       //biblioteca padrao para C
#include <stdlib.h>
//#include <locale.h>    //usar setlocale   (LC_ALL, "pt-BR"); não funcionou
#include <windows.h>     //biblioteca do windows para que o apareca acentos no código no cmd.

void preparacao_acentos(){       //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;            //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);     //muda a codificação do sistema para UFT-8
    system("cls");             //comando para limpar a tela do cmd
}

int main(){
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();    //armazena a codificação padrao do windows
    preparacao_acentos(0);      //chama o processo que prepara o sistema para mostrar acentos
    //declaração variaveis
    float   valor_conta;
    char    escolha = 's';
    //inicio do programa
    printf  ("Programa para calcular gorjeta de uma conta de restaurante\n");
    printf  ("----------------------------------------------------------\n\n");
    while   ((escolha == 's')||(escolha == 'S')){
        printf  ("Qual foi a despesa realizada no restaurante?  ");
        scanf   ("%f",&valor_conta);
        /* A gorjeta é 10% do valor da compra, portanto 0.1*valor_compra
        e a gorjeta somada ao valor total é 1.1*valor_compra */
        printf  ("O valor da gorjeta é %5.2f e o valor da conta com a gorjeta é %5.2f\n\n", valor_conta*0.1, valor_conta*1.1);
        
        /* bloco pergunta se o usuario gostaria de usar o programa novamente
        permitindo o mesmo a sair do loop */
        printf  ("Deseja calcular outra gorjeta? (s/n):  ");
        scanf   (" %c", &escolha);
        printf  ("\n");     //pra formatação na cmd
    }

    //fim  do codigo
    printf  ("\n-------------------------------------------------");
    printf  ("\nObrigada por utilizar o programa. \n\nAutor:\t\tAna Atala  \nData:\t\tMaio 20, 2021  \nMateria:\tAlgoritmo I  \nFaculdade:\tUnemat  \n\n");   

    SetConsoleOutputCP(CPAGE_DEFAULT);   //comando para voltar à codificação padrão do windows.
    system ("pause");     //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}