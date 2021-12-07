#include "./lib/cadastro.h"

/* main menu must be the place that will gatekeep if curr_size > max_size! */

int main(){
    SEmpresa empresa;
    // bool exists = false;

    // /* INTIALIZE FROM KEYBOARD */
    // init_db(&empresa, false);
    // // printf("hey\n");
    // get_info(&empresa, 2);
    // read_info(&empresa);
    // get_info(&empresa, 2);
    // read_info(&empresa);
    // delete_info(&empresa);
    // read_info(&empresa);
    // save_to_file(&empresa);

    /* INITIALIZE FROM FILE */
    init_db(&empresa, true);
    // read_info(&empresa);
    // // // /* SWAP TEST */
    // // swap(&empresa.func[0], &empresa.func[1]);
    // // // /* DELETE TEST */
    // // // delete_info(&empresa);
    // // // /* UPDATE TEST */
    // update_info(&empresa);
    // read_info(&empresa);
    save_to_file(&empresa);
    /* GET INDEX TEST */
    // printf("index of id 0: %i\n", get_index(&empresa, 0));
}