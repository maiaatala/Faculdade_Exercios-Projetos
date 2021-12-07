#include "cadastro.h"
// #include <string.h>

// get index by THE ID INPUT for the delete and update

// update

// delete

// sorts

// take the read and save file from main and put here

// create
void get_info(PSEmpresa emp, int n){
    int i;
    
    if (emp->curr_size == 0){
        emp->func = (SFuncionario*)malloc(sizeof(SFuncionario)*n);
    }else{
        emp->func = realloc(emp->func, sizeof(SFuncionario)*(emp->curr_size+n));
    }
    
    for (i = emp->curr_size; i < (emp->curr_size+n); i++){
        emp->func[i].id = (emp->last_id++);
        printf("Nome: ");
        f_gets(emp->func[i].name, stdin, true);
        // emp->func[i].name = getstr(stdin, true);
        printf("Horas: ");
        scanf("%i", &emp->func[i].horas);
        clean_stdin();
    }
    emp->curr_size += n;
}

// Read
void read_info(PSEmpresa emp){
    int i;
    printf("current size: %i   last id: %i   \n", emp->curr_size, emp->last_id);
    for (i = 0; i < (emp->curr_size); i++){
        printf("id: %i   nome: %s   horas: %i\n", emp->func[i].id, emp->func[i].name, emp->func[i].horas);
    }
}

// Save to file
void save_to_file(PSEmpresa emp){
    int i;
    FILE *outfile;
    
    // open file for writing
    outfile = fopen ("person.dat", "w");
    // verify if it was opened suceffuly 
    if (outfile == NULL){
        printf("Error openning the file.\n");
        // fprintf(stderr, "\nError opened file\n");
        exit (1); //exit failure
    }else{
        // function to write the most import data
        for (i=0; i < emp->curr_size; i++){
            fwrite (&emp->func[i], sizeof(SFuncionario), 1, outfile);
        }
    }
    // close file
    fclose (outfile);
}

// reads from file
PSFuncionario read_from_file(){

    SFuncionario read_func;
    PSFuncionario func;
    int i = 0;
    FILE *infile;
    // Open person.dat for reading
    infile = fopen ("person.dat", "r");

    if (infile == NULL){
        fprintf(stderr, "\nError opening file\n");
        exit (1); // exit failure

    }else{

        while(fread(&read_func, sizeof(SFuncionario), 1, infile)){
            /* alocates space if there's content on the txt,
            keeps allocating more space if there's more content on the txt */
            func = (i==0)? malloc(sizeof(SFuncionario)*1):realloc(func, sizeof(SFuncionario)*(i+1));

            func[i].id = read_func.id;
            func[i].horas = read_func.horas;
            str_cpy(func[i].name, read_func.name);

            i++;
        }
        fclose (infile);
        // func = realloc(func, sizeof(SFuncionario)*(i));
        return func;
    }
}

// inicia a struct
void init_db(PSEmpresa emp, int op){
    int i = 0;
    
    if (op == 1){
        
        emp->func = read_from_file();
        // GET DATA FOR EMPRESA.
        // curr_size and last id
        //testing block
        emp->curr_size = 2;
        for (i=0; i < emp->curr_size; i++){
            printf("id: %i   name: %s   Horas: %i\n", emp->func[i].id, emp->func[i].name, emp->func[i].horas);
        }
    }else{
        emp->curr_size = 0;
        emp->last_id = 0;
    }
    
    // printf("hjey\n");
}