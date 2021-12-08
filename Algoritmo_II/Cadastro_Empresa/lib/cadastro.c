#include "cadastro.h"

// inicia a struct PSEmpresa
void init_db(PSEmpresa emp, int op){
    int i;

    // inicia o banco de dados a partir do arquivo
    if (op==1){
        emp->curr_size = 0;
        emp->last_id = 0;
        emp->func = read_from_file(&emp->curr_size);
        // printf("K: %i\n", emp->curr_size);
        for (i = 0; i < emp->curr_size; i++){
            // printf("id: %i   name: %s   hours: %i\n", emp->func[i].id, emp->func[i].name, emp->func[i].hours);
            if (emp->func[i].id > emp->last_id){
                emp->last_id = emp->func[i].id;
            }
        }
        emp->exists = true;
        printf("\tAccio\n");
    }
    // Deleta tudo atual do banco de dados e nos arquivos
    else if(op == 2){
        emp->last_id = 0;
        emp->curr_size = 0;
        free(emp->func);

        emp->exists = true;
        printf("\tAvada Kedavra\n");
    }
    // inicia o banco de dados para receber dados do teclado
    else{
        emp->curr_size = 0;
        emp->last_id = 0;
        emp->exists = true;
        printf("\tLumos Maxima\n");
    }
}

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

void input(PSFuncionario f){
    printf("Nome do Funcionario: ");
    f_gets(f->name, stdin, true);
    // emp->func[i].name = getstr(stdin, true);
    printf("Idade do Funcionario: ");
    scanf("%i", &f->age);
    clean_stdin();
    printf("Horas Trabalhadas: ");
    scanf("%i", &f->hours);
    clean_stdin();
}

// create
void get_info(PSEmpresa emp, int n){
    int i;

    emp->func = (emp->curr_size == 0)? malloc(sizeof(SFuncionario) * n) : realloc(emp->func, (sizeof(SFuncionario) * (emp->curr_size + n)));
    for (i = emp->curr_size; i < (emp->curr_size + n); i++){
        emp->func[i].id = (emp->last_id++)+1; // need to increment it like this so it does work when makeing new entires after file read
        input(&emp->func[i]);
    }
    emp->curr_size += n;
    printf("\tRegistros feitos com sucesso.\n");
}

// Read
void read_info(PSEmpresa emp){
    int i;
    printf("\tcurrent size: %i   last id: %i   \n", emp->curr_size, emp->last_id);
    for (i = 0; i < (emp->curr_size); i++){
        printf(
            "\tid: %i   nome: %-15s   idade: %-2i   horas: %-2i\n",
            emp->func[i].id, emp->func[i].name, emp->func[i].age, emp->func[i].hours
        );
    }
    printf("\t------------------------------------------------------------\n");
}

// update
void update_info(PSEmpresa emp){
    int id, index;
    
    printf("ID para fazer UPDATE no banco de dados: ");
    scanf("%i", &id);
    clean_stdin();
    index = get_index(emp, id);

    if (index < 0){
        printf("\tRegistro nao encontrado, tente um ID que exista\n");
    }else{
        printf("\tRegistro atual: \n"
            "\tid: %i   nome: %-15s   idade: %-2i   horas: %-2i\n",
            emp->func[index].id, emp->func[index].name, emp->func[index].age, emp->func[index].hours
        );
        input(&emp->func[index]);
    }

}

// delete
void delete_info(PSEmpresa emp){
    int id, index, i;
    
    printf("ID para DELETAR do banco de dados: ");
    scanf("%i", &id);
    clean_stdin();
    index = get_index(emp, id);

    if (index < 0){
        printf("Registro nao encontrado, tente um ID que exista\n");
    }else{
        for(i = index; i < emp->curr_size-1; i++){
            /*  DO A SWAP FUNCTION */
            swap(&emp->func[i], &emp->func[i+1]);
        }
        emp->curr_size--;
        // if there's an error, it is in this line
        emp->func = realloc(emp->func, (sizeof(SFuncionario) * emp->curr_size));
    }

}

// swap
void swap(PSFuncionario ant, PSFuncionario pos){
    SFuncionario temp_func;

    /* saving to the temp */
    str_cpy(temp_func.name, pos->name);
    temp_func.hours = pos->hours;
    temp_func.age = pos->age;
    temp_func.id = pos->id;

    /* Passing anterior to pos */
    str_cpy(pos->name, ant->name);
    pos->hours = ant->hours;
    pos->age = ant->age;
    pos->id = ant->id;

    /* Passing pos to anterior */
    str_cpy(ant->name, temp_func.name);
    ant->age = temp_func.age;
    ant->hours = temp_func.hours;
    ant->id = temp_func.id;
}

// sorts
/* ordena por horas */
void sort_hours(PSEmpresa emp){
    int i, j, k;
    for (i = 0; i < emp->curr_size-1; i++){
        k = i;
        for (j = i; j < emp->curr_size; j++){
            if (emp->func[j].hours < emp->func[k].hours){
                k = j;
            }
        }
        if (k != i){
            swap(&emp->func[i], &emp->func[k]);
        }
    }
    printf("\tRegistros ordenados Por Horas\n");
}

/* ordena por idade */
void sort_age(PSEmpresa emp){
    int i, j, k;
    for (i = 0; i < emp->curr_size-1; i++){
        k = i;
        for (j = i; j < emp->curr_size; j++){
            if (emp->func[j].age < emp->func[k].age){
                k = j;
            }
        }
        if (k != i){
            swap(&emp->func[i], &emp->func[k]);
        }
    }
    printf("\tRegistros ordenados Por Idade\n");
}

/* ordena por ID */
void sort_id(PSEmpresa emp){
    int i, j, k;
    for (i = 0; i < emp->curr_size-1; i++){
        k = i;
        for (j = i; j < emp->curr_size; j++){
            if (emp->func[j].id < emp->func[k].id){
                k = j;
            }
        }
        if (k != i){
            swap(&emp->func[i], &emp->func[k]);
        }
    }
    printf("\tRegistros ordenados Por ID\n");
}

/* ordena por nome */
void sort_name(PSEmpresa emp){
    int i, j;
    for (i = 0; i < emp->curr_size-1; i++){
        for (j = i; j < emp->curr_size; j++){
            if(str_cmp(emp->func[i].name, emp->func[j].name) > 0){
                swap(&emp->func[i], &emp->func[j]);
            }
        }
    }
    printf("\tRegistros ordenados Por Nome\n");
}

// Save to file
void save_to_file(PSEmpresa emp){
    int i;
    FILE *outfile;
    FILE *human_outfile;

    // open file for writing
    outfile = fopen(PATH, "w");
    human_outfile = fopen(HUMAN_PATH, "w");
    // verify if it was opened suceffuly
    if (outfile == NULL){
        printf("Error opening the file.\n");
        // fprintf(stderr, "\nError opened file\n");
        exit(1); //exit failure
    }if (human_outfile == NULL){
        printf("Error opening the human's file.\n");
        // fprintf(stderr, "\nError opened file\n");
        exit(1); //exit failure
    }
    else{
        // function to write the most import data
        for (i = 0; i < emp->curr_size; i++)
        {
            fwrite(&emp->func[i], sizeof(SFuncionario), 1, outfile);
        }
        fclose(outfile);
        for (i=0; i<emp->curr_size; i++){
            fprintf(human_outfile, "%s\n%i\n%i\n", emp->func[i].name, emp->func[i].hours, emp->func[i].age);
        }
        fclose(human_outfile);
    }
    printf("\tMalfeito feito.\n");
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
        printf("Erro ao tentar abrir o banco de dados.\n");
        exit(1); // exit failure
    }
    else{
        while (fread(&read_func, sizeof(SFuncionario), 1, infile)){
            /* alocates space if there's content on the txt,
            keeps allocating more space if there's more content on the txt */
            func = (i == 0) ? malloc(sizeof(SFuncionario) * 1) : realloc(func, sizeof(SFuncionario) * (i + 1));

            func[i].id = read_func.id;
            func[i].hours = read_func.hours;
            func[i].age = read_func.age;
            str_cpy(func[i].name, read_func.name);

            i++;
        }
        fclose(infile);
        *len = i;
        // func = realloc(func, sizeof(SFuncionario)*(i));
        return func;
    }
}

void delete_files(){
    FILE *outfile, *human_outfile;

    outfile = fopen(PATH, "w");
    human_outfile = fopen(HUMAN_PATH, "w");
    if ((outfile == NULL)||(human_outfile == NULL)){
        printf("\tErro tentnaod abrir o banco de dados\n");
    }else{
        printf("\tEvidencia limpa com sucesso.\n");
    }
    fclose(outfile);
    fclose(human_outfile);
}