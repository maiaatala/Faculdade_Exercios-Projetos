#ifndef DBANA_H
#define DBANA_H

//all the libs we use
#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"
#include <stdbool.h>
#include <string.h>

//all the defines here
#define n_arr 15 //define qnt de array
#define c_max 300 //define limite de char

//all the structs here
//tive que deixar as struct aqui ou dava erro

//struct para produtos
struct db { 
    char nome[n_arr][c_max];
    int qnt[n_arr];
    float preco[n_arr];
    int ultimo;
};

//struct para clientes
struct client{
    char nome[n_arr][c_max];
    int ultimo;
};

//struct parav endas
struct dbout{
    //id produto, id cliente, qnt
    int registro[n_arr][3]; 
    float v_t[n_arr];
    int ultimo;
};

//ALL the function prototype
//struct para produtos
struct db;
//struct para clientes
struct client;
//struct para vendas
struct dbout;
//does client exists. returns -1 if not
int existe_cliente(struct client, char *str);
//does product exist. returns -1 if not
int existe_produto(struct db, char *str);
//brings out main menu
int main_menu( );
//inicializes the products
struct db in_db(struct db);
//inicializes the clients
struct client in_cliente(struct client);
//inicializes the sales
struct dbout in_dbout(struct dbout);
//Add new client
struct client novo_cliente(struct client);
//show client
void mostrar_cliente(struct client);
//verify client
void consulta_cliente(struct client);
//insert new product
struct db novo_produto(struct db);
//verify product
void consulta_produto(struct db);
//mostrar lista de produto
void mostrar_produto(struct db);
//add new sales
struct dbout nova_venda(struct dbout, struct db *, struct client);
//show sales
void mostrar_vendas(struct dbout, struct db, struct client);

//All the macro declararion [declare what the functions are]

//#define mostrar_vendas(vendas, produtos, clientes) lists
//parei pq nao vi diferença no vscode.

// END IF
#endif