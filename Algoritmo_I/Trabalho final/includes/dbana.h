#ifndef DBANA_H_INCLUDED
#define DBANA_H_INCLUDED

//all the libs we use
#include <stdio.h>
#include <stdlib.h>
#include "ascii_acentos.h"
#include <stdbool.h>
#include <string.h>

//all the defines here
#define n_arr 15

//ALL the function prototype

//struct para produtos
struct db;
//struct para clientes
struct client;
//struct para vendas
struct dbout;
//brings out main menu
int main_menu( );
//inicializes the products
struct db in_db(struct db);
//inicializes the clients
struct client in_client(struct client);
//inicializes the sales
struct dbout in_dbout(struct dbout);


// END IF

#endif