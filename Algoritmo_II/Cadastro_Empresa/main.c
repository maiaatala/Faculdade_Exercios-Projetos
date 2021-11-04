#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs

struct funcionario {
    char *nome;
    short int idade;
    int horas;
};
typedef struct funcionario Tfuncionario;
typedef struct funcionario* PTfuncionario;

struct empresa{
    PTfuncionario funcionario[21];
};

// typedef struct empresa Tempresa;
// typedef struct empresa* PTempresa;

int main(){

    struct empresa *PTempresa, emp;
    PTempresa = &emp;
    printf("hi\n");
    PTempresa->funcionario[1]->nome = (char *) malloc (5 * sizeof(char));
    strcpy(PTempresa->funcionario[1]->nome, "Ana");
    printf("%s\n", PTempresa->funcionario[1]->nome);
    // empresa[1]->nome = (char*) malloc ( 5 * sizeof(char));
    // strcpy(empresa[1]->nome, "Ana");
    

    // printf("%s\n", empresa[1]->nome);
    // free(empresa[1]->nome);

}