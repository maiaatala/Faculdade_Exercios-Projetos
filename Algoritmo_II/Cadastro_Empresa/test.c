#include "./lib/cadastro.h"

int main(){
    SEmpresa empresa;
    // bool exists = false;

    // /* INTIALIZE FROM KEYBOARD */
    // init_db(&empresa, 0);
    // // printf("hey\n");
    // get_info(&empresa, 2);
    // read_info(&empresa);
    // get_info(&empresa, 2);
    // read_info(&empresa);
    // delete_info(&empresa);
    // read_info(&empresa);
    // save_to_file(&empresa);

    /* INITIALIZE FROM FILE */
    // init_db(&empresa, 1);
    // // read_info(&empresa);
    // // // // /* SWAP TEST */
    // // // swap(&empresa.func[0], &empresa.func[1]);
    // // // // /* DELETE TEST */
    // // // // delete_info(&empresa);
    // // // // /* UPDATE TEST */
    // // update_info(&empresa);
    // // read_info(&empresa);
    // save_to_file(&empresa);
    // /* GET INDEX TEST */
    // // printf("index of id 0: %i\n", get_index(&empresa, 0));
    

    /* testing the delete database */
    // init_db(&empresa, 1);
    // read_info(&empresa);
    // init_db(&empresa, 2);
    // read_info(&empresa);
    // get_info(&empresa, 2);
    // read_info(&empresa);

    // /* testing sorts */
    // init_db(&empresa, 1);
    // read_info(&empresa);
    // /* sort by hrs */
    // sort_hours(&empresa);
    // read_info(&empresa);
    // /* sort by age */
    // sort_age(&empresa);
    // read_info(&empresa);
    // /* sort by name */
    // sort_name(&empresa);
    // read_info(&empresa);
    // // /* sort by id */
    // sort_id(&empresa);
    // read_info(&empresa);

    free(empresa.func);
    return 0;
}