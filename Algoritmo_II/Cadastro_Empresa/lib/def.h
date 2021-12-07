#ifndef DEFINITION_H
#define DEFINITION_H

// libs
#include <stdio.h>
#include <stdlib.h>

// constant variables
#define PATH "./db/empresa.txt"
#define MAX_SIZE 21
#define MAX_CHAR 100

// creates the boolean type
typedef enum
{
    false,
    true
} bool;

// structs
/*Struct para armazeanr os dados do funcionário
char *nome
int horas
*/
struct Funcionario
{
    unsigned int id;
    char name[MAX_CHAR]; //precisa ser tramanho constante para na hora da leitura de arquivo, ele saber alocar os binarios corretos
    int horas;
    int idade;
};
typedef struct Funcionario SFuncionario;   //Struct Funcionario
typedef struct Funcionario *PSFuncionario; //Pointer To Struct Funcionario

/*"Tabela" empresa
int curr_size as current numbers of employee
Funcionario[21] func*/
struct Empresa
{
    int curr_size;
    int last_id;
    struct Funcionario *func;
};
typedef struct Empresa SEmpresa;
typedef struct Empresa *PSEmpresa;

#endif