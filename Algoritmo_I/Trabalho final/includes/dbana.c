#include "dbana.h"

int existe_cliente(struct client C, char *str){
    int flag = -1;
    int value;
    for(int i=0; i <= C.ultimo; i++){
        value = strcmp(str, C.nome[i]);
        if (value == 0){
            flag = i;
        }
    }
    return (flag);
}

int existe_produto(struct db P, char *str){
    int flag = -1;
    int value;
    for(int i = 0; i <= P.ultimo; i++){
        value = strcmp(str, P.nome[i]);
        if (value == 0){
            flag = i;
        }
    }
    return (flag);
}

int main_menu(){ 
    //função para ler as opções do cliente no menu principal
    int m, m1;
    //m sera a opção do menu principal e m1 a opçao dos menus secundários;
    bool flag = false;
    //flag vai indicar se uma opção para sair do menu foi selecionada

    while (!flag){
        do{ //esse loop vai restrigir o input para entre apenas 0 e 3. sera usado varias vezes.
            system("cls");
            printf ("\n       --Menu Principal--\n");
            printf ("+---+-------------------------+\n");
            printf ("| 1 | Acessar m%cdulo Cliente  |\n", o_a);
            printf ("| 2 | Acessar m%cdulo Produto  |\n", o_a);
            printf ("| 3 | M%cdulo de Vendas        |\n", o_a);
            printf ("| 0 | para sair do programa   |\n");
            printf ("+---+-------------------------+\n");
            printf ("           escolha: ");
            scanf  ("%i", &m);
        }while((m<0)||(m>3));

        switch (m) {
            case 0:
                break;
            case 1:
                do{
                    system("cls");
                    printf ("\n         --M%cdulo Cliente--\n", o_a);
                    printf ("+---+------------------------------+\n");
                    printf ("| 1 | Inserir novo Cliente         |\n");
                    printf ("| 2 | Consultar Cliente pelo nome  | \n");
                    printf ("| 3 | Imprimir lista de Clientes   |\n");
                    printf ("| 0 | Retornar ao menu principal   |\n");
                    printf ("+---+------------------------------+\n");
                    printf ("           escolha: ");
                    scanf  ("%i", &m1);
                }while((m1<0)||(m1>3));
                //m*10 + m1 = as opções serao 11 para novo cliente, 12 para consulta pelo nome, 13 imprimir lista, 10 para voltar ao menu principal.
                m *= 10;
                m += m1;
                break;
            case 2:
                do{
                    system("cls");
                    printf ("\n         --M%cdulo Produto--\n", o_a);
                    printf ("+---+------------------------------+\n");
                    printf ("| 1 | Inserir novo Produto         |\n");
                    printf ("| 2 | Consultar Produto pelo nome  |\n");
                    printf ("| 3 | Imprimir lista de Produto    |\n");
                    printf ("| 0 | Retornar ao menu principal   |\n");
                    printf ("+---+------------------------------+\n");
                    printf ("           escolha: ");
                    scanf  ("%i", &m1);
                }while((m1<0)||(m1>3));
                //m*10 + m1 = as opções serao 21 para novo produto, 22 para consulta pelo nome, 23 para imprimir lista, 20 para voltar ao menu principal.
                m *= 10;
                m += m1;
                break;
            case 3:
                do{
                    system("cls");
                    printf ("\n         --M%cdulo de Vendas--\n", o_a);
                    printf ("+---+------------------------------+\n");
                    printf ("| 1 | Registrar Venda de produtos  |\n");
                    printf ("| 2 | Imprimir lista de Vendas     |\n");
                    printf ("| 0 | Retornar ao menu principal   |\n");
                    printf ("+---+------------------------------+\n");
                    printf ("           escolha: ");
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
    strcpy(P.nome[0], "guanabara\0");
    P.qnt[0] = 1000;
    P.preco[0] = 25.0;
    P.ultimo = 0;
    return(P);
}

struct client in_cliente(struct client C){
    strcpy(C.nome[0], "gunnar ramos\0");
    strcpy(C.nome[1], "ana atala\0");
    C.ultimo = 1;
    return(C);
}

struct dbout in_dbout(struct dbout V){
    V.registro[0][0] = 0;
    V.registro[0][1] = 1;
    V.registro[0][2] = 1;
    V.v_t[0] = 25.0*1;
    V.ultimo = 0;
    return(V);
}

struct client novo_cliente(struct client C){
    char escolha = 's';
    int i = C.ultimo + 1;
    
    while (((escolha == 's')||(escolha == 'S')) && (i < n_arr)){
        printf ("Escreva o nome do Cliente: ");
        fflush (stdin); //algum /n estava entrando no meio do fgets
        fgets (C.nome[i], c_max, stdin);
        fflush (stdin);
        //tratando a string
        C.nome[i][strlen(C.nome[i])-1] = '\0';
        if (existe_cliente(C, C.nome[i]) == -1){
            C.ultimo = i; //marca qual foi o ultimo cliente inserido
            i++;
        }else{
            printf ("!! Error: Cliente j%c existe !!\n", a_a);
        }
        //preparando outro loop
        printf ("Cliente registrado!\n>>>> Deseja inserir outro cliente? (s/n): ");
        scanf (" %c", &escolha);
    }

    if (i >= n_arr){
        printf ("\n!! Error: Limite de cliente excedido !!\n");
    }
    return (C);
}

void consulta_cliente(struct client C){
    char temp[c_max], escolha;

    do{
        printf("Escreva o nome que deseja consultar: \n>>>> ");
        fflush (stdin); //algum /n estava entrando no meio do fgets
        fgets (temp, c_max, stdin);
        fflush (stdin);
        //tratamento da string
        temp[strlen(temp)-1] = '\0';  

        if (existe_cliente(C, temp) != -1){
            printf ("j%c existe um cliente com o nome %s\n", a_a, temp);
        }else{
            printf ("N%co existe um cliente com esse nome\n", a_t);
        }

        printf (">>>> Deseja consultar outro cliente? (s/n): ");
        scanf (" %c", &escolha);
        printf ("\n");
    }while((escolha == 's')||(escolha == 'S'));
}

void mostrar_cliente(struct client C){
    int i;
    printf ("+----+-----------------------------+\n");
    printf ("| id |           cliente           |\n");
    printf ("+----+-----------------------------+\n");
    for (i = 0; i <= C.ultimo; i++){
        printf ("| %-3i|    %-25s|\n", i, C.nome[i]);
    }
    printf ("+----+-----------------------------+\n");
}

struct db novo_produto(struct db P){
    int i = (P.ultimo + 1);
    char escolha = 's';

    while ((i <= n_arr) && ((escolha == 's')||(escolha == 'S'))){
        printf ("Nome do novo produto: ");
        fflush (stdin); //algum /n estava entrando no meio do fgets
        fgets (P.nome[i], c_max, stdin);
        fflush (stdin);
        //tratamento de string
        P.nome[i][strlen(P.nome[i])-1] = '\0';
        if (existe_produto(P, P.nome[i]) == -1){
            printf ("Pre%co de 1 unidade: ", cs);
            scanf ("%f", &P.preco[i]);
            printf ("Quantidade do produto disponivel: ");
            scanf ("%i", &P.qnt[i]);
            P.ultimo = i;
            i++;
        }else{
            printf ("!! Error: Produto j%c existe !!\n", a_a);
        }
        printf ("Produto Inserido!\n>>>> Deseja inserir outro produto? (s/n): ");
        scanf (" %c", &escolha);
    }
    if (i >= n_arr){
        printf ("\n!! Error: Limite de Produto excedido !!\n");
    }
    return (P);
}

void consulta_produto(struct db P){
    char temp[c_max], escolha;

    do{
        printf ("Escreva o Produto que deseja consultar: \n>>>> ");
        fflush (stdin);
        fgets (temp, c_max, stdin);
        fflush (stdin);
        //tratamento string
        temp[strlen(temp)-1] = '\0';

        if (existe_produto(P, temp) != -1){
            printf ("Produto j%c cadastrado\n", a_a);
        }else{
            printf ("Produto n%co cadastrado\n", a_t);
        }
        printf (">>>> Deseja consultar outro produto? (s/n): ");
        scanf (" %c", &escolha);
        printf ("\n");
    }while((escolha == 's')||(escolha == 'S'));

}

void mostrar_produto(struct db P){
    int i;
    printf ("+----+-----------------------------+-------+-----------+\n");
    printf ("| id |           produto           |  qnt  |   pre%co   |\n",cs);
    printf ("+----+-----------------------------+-------+-----------+\n");
    for(i = 0; i <= P.ultimo; i++){
        printf ("| %-3i|    %-25s|  %-5i|  %-9.2f|\n", i, P.nome[i], P.qnt[i], P.preco[i]);
    }
    printf ("+----+-----------------------------+-------+-----------+\n");
}

struct dbout nova_venda(struct dbout V, struct db * P, struct client C){
    char escolha = 's', tempchar[c_max];
    int i = (V.ultimo+1), tempint;
    bool loop = true, loop_in = true;
    /* creates a temporary struct that is exactly like P
    'cuz issues working it with the pointer adress; */
    struct db tempP = *P; 

    printf ("--lista de clientes--\n");
    mostrar_cliente(C);
    printf ("--lista de produtos--\n");
    mostrar_produto(tempP);

    if (i >= n_arr){
        loop = false;
    }
    while(loop){
        //loop registro cliente
        while (loop_in){
            printf ("Cliente: ");
            fflush (stdin); //algum /n estava entrando no meio do fgets
            fgets (tempchar, c_max, stdin);
            fflush (stdin);
            tempchar[strlen(tempchar)-1] = '\0';
            tempint = existe_cliente(C, tempchar);
            //bloco caso usuario escreva um cliente que nao existe
            if (tempint == -1){ 
                printf ("Cliente n%co registrado\n", a_t);
                printf (">>>> deseja sair do registro de venda? (s/n): ");
                scanf (" %c", &escolha);
                if ((escolha == 's')||(escolha == 'S')){
                    loop_in = false;
                    return(V); //sai do registo de venda pro cliente voltar ao main menu
                }else{
                    loop_in = true;
                }
            }else{
                loop_in = false;
            }
        }
        V.registro[i][1] = tempint; //salva o id do cliente
        loop_in	= true;

        //loop registro produto
        while (loop_in){
            printf ("Produto: ");
            fflush (stdin); //algum /n estava entrando no meio do fgets
            fgets (tempchar, c_max, stdin);
            fflush (stdin);
            tempchar[strlen(tempchar)-1] = '\0';
            tempint = existe_produto(*P, tempchar);
            //bloco caso usuario escreva um cliente que nao existe
            if (tempint == -1){ 
                printf ("Produto n%co registrado\n", a_t);
                printf (">>>> deseja sair do registro de venda? (s/n): ");
                scanf (" %c", &escolha);
                if ((escolha == 's')||(escolha == 'S')){
                    loop_in = false;
                    return(V); //sai do registo de venda pro cliente voltar ao main menu
                }else{
                    loop_in = true;
                }
            }else{
                loop_in = false;
            }
        }
        V.registro[i][0] = tempint; //salva o id do produto
        loop_in	= true;
        
        //loop registro quantidade
        while (loop_in){
            printf ("Quantidade: ");
            scanf ("%i", &tempint);
            if (tempint > tempP.qnt[V.registro[i][0]]){
                printf ("!! Error, estoque insuficiente, compre %i ou menos\n", tempP.qnt[V.registro[i][0]]);
                printf (">>>> Deseja inserir outra quantidade? (s/n): ");
                scanf (" %c", &escolha);
                if ((escolha == 's')||(escolha == 'S')){
                    loop_in = true;
                }else{
                    loop_in = false;
                    return(V);
                }
            }else{
                loop_in = false;
            }
        }
        tempP.qnt[V.registro[i][0]] -= tempint; //diminui a quantidade na struct do produto
        V.registro[i][2] = tempint; //salva a quantidade comprada

        V.v_t[i] = tempP.preco[V.registro[i][0]]*V.registro[i][2]; //calcula o valor total
        V.ultimo = i; //salva o ultimo indice utilizado da struct vendas
        //preparação pro prox loop
        loop_in	= true;
        i++;
        //verificacoes do loop
        if (i >= n_arr){
            loop = false;
        }
        printf ("Venda Registrada!\n>>>> Deseja Registrar nova venda? (s/n): ");
        scanf (" %c", &escolha);
        if ((escolha != 's')&&(escolha != 'S')){
            loop = false;
        }
    }
    *P = tempP; //salva as mudanças no adress correto da struct product
    //verificacao se limite estorou
    if (i >= n_arr){
        printf ("!! error, limite de vendas atingido !!\n");
    }
    return(V);
}

void mostrar_vendas(struct dbout V, struct db P, struct client C){
    int i;
    printf ("+----+-----------------------------+-----------------------------+-------+-----------+\n");
    printf ("| id |           cliente           |           produto           |  qnt  |   total   |\n",cs);
    printf ("+----+-----------------------------+-----------------------------+-------+-----------+\n");
    //id cliente produto qnt valor total
    for(i = 0; i <= V.ultimo; i++){
        printf ("| %-3i|    %-25s|    %-25s|  %-5i|  %-9.2f|\n", i, C.nome[V.registro[i][1]], P.nome[V.registro[i][0]], V.registro[i][2], V.v_t[i]);
    }
    printf ("+----+-----------------------------+-----------------------------+-------+-----------+\n");;
}
