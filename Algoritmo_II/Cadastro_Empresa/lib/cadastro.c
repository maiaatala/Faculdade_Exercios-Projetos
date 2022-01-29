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
        printf("\tLido do arquivo com sucesso.\n");
    }
    // Deleta tudo atual do banco de dados e nos arquivos
    else if(op == 2){
        emp->last_id = 0;
        emp->curr_size = 0;
        free(emp->func);

        emp->exists = true;
        printf("\tSessao nova gerada.\n");
    }
    // inicia o banco de dados para receber dados do teclado
    else{
        emp->curr_size = 0;
        emp->last_id = 0;
        emp->exists = true;
        printf("\tSessao nova gerada.\n");
    }
}

// retorna o index PELO ID PROCURADO para o delete e update
int get_index(PSEmpresa emp, int wanted_id){
    int i;

    for (i = 0; i < emp->curr_size; i++){
        if (emp->func[i].id == wanted_id){
            return i;
        }
    }
    return -1;
}

// Recebe os dados para preencher o array do funcionario
void input(PSFuncionario f){
    printf("Nome do Funcionario: ");
    f_gets(f->name, stdin, true);
    // emp->func[i].name = getstr(stdin, true);
    printf("Idade do Funcionario: ");
    scanf(" %i", &f->age);
    clean_stdin();
    printf("Horas Trabalhadas: ");
    scanf(" %i", &f->hours);
    clean_stdin();
}

// create
void get_info(PSEmpresa emp, int n){
    int i;

    //Aloca o espaco necessario para os novos dados
    emp->func = (emp->curr_size == 0)? malloc(sizeof(SFuncionario) * n) : realloc(emp->func, (sizeof(SFuncionario) * (emp->curr_size + n)));
    for (i = emp->curr_size; i < (emp->curr_size + n); i++){
        // need to increment it like this so it does work when makeing new entires after file read
        emp->func[i].id = (emp->last_id++)+1; 
        input(&emp->func[i]); // funcao para receber o nome, idade, horas.
    }
    emp->curr_size += n; // atualiza o tamanho do atual do array de funcionarios
    printf("\tRegistros feitos com sucesso.\n");
}

// Read
void read_info(PSEmpresa emp){
    int i;
    printf("\tcurrent size: %i   last id: %i   \n", emp->curr_size, emp->last_id);
    printf(
        "\t+----+--------------------+-------+-------+\n"
        "\t| id |        nome        | idade | horas |\n"
        );
    for (i = 0; i < (emp->curr_size); i++){
        printf(
            "\t| %2i | %-18s | %-5i | %-5i |\n",
            emp->func[i].id, emp->func[i].name, emp->func[i].age, emp->func[i].hours
        );
    }
    printf("\t+----+--------------------+-------+-------+\n");
}

// update
void update_info(PSEmpresa emp){
    int id, index;
    
    printf("ID para fazer UPDATE no banco de dados: ");
    scanf("%i", &id);
    clean_stdin();
    index = get_index(emp, id); //pega o index do id inserido

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
    index = get_index(emp, id); //pega o index do id inserido

    if (index < 0){
        printf("Registro nao encontrado, tente um ID que exista\n");
    }else{
        // "empurra" o dado que quer deletar para o final do array
        for(i = index; i < emp->curr_size-1; i++){
            swap(&emp->func[i], &emp->func[i+1]);
        }
        emp->curr_size--; // diminui o tamanho atual do array de funcionario
        // apaga o dado ao "desalocar" o espaco de memoria que ele ocupa
        emp->func = realloc(emp->func, (sizeof(SFuncionario) * emp->curr_size));
    }
}

// swap. funcao auxiliar dos metodos de sort e de delete.
void swap(PSFuncionario ant, PSFuncionario pos){
    SFuncionario temp_func;

    /* turns out that this works */
    temp_func = *pos;
    *pos = *ant;
    *ant = temp_func;

    // /* saving to the temp */
    // str_cpy(temp_func.name, pos->name);
    // temp_func.hours = pos->hours;
    // temp_func.age = pos->age;
    // temp_func.id = pos->id;

    // /* Passing anterior to pos */
    // str_cpy(pos->name, ant->name);
    // pos->hours = ant->hours;
    // pos->age = ant->age;
    // pos->id = ant->id;

    // /* Passing pos to anterior */
    // str_cpy(ant->name, temp_func.name);
    // ant->age = temp_func.age;
    // ant->hours = temp_func.hours;
    // ant->id = temp_func.id;

    

}

// sorts
/* ordena por horas */
void sort_hours(PSEmpresa emp){
    int i, j, k;
    for (i = 0; i < emp->curr_size-1; i++){
        k = i;
        for (j = i+1; j < emp->curr_size; j++){
            if (emp->func[j].hours < emp->func[k].hours){ // compara as horas
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
        for (j = i+1; j < emp->curr_size; j++){
            if (emp->func[j].age < emp->func[k].age){ // compara as idades
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
        for (j = i+1; j < emp->curr_size; j++){
            if (emp->func[j].id < emp->func[k].id){ // compara os id
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
        for (j = i+1; j < emp->curr_size; j++){
            if(str_cmp(emp->func[i].name, emp->func[j].name) > 0){ // compara os nomes
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
    //passa o "emp->curr_size" como referencia para que esta funcao "retorne" mais que um valor
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
            /* Aloca memoria para o vetor de funcionarios se tiver conteudo no txt
            continua alocando mais espaco caso tenha mais conteudo. */
            func = (i == 0) ? malloc(sizeof(SFuncionario) * 1) : realloc(func, sizeof(SFuncionario) * (i + 1));
            func[i] = read_func; // turns out that this works 

            // copia os dados de read_func para o array de funcionario que iremos retornar
            // func[i].id = read_func.id;
            // func[i].hours = read_func.hours;
            // func[i].age = read_func.age;
            // str_cpy(func[i].name, read_func.name);

            i++;
        }
        fclose(infile);
        *len = i; //"retorna" qual o tamanho atual do array de SFuncionario
        return func;
    }
}

// abre os arquivos em modo "w" para apagar os dados neles.
void delete_files(){
    FILE *outfile, *human_outfile;

    outfile = fopen(PATH, "w");
    human_outfile = fopen(HUMAN_PATH, "w");
    if ((outfile == NULL)||(human_outfile == NULL)){
        printf("\tErro tentando abrir o banco de dados\n");
    }else{
        printf("\tEvidencia limpa com sucesso.\n");
    }
    fclose(outfile);
    fclose(human_outfile);
}