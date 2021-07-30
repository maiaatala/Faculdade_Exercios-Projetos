#include "includes/dbana.c"

/* HOW TO COMPILE THIS CORRECTLY
ON THE MAIN FILE:
#include "includes/dbana.h"
on terminal, USINC CMD:
gcc -o mercado.exe mercado.c includes/dbana.c
TO RUN:
mercado.exe */

void credits (){
    printf ("\n Fim do programa \n\t%c Ana Atala.\n\n", p_s);
}

int main(){
    int menu;
    system("cls");

    struct db produto = in_db(produto);
    struct client cliente = in_client(cliente);
    struct dbout vendas = in_dbout(vendas);

    do{
        menu = main_menu();
        printf ("\nEscolha: %i\n", menu);
        switch (menu){
            case 0:
                //Sair do programa
                credits();
                break;
            case 11:
                //Inserir novo Cliente
                
                break;
            case 12:
                //Consultar cliente pelo nome
                break;
            case 13:
                //Imprimir lista de Clientes
                break;
            case 21:
                //Inserir novo Produto
                break;
            case 22:
                //Consultar produto pelo nome
                break;
            case 23:
                //Imprimir lista de produtos
                break;
            case 31:
                //Registrar Venda de Produtos
                break;
            case 32:
                //imprimir lista de produtos vendidos
                break;
        }
    }while(menu != 0);
    //printf ("--><--><--><--><--><--><--><--><--><--><--><--><--><--\n");
    //printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");
    system("pause");
    return 0;
}