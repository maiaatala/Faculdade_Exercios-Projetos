#ifndef CADASTRO_H
#define CADASTRO_H

// libs
#include "def.h"
#include "lin.h"
#include "str.h"

/* inicializes the database, if bool reads from the file */
void init_db(PSEmpresa emp, bool op);

/* Fills the attributes of PSFuncionario from the keyboard*/
void input(PSFuncionario f);

/* create a new entries */
void get_info(PSEmpresa emp, int n);

/* Reads the database */
void read_info(PSEmpresa emp);

/* Updates an existing entry */
void update_info(PSEmpresa emp);

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

/* saves to file */
void save_to_file(PSEmpresa emp);

/* saves to HUMANS readable file */

/* reads from file */
PSFuncionario read_from_file(int *len);

#endif