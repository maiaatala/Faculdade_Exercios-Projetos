#include "lib/c_palavra.h"


void print_options(){
    printf ("|             Caca Palavras        |\n"
            "| id |            opcao            |\n"
            "|----|-----------------------------|\n"
            "|  1 | Gerar Matriz aleatoriamente |\n"
            "|  2 | Inserir Matriz              |\n"
            "|  3 | Mostrar Matriz              |\n"
            "|  4 | Pesquisa                    |\n"
            "|  5 | Sair                        |\n"
            "      >>>  escolha: "
        );
}

int main(){
    /*Devido ao fflsuh nao funcionar,
    e fgets ser estranho, há situacoes que
    precisará pressionar o enter varias vezes*/
    Jogo matriz;
    int menu;
    char escolha;
    bool loop = true;

    matriz.m_exists = false;

    do{
        system("clear");
        print_options();
        scanf("%i", &menu);

        switch(menu){
            /*Gerar matriz aleatoriamente*/
            case 1:
                system("clear");
                /*checa se o usuario ja inseriu uma matriz*/
                if(matriz.m_exists){
                    printf(">>> Ira apagar a Matriz atual, continuar? (s/n): ");
                    scanf(" %c", &escolha);
                    if (escolha == 's'){
                        matriz = generate(matriz);
                        printf("\nMatriz gerada com sucesso\n");
                    }
                }else{
                    matriz = generate(matriz);
                    printf("\nMatriz gerada com sucesso\n");
                }
                clean_stdin();
                pause();
                
                break;

            /*Usuario faz o input da matriz*/
            case 2:
                system("clear");
                /*checa se o usuario ja inseriu uma matriz*/
                if (matriz.m_exists){
                    printf(">>> Ira apagar a Matriz atual, continuar? (s/n): ");
                    scanf(" %c", &escolha);
                    if (escolha == 's'){
                        matriz = input_Jogo(matriz);
                        printf("\n");
                    }
                }else{
                    matriz = input_Jogo(matriz);
                }
                /* esse bloco existe, pois o processo pode quitar sem inserir
                uma matriz se o usuario inserir numero incorreto de char*/
                if (matriz.m_exists){
                    printf("Matriz gerada com sucesso\n");
                    clean_stdin();
                }
                pause();
                break;

            /*Mostra a matriz*/
            case 3:
                system("clear");
                /*checa se o usuario ja inseriu uma matriz*/
                if (matriz.m_exists){
                    printf("\t\tJogo Atual: \n");
                    show(matriz);
                }else{
                    printf("Matriz ainda não existe, use opção 1 ou 2\n");
                }
                clean_stdin();
                pause();
                break;

            /*Pede ao usario uma palavra e a procura na matriz armazenada*/
            case 4:
                system("clear");
                /*checa se o usuario ja inseriu uma matriz*/
                if(matriz.m_exists){
                    matriz = nova_palavra(matriz);
                    printf("\n");
                    pesquisa(matriz);
                    printf("\n");
                }else{
                    printf("Matriz nao inserida. tente novamente\n");
                    clean_stdin();
                }
                pause();
                break;

            /*sai do loop com uma mensagem de despedida*/
            default:
                printf("\n Made By: Ana Atala");
                printf("\n \t-byeee.\n");
                printf("\n\n");
                loop = false;
        }
    }while(loop);

    return (0);
}