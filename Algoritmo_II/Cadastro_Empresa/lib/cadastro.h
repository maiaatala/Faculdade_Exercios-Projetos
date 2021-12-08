#ifndef CADASTRO_H
#define CADASTRO_H

// libs
#include "def.h"
#include "lin.h"
#include "str.h"

/* inicializes the database,
if op == 1 reads from the file 
if op == 2 deletes and reestarts the db
if other, starts the db for keyboard input*/
void init_db(PSEmpresa emp, int op);

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

/* returns the index of the wanted id 
if == -1, the id doesn't currently exists */
int get_index(PSEmpresa emp, int wanted_id);

/* swap arrays of SFuncionario
ant passa a ser pos
pos passa a ser ant*/
void swap(PSFuncionario ant, PSFuncionario pos);

/* Orders alphabetically */
void sort_name(PSEmpresa emp);

/* Order by hours */
void sort_hours(PSEmpresa emp);

/* Order by Age */
void sort_age(PSEmpresa emp);

/* Order by ID */
void sort_id(PSEmpresa emp);

/* saves to file, the database .dat, and the human file, .txt*/
void save_to_file(PSEmpresa emp);

/* reads from file */
PSFuncionario read_from_file(int *len);

/* Deletes all the information contained in the files */
void delete_files();

#endif