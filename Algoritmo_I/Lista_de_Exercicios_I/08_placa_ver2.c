#include <stdio.h>                               //biblioteca padrao para C
#include <stdlib.h>
//#include <locale.h>                            //usar setlocale   (LC_ALL, "pt-BR"); não funcionou
#include <windows.h>                             //biblioteca do windows para que o apareca acentos no código no cmd.

void preparacao_acentos(){                       //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;                     //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);              //muda a codificação do sistema para UFT-8
    system("cls");                               //comando para limpar a tela do cmd
}

int calculocentena(int valorp){
    //declaração das variaveis
    div_t centena;

    /*calculo da centena
    usamos o modulo (%) para calcular o resto da divisao de milhar, 'retirando' a parte do milhar do calculo
    e div(int numerador, int denominador) para calcular a centena
    onde centena.quot é o quociente e centena.rem é o resto*/
    centena = div((valorp%1000), 100);

    return (centena.quot);
}

int main(){
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();    //armazena a codificação padrao do windows
    preparacao_acentos(0);                        //chama o processo que prepara o sistema para mostrar acentos
    //declaração das variaveis
    int placa;
    char escolha = 's';

    //entrada de dados
    printf  ("Programa para dectar a unidade de centena de uma placa de 4 números\n");
    printf  ("-------------------------------------------------------------------\n\n");
    while   ((escolha == 's')||(escolha == 'S')){       //C é case sensitive, então deve ser feita as comparações para s e S
        printf  ("escreva o número da placa:  ");
        scanf   ("%i", &placa);
        /* bloco verifica se o valor de entrada da placa é valido ou não.
        se o valor for maior que 10000 ou menor que 1000, o programa pede
        pro valor ser inserido norvamente, tendo em vista que é uma placa
        de 4 algarismos. */
        while   ((placa >= 10000)||(placa < 1000)){
            printf  ("Valor incorreto, por favor inserir uma placa de valor positivo e de 4 algarismos\n");
            printf  ("escreva o número da placa:  ");
            scanf   ("%i", &placa);
        }
        printf  ("O algarismo correspondente à centena é:  %i\n\n", calculocentena(placa));
    
        //bloco pergunta se o usuario deseja utilizar o programa novamente
        printf  ("Deseja identificar a centena de outra placa? (s/n):  ");
        scanf   (" %c", &escolha);
        printf  ("\n");         //apenas para formatação na cmd
    }

    //Fim do código
    printf  ("\n---------------------------------------------------------------------");
    printf  ("\nObrigada por utilizar o programa. \n\nAutor:\t\tAna Atala  \nData:\t\tMaio 20, 2021  \nMateria:\tAlgoritmo I  \nFaculdade:\tUnemat  \n\n");
    
    SetConsoleOutputCP(CPAGE_DEFAULT);  //comando para voltar à codificação padrão do windows.
    system ("pause");    //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}
