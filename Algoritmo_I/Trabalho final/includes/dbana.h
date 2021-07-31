#ifndef DBANA_H_INCLUDED
#define DBANA_H_INCLUDED

//all the libs we use
#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h> //lowercase

//all the defines here
#define n_arr 15 //define qnt de array
#define c_max 300 //define limite de char

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
void mostrar_produto (struct db);
//add new sales
struct dbout nova_venda(struct dbout, struct db *, struct client);
//show sales
void mostrar_vendas (struct dbout, struct db, struct client);

// END IF

#endif