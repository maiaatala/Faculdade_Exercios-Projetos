#include <stdio.h>       //biblioteca padrao para C
#include <stdlib.h>
//#include <locale.h>    //usar setlocale   (LC_ALL, "pt-BR"); não funcionou
#include <windows.h>     //biblioteca do windows para que o apareca acentos no código no cmd.

void preparacao_acentos(){       //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;            //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);     //muda a codificação do sistema para UFT-8
    system("cls");             //comando para limpar a tela do cmd
}

float calculo_litros(float t, float v){
    /* calcular litros gastos na viagem
    t é o tempo e v é vm
    e o consumo foi dado como 12km/l pelo exercicio
    d = t*v
    L = d/12 = (t*v)/12 */

    return((t*v)/12);
}

int main(){
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();    //armazena a codificação padrao do windows
    preparacao_acentos(0);      //chama o processo que prepara o sistema para mostrar acentos
    //declaração devariaveis
    float   Vm, tempo;
    char    escolha;
    //inicio do programa
    printf  ("Progama para caulcular a quantidade de litros usadas em uma viagem\n");
    printf  ("------------------------------------------------------------------\n\n");
    /* bloco para repetir o programa quantas vezes o usuario quiser
    basta ele responder à pergunta com s ou S */
    do{
        printf  ("Qual foi o tempo (em horas) gastos na viagem?  ");
        scanf   ("%f",&tempo);
        printf  ("Qual foi a velocidade média (em km/h) realizada durante a viagem?  ");
        scanf   ("%f",&Vm);
        //chama a função para realizar o calculo da quantidade de litros gastos
        printf  ("A quantidade de combustivel gastas durante a viagem é de:  %5.2f Litros\n\n", calculo_litros(tempo,Vm));

        printf  ("Deseja calcular a quantidade de litros gastos em outra viagem? (s/n):  ");
        scanf   (" %c",&escolha);
        printf  ("\n");     //formatação para a cmd
    }while((escolha == 's')||(escolha == 'S'));


    //fim  do codigo
    printf  ("\n-------------------------------------------------");
    printf  ("\nObrigada por utilizar o programa. \n\nAutor:\t\tAna Atala  \nData:\t\tMaio 20, 2021  \nMateria:\tAlgoritmo I  \nFaculdade:\tUnemat  \n\n");

    SetConsoleOutputCP(CPAGE_DEFAULT);   //comando para voltar à codificação padrão do windows.
    system ("pause");     //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}