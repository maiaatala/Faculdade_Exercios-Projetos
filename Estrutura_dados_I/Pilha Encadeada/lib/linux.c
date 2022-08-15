#include "linux.h"
// fflush nao funciona no linux, essa é a minha versão
void clean_stdin(){
    int c;
    // limpa os \n e EOF do console, para que o fgets e pause funcionem corretamente
    while((c = getchar() != '\n' && c != EOF))
    {    }
}

// linux também nao tem um system("pause"), essa é a minha versão
void pause(){
    printf("\n...Press Enter to continue...\n");
    int c = getchar();
    // o programa fica "parado" esperando um enter.
}