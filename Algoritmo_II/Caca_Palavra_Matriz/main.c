#include "lib/c_palavra.c"

/* HOW TO COMPILE THIS CORRECTLY
ON THE MAIN FILE:
#include "calc.h"
on terminal, USING CMD:
gcc -o main.exe main.c lib/calc.c
TO RUN:
mercado.exe 
TO MAKE IT EASIER TO CODE
change .h to .c and it will compile inside vscode*/


void print_options(){
    printf ("|             Caca Palavras        |\n"
            "| id |            opcao            |\n"
            "|----|-----------------------------|\n"
            "|  1 | Gerar Matriz aleatoriamente |\n"
            "|  2 | Inserir Matriz              |\n"
            "|  3 | Mostrar Matriz              |\n"
            "|  4 | Inserir palavra             |\n"
            "|  5 | Pesquisa                    |\n"
            "|  6 | Sair                        |\n"
            "      >>>  escolha: "
        );
}

// option 1 resets the Jogo, op 2 resets the word.

int main(){
    Jogo matriz;
    int menu;
    char escolha;
    bool loop = true;

    matriz = init_struct(matriz, 3);


    do{
        system("cls");
        print_options();
        scanf("%i", &menu);

        switch(menu){
            // random matriz
            case 1:
                system("cls");
                if(matriz.m_exists){
                    printf(">>> Ira apagar a Matriz atual, continuar? (s/n): ");
                    scanf(" %c", &escolha);
                    if (escolha == 's'){
                        matriz = generate(matriz);
                        printf("Matriz gerada com sucesso\n\n");
                        system("pause");
                    }
                }else{
                    matriz = generate(matriz);
                    printf("Matriz gerada com sucesso\n");
                    system("pause");
                }
                break;
            // input matriz
            case 2:
                system("cls");
                if (matriz.m_exists){
                    printf(">>> Ira apagar a Matriz atual, continuar? (s/n): ");
                    scanf(" %c", &escolha);
                    if (escolha == 's'){
                        matriz = input_Jogo(matriz);
                        printf("\n");
                        system("pause");
                    }
                }else{
                    matriz = input_Jogo(matriz);
                    printf("\n");
                    system("pause");
                }
                break;
            //mostrar matriz
            case 3:
                system("cls");
                if (matriz.m_exists){
                    show(matriz);
                }else{
                    printf("Matriz ainda não existe, use opção 1 ou 2\n");
                }
                system("pause");
                break;
            //inserir palavra
            case 4:
                system("cls");
                if(matriz.caca.w_exists){
                    printf(">>> Ira apagar a palavra atual, continuar? (s/n): ");
                    scanf(" %c", &escolha);
                    if (escolha == 's'){
                        matriz = nova_palavra(matriz);
                    }
                }else{
                    
                    matriz = nova_palavra(matriz);
                }
                system("pause");
                break;
            //busca esquerda -> dir
            case 5:
                system("cls");
                if(matriz.caca.w_exists & matriz.m_exists){
                    pesquisa(matriz);
                }else{
                    printf("Matriz ou palavra nao inserida. tente novamente\n");
                }
                system("pause");
                break;
            default:
                printf("\n Made By: Ana Atala");
                printf("\n \t-byeee.\n");
                system("pause");
                loop = false;
        }
    }while(loop);

    return (0);
}