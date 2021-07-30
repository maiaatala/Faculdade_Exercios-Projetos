#include "dbana.h"

struct db { //struct para produtos
    char nome[n_arr][100];
    int qnt[n_arr];
    float preco[n_arr];
    int ultimo;
};

struct client{
    char nome[n_arr][100];
    int ultimo;
};

struct dbout{
    //id produto, id cliente, qnt
    int registro[n_arr][3]; 
    float v_t[n_arr];
    int ultimo;
};

int main_menu(){ 
    //função para ler as opções do cliente no menu principal
    int m, m1;
    //m sera a opção do menu principal e m1 a opçao dos menus secundários;
    bool flag = false;
    //flag vai indicar se uma opção para sair do menu foi selecionada

    while (!flag){
        do{ //esse loop vai restrigir o input para entre apenas 0 e 3. sera usado varias vezes.
            system("cls");
            printf ("\n\t Menu Principal\n");
            printf ("1 - Acessar m%cdulo Cliente \n", o_a);
            printf ("2 - Acessar m%cdulo Produto \n", o_a);
            printf ("3 - M%cdulo de Vendas\n", o_a);
            printf ("0 - para sair do programa\n\t escolha: ");
            scanf  ("%i", &m);
        }while((m<0)||(m>3));

        switch (m) {
            case 0:
                break;
            case 1:
                do{
                    system("cls");
                    printf ("\n\t M%cdulo Cliente\n", o_a);
                    printf ("1 - Inserir novo Cliente \n");
                    printf ("2 - Consultar Cliente pelo nome \n");
                    printf ("3 - Imprimir lista de Clientes\n");
                    printf ("0 - Retornar ao menu principal\n\t escolha: ");
                    scanf  ("%i", &m1);
                }while((m1<0)||(m1>3));
                //m*10 + m1 = as opções serao 11 para novo cliente, 12 para consulta pelo nome, 13 imprimir lista, 10 para voltar ao menu principal.
                m *= 10;
                m += m1;
                break;
            case 2:
                do{
                    system("cls");
                    printf ("\n\t M%cdulo Produto\n", o_a);
                    printf ("1 - Inserir novo Produto \n");
                    printf ("2 - Consultar Produto pelo nome \n");
                    printf ("3 - Imprimir lista de Produto\n");
                    printf ("0 - Retornar ao menu principal\n\t escolha: ");
                    scanf  ("%i", &m1);
                }while((m1<0)||(m1>3));
                //m*10 + m1 = as opções serao 21 para novo produto, 22 para consulta pelo nome, 23 para imprimir lista, 20 para voltar ao menu principal.
                m *= 10;
                m += m1;
                break;
            case 3:
                do{
                    system("cls");
                    printf ("\n\t M%cdulo de Vendas\n", o_a);
                    printf ("1 - Registrar Venda de produtos \n");
                    printf ("2 - Imprimir lista de pordutos vendidos \n");
                    printf ("0 - Retornar ao menu principal\n\t escolha: ");
                    scanf  ("%i", &m1);
                }while((m1<0)||(m1>2));
                //m*10 + m1 = as opções serao 31 para nova venda, 32 para imprimir lista, 30 para voltar ao menu principal.
                m *= 10;
                m += m1;
                break;
        }
        //bloco verifica se M = 0 (opção sair do programa). ou se m é diferente de 10, 20, 30 (opções voltar ao menu principal)
        if ((m == 0)||((m % 10) != 0)){
            flag = true;
        }
    }
    return (m);
}

struct db in_db(struct db P){
    strcpy(P.nome[0], "Guanabara");
    P.qnt[0] = 1000;
    P.preco[0] = 25.0;
    P.ultimo = 0;
}

struct client in_client(struct client C){
    strcpy(C.nome[0], "Gunnar Rammos");
    strcpy(C.nome[1], "Ana Atala");
    C.ultimo = 1;
}

struct dbout in_dbout(struct dbout V){
    V.registro[0][0] = 0;
    V.registro[0][1] = 1;
    V.registro[0][2] = 1;
    V.v_t[0] = 25.0*1;
    V.ultimo = 0;
}







