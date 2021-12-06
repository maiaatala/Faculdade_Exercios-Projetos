#include "./lib/str.h"
#include "./lib/cadastro.h"

void test1(PSEmpresa emp){
    int i;
    // SEmpresa empresa;

    // empresa.func = (SFuncionario*)malloc( sizeof(SFuncionario)*2);
    // empresa.curr_size = 2;
    // empresa.func[0].horas = 30;
    // empresa.func[0].name = "heyu";
    // empresa.func[0].id = 0;
    // empresa.last_id = 0;
    // empresa.func[1].horas = 20;
    // empresa.func[1].name = "heyu";
    // empresa.func[1].id = 1;
    // empresa.last_id++;

    // for (i=0; i < empresa.curr_size; i++){
    //     printf("id:%i   name: %s   Horas %i\n", empresa.func[i].id, empresa.func[i].name, empresa.func[i].horas);
    // }

    FILE *outfile;
    
    // open file for writing
    outfile = fopen ("person.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
    for (i=0; i < emp->curr_size; i++){
        fwrite (&emp->func[i], sizeof(SFuncionario), 1, outfile);
    }
    // close file
    fclose (outfile);
}

SFuncionario* read(){
    SFuncionario read_func;
    PSFuncionario func;
    int i = 0; //starts as 1
    FILE *infile;
    infile = fopen ("person.dat", "r");

    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    func = (SFuncionario*)malloc(sizeof(SFuncionario)*21);
    // read_func.name = malloc(sizeof(char)*100);
    while(fread(&read_func, sizeof(SFuncionario), 1, infile)){
        func[i].id = read_func.id;
        // func[i].name = read_func.name;
        func[i].horas = read_func.horas;
        str_cpy(func[i].name, read_func.name);
        i++;
    }
    fclose (infile);
    func = realloc(func, sizeof(SFuncionario)*(i));
    return func;
}

void test2(PSEmpresa emp){
    // test1();
    
    // SEmpresa empresa;
    int i = 0;


    // Open person.dat for reading
    
    
    emp->func = read();
    printf("hjey\n");
    // GET DATA FOR EMPRESA.
    // curr_size and last id
    emp->curr_size = 4;
    for (i=0; i < emp->curr_size; i++){
        // printf("%i\n", emp->func[i].id);
        printf("id:%i   name: %s   Horas %i\n", emp->func[i].id, emp->func[i].name, emp->func[i].horas);
    }

    
}
// testes nao deram certo

int main(){
    SEmpresa empresa;
    empresa.curr_size = 0;
    empresa.last_id = 0;

    // printf("%li\n",sizeof(empresa.func));
    // if (empresa.func==NULL){
    //     printf("hey");
    // }

    // get_info(&empresa, 2);
    // read_info(&empresa);
    // get_info(&empresa, 2);
    // read_info(&empresa);
    // test1(&empresa);

    test2(&empresa);
}