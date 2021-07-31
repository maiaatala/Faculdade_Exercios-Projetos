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

    struct db produto;
    struct client cliente;
    struct dbout vendas;

    produto = in_db(produto);
    cliente = in_cliente(cliente);
    vendas = in_dbout(vendas);
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
                system("cls");
                printf("--Cadastro de cliente--\n\n");
                cliente = novo_cliente(cliente);
                break;
            case 12:
                //Consultar cliente pelo nome
                system("cls");
                printf("--Consulta de cliente--\n\n");
                consulta_cliente(cliente);
                break;
            case 13:
                //Imprimir lista de Clientes
                system("cls");
                printf("--Lista de Clientes--\n");
                mostrar_cliente(cliente);
                system("pause");
                break;
            case 21:
                //Inserir novo Produto
                system("cls");
                printf("--Cadastro de Produto--\n");
                produto = novo_produto(produto);
                
                break;
            case 22:
                //Consultar produto pelo nome
                system("cls");
                printf("--Consulta de Produto--\n\n");
                consulta_produto(produto);
                break;
            case 23:
                //Imprimir lista de produtos
                system("cls");
                printf("--Lista de Produto--\n");
                mostrar_produto (produto);
                system("pause");
                break;
            case 31:
                //Registrar Venda de Produtos
                system("cls");
                vendas = nova_venda(vendas, &produto, cliente);
                printf("--Registro de Venda--\n");
                break;
            case 32:
                //imprimir lista de produtos vendidos
                system("cls");
                printf ("--Lista de Vendas--\n");
                mostrar_vendas (vendas, produto, cliente);
                system("pause");
                break;
        }
    }while(menu != 0);
    //printf ("--><--><--><--><--><--><--><--><--><--><--><--><--><--\n");
    //printf ("--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--<>--\n\n");
    system("pause");
    return 0;
}