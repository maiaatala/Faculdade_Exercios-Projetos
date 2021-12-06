#ifndef DEFINITION_H
#define DEFINITION_H

// libs
#include <stdio.h>
#include <stdlib.h>

// constant variables
#define path "./db/empresa.txt"
#define max_funcionarios 21

// creates the boolean type
typedef enum {false, true} bool;

// structs
/*Struct para armazeanr os dados do funcionário
char *nome
int horas
*/
struct Funcionario{
    char * name;
    int horas;
};
typedef struct Funcionario SFuncionario; //Struct Funcionario
typedef struct Funcionario * PSFuncionario; //Pointer To Struct Funcionario

/*"Tabela" empresa
int count as current numbers of employee
Funcionario[21] func*/
struct Empresa{
    int count;
    PSFuncionario * func; 
};
typedef struct Empresa SEmpresa;
typedef struct Empresa * PSEmpresa;

#endif