#ifndef CADASTRO_H
#define CADASTRO_H

// libs
#include "def.h"
#include "lin.h"
#include "str.h"


/* create a new entry */
void get_info(PSEmpresa emp, int n);
/* Reads the database */
void read_info(PSEmpresa emp);

/* Updates an existing entry */

/* Deletes an existing entry */

/* returns the index of the wanted id */

/* Orders alphabetically */

/* Order by hours */

/* inicializes the database */
void init_db(PSEmpresa emp, int op);
/* saves to file */
void save_to_file(PSEmpresa emp);
/* reads from file */
PSFuncionario read_from_file();

#endif