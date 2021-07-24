#include <stdio.h>        //biblioteca padrao para C
#include <stdlib.h>
//#include <locale.h>     //usar setlocale   (LC_ALL, "pt-BR"); não funcionou
#include <windows.h>      //biblioteca do windows para que o apareca acentos do printf na cmd.

float calc_pa (float a, int n, int k, float r){
    //função para calcular  progressão aritmética
    // an = a + (n-k)*r

    return (a + (n-k)*r);
}

void preparacao_acentos(){          //Processo de preparação do sistema para acentos
    UINT CPAGE_UTF8 = 65001;        //Define a codificação do cmd com UFT-8
    SetConsoleOutputCP(CPAGE_UTF8);     //muda a codificação do sistema para UFT-8
    system("cls");      //comando para limpar a tela do cmd
}

int main(){
    //declaraçã das variaveis
    float   razao, ak;
    int     countk, countn;
    char    escolha_pa, escolha_termo;

    UINT CPAGE_DEFAULT = GetConsoleOutputCP();    //armazena a codificação padrao do windows
    preparacao_acentos(0);        //chama o processo que prepara o sistema para mostrar acentos
    
    //Inicio do código
    printf  ("Programa para calcular qualquer termo n de uma progressão aritmética a partir de um termo conhecido e a razão\n");
    printf  ("-------------------------------------------------------------------------------------------------------------\n");

    /* Loop para começar o programa de novo enquanto o usuario quiser
    calcular uma nova PA */
    do  {
        /* loop para repetir a entrada de dados
        caso o usuário tenha errado os dados inseridos */
        do{   
            printf  ("\n-----------Entrada de dados da PA-----------\n");
            printf  ("Escreva a razão da PA:  ");
            scanf   ("%f", &razao);
            printf  ("Escreva o termo conhecido:  ");
            scanf   ("%f", &ak);
            printf  ("Escreva a posição do termo conhecido na pa:  ");
            scanf   ("%i", &countk);
            printf  ("A PA inserida é: \n");
            printf  ("\nan = %.2f + ( n - %i )*%.2f\n",ak,countk,razao);

            /* Bloco pede pro usuario confirmar a equação, caso o
            usuario escolha 'n' o programa pede os dados novamente. */
            printf  ("\nConfirmar? (s/n):  ");
            scanf   (" %c", &escolha_pa);                     //o espaço entre " e % é para que o programa ignore 'white spaces'
        }while  ((escolha_pa == 'n')||(escolha_pa == 'N'));

        printf  ("\n----------Dados do calculo desejado----------\n");

        //bloco para pedir um termo n para calcular o an
        do{  
            printf  ("Escreva a posição do termo desejado: \t");
            scanf   ("%i", &countn);
            printf  ("\nO resultado da progressão aritmética para o termo %i é:  %.3f\n", countn, calc_pa(ak,countn,countk,razao));

            /* Bloco pede pro usuario se ele deseja calcular outro termo para a mesma PA.
            caso ele escolha 's' o loop continua */
            printf  ("\nDeseja calcular outro termo para esta PA? (s/n):  ");
            scanf   (" %c", &escolha_termo);
        }while  ((escolha_termo == 's') || (escolha_termo == 'S')); //c é case sensitive entao precisa verificar s e S

        //Bloco pede pro usuario se ele deseja calcular outra PA. caso ele escolha 's' o programa recomeça da entrada de dados
        printf  ("\nDeseja calcular outra PA? (s/n):  ");
        scanf   (" %c", &escolha_pa);
    } while ((escolha_pa == 's')||(escolha_pa == 'S'));

    //Fim do código
    printf  ("\n---------------------------------");
    printf  ("\nObrigada por utilizar o programa. \n\nAutor:\t\tAna Atala  \nData:\t\tMaio 20, 2021  \nMateria:\tAlgoritmo I  \nFaculdade:\tUnemat  \n\n");
    
    SetConsoleOutputCP(CPAGE_DEFAULT);   //comando para voltar à codificação padrão do windows.
    system  ("pause");   //comando para fazer o arquivo .exe nao fechar automaticamente
    return (0);
}
