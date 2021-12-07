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
void delete_info(PSEmpresa emp);

/* returns the index of the wanted id */
int get_index(PSEmpresa emp, int wanted_id);

/* swap arrays of SFuncionario */
void swap(PSFuncionario ant, PSFuncionario pos);

/* Orders function */

/* Orders alphabetically */

/* Order by hours */

/* Order by Age */

/* inicializes the database */
void init_db(PSEmpresa emp, int op);
/* saves to file */
void save_to_file(PSEmpresa emp);
/* reads from file */
PSFuncionario read_from_file(int *len);

#endif