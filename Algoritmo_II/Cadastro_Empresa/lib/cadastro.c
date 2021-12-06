#include "cadastro.h"
// #include <string.h>

// get index by THE ID INPUT for the delete and update

// update

// delete

// sorts

// take the read and save file from main and put here

void get_info(PSEmpresa emp, int n){
    int i;
    // 
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

void read_info(                                                                                                            PSEmpresa emp){
    int i;
    printf("current size: %i   last id: %i   \n", emp->curr_size, emp->last_id);
    for (i = 0; i < (emp->curr_size); i++){
        printf("id: %i   nome: %s   horas: %i\n", emp->func[i].id, emp->func[i].name, emp->func[i].horas);
    }
}