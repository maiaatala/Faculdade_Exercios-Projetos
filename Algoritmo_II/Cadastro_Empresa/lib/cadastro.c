#include "cadastro.h"

// get index by THE ID INPUT for the delete and update
int get_index(PSEmpresa emp, int wanted_id){
    int i;

    for (i = 0; i < emp->curr_size; i++){
        if (emp->func[i].id == wanted_id){
            return i;
        }
    }
    return -1;
}

// create
void get_info(PSEmpresa emp, int n){
    int i;

    if (emp->curr_size == 0){
        emp->func = (SFuncionario *)malloc(sizeof(SFuncionario) * n);
    }
    else{
        emp->func = realloc(emp->func, sizeof(SFuncionario) * (emp->curr_size + n));
    }

    for (i = emp->curr_size; i < (emp->curr_size + n); i++){
        emp->func[i].id = (emp->last_id++);
        printf("Nome: ");
        f_gets(emp->func[i].name, stdin, true);
        // emp->func[i].name = getstr(stdin, true);
        printf("Idade: ");
        scanf("%i", &emp->func[i].idade);
        clean_stdin();
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
        printf(
            "id: %i   nome: %s   idade: %i   horas: %i\n",
            emp->func[i].id, emp->func[i].name, emp->func[i].idade, emp->func[i].horas
        );
    }
}

// update


// delete
void delete_info(PSEmpresa emp){
    int id, index, i;
    

    printf("ID para deletar do banco de dados: ");
    scanf("%i", &id);
    clean_stdin();
    index = get_index(emp, id);

    if (index < 0){
        printf("Registro nao encontrado, tente um ID que exista\n");
    }else{
        for(i = id; i < emp->curr_size-1; i++){
            /*  DO A SWAP FUNCTION */
            swap(&emp->func[i], &emp->func[i+1]);
        }
        emp->curr_size--;
        // if there's an error, it is in this line
        emp->func = realloc(emp->func, (sizeof(SFuncionario) * emp->curr_size));
    }

}

// sorts

// swap
void swap(PSFuncionario ant, PSFuncionario pos){
    SFuncionario temp_func;

    /* saving to the temp */
    str_cpy(temp_func.name, pos->name);
    temp_func.horas = pos->horas;
    temp_func.idade = pos->idade;
    temp_func.id = pos->id;

    /* Passing anterior to pos */
    str_cpy(pos->name, ant->name);
    pos->horas = ant->horas;
    pos->idade = ant->idade;
    pos->id = ant->id;

    /* Passing pos to anterior */
    str_cpy(ant->name, temp_func.name);
    ant->idade = temp_func.idade;
    ant->horas = temp_func.horas;
    ant->id = temp_func.id;

}

// Save to file
void save_to_file(PSEmpresa emp){
    int i;
    FILE *outfile;

    // open file for writing
    outfile = fopen(PATH, "w");
    // verify if it was opened suceffuly
    if (outfile == NULL){
        printf("Error openning the file.\n");
        // fprintf(stderr, "\nError opened file\n");
        exit(1); //exit failure
    }
    else{
        // function to write the most import data
        for (i = 0; i < emp->curr_size; i++)
        {
            fwrite(&emp->func[i], sizeof(SFuncionario), 1, outfile);
        }
    }
    // close file
    fclose(outfile);
}

// reads from file
PSFuncionario read_from_file(int *len){

    SFuncionario read_func;
    PSFuncionario func;
    int i = 0;
    FILE *infile;
    // Open person.dat for reading
    infile = fopen(PATH, "r");

    if (infile == NULL){
        fprintf(stderr, "\nError opening file\n");
        exit(1); // exit failure
    }
    else{

        while (fread(&read_func, sizeof(SFuncionario), 1, infile)){
            /* alocates space if there's content on the txt,
            keeps allocating more space if there's more content on the txt */
            func = (i == 0) ? malloc(sizeof(SFuncionario) * 1) : realloc(func, sizeof(SFuncionario) * (i + 1));

            func[i].id = read_func.id;
            func[i].horas = read_func.horas;
            func[i].idade = read_func.idade;
            str_cpy(func[i].name, read_func.name);

            i++;
        }
        fclose(infile);
        *len = i;
        // func = realloc(func, sizeof(SFuncionario)*(i));
        return func;
    }
}

// inicia a struct
void init_db(PSEmpresa emp, int op){
    int i = 0;

    if (op == 1){

        emp->func = read_from_file(&emp->curr_size);
        emp->last_id = 0;
        // printf("K: %i\n", emp->curr_size);
        for (i = 0; i < emp->curr_size; i++){
            // printf("id: %i   name: %s   Horas: %i\n", emp->func[i].id, emp->func[i].name, emp->func[i].horas);
            if (emp->func[i].id > emp->last_id){
                emp->last_id = emp->func[i].id;
            }
        }
    }
    else{
        emp->curr_size = 0;
        emp->last_id = 0;
    }

    // printf("hjey\n");
}