#include "lib/calc.c"

/* HOW TO COMPILE THIS CORRECTLY
ON THE MAIN FILE:
#include "calc.h"
on terminal, USING CMD:
gcc -o main.exe main.c lib/calc.c
TO RUN:
mercado.exe 
TO MAKE IT EASIER TO CODE
change .h to .c and it will compile inside vscode*/

void menu(){
    system("cls");

    printf("+-----------------+\n");
    printf("|   Calculadora   |\n");
    printf("+-----------------+\n");
    printf("| 1 | Somar       |\n");
    printf("| 2 | Subtra%c%co   |\n", cs, a_t);
    printf("| 3 | multiplique |\n");
    printf("| 4 | divida      |\n");
    printf("| 0 | sair        |\n");
    printf("+-----------------+\n");
}

int main(){
    char escolha;
    
    do{
        menu();
        scanf("%c", &escolha);
        switch (escolha){
            case '0':
                printf("byeeeee.");
                break;
            case '1':
                soma();
                system("pause");
                break;
            case '2':
                sub();
                system("pause");
                break;
            case '3':
                multi();
                system("pause");
                break;
            case '4':
                divi();
                system("pause");
                break;
            default:
                break;
        }
    }while(escolha != '0');

    return(0);
}