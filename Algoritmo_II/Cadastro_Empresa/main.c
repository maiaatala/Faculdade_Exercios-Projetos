#include "./lib/str.h"
#include "./lib/cadastro.h"

int main(){
    SEmpresa empresa;
    // bool exists = false;

    /* INTIALIZE FROM KEYBOARD */
    // init_db(&empresa, 0);
    // // printf("hey\n");
    // get_info(&empresa, 2);
    // read_info(&empresa);
    // save_to_file(&empresa);

    /* INITIALIZE FROM FILE */
    init_db(&empresa, 1);
    // // printf("hey\n");
    read_info(&empresa);

    /* GET INDEX TEST */
    // printf("index of id 0: %i\n", get_index(&empresa, 0));
}