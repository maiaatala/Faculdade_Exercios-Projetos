#include "./lib/cadastro.h"

void print_menu(){
    printf(
        "\n\t+----+--------------------------+\n"
        "\t| OP |      Navegacao Menu      |\n"
        "\t+----+--------------------------+\n"
        "\t|  1 | Criar Registros          |\n"
        "\t| 12 | Carregar do Banco        |\n"
        "\t|  2 | Ler Registros            |\n"
        "\t| 21 | Ordenar por Nome         |\n"
        "\t| 22 | Ordenar por Horas        |\n"
        "\t| 23 | Ordenar por Idade        |\n"
        "\t| 24 | Ordenar por ID           |\n"
        "\t|  3 | Atualizar Registro       |\n"
        "\t|  4 | Deletar Registro         |\n"
        "\t| 41 | Deletar Sessao Atual     |\n"
        "\t| 42 | Deletar o Banco de Dados |\n"
        "\t|  5 | Salvar No Banco de Dados |\n"
        "\t|  0 | Sair                     |\n"
        "\t+----+--------------------------+\n"
        "\t        Escolha: "
    );
}

int main(){
    SEmpresa empresa;
    int escolha, aux;

    printf(
        "\tDeseja comecar uma sessao nova ou carregar dos arquivos?\n"
        "\t1- Sessao Nova | 2- Carregar do Arquivo\n"
        "escolha: "
    );
    scanf("%i", &escolha);
    clean_stdin();

    if (escolha == 1){
        init_db(&empresa, 0);

    }else if(escolha==2){
        init_db(&empresa, 1);
    }else{
        printf("Opcao invalida!\n");
        exit(1);
    }

    do{
        print_menu();
        scanf("%i", &escolha);
        clean_stdin();
        printf("\n");

        switch(escolha){
            case 1:
                if (empresa.curr_size == MAX_SIZE){
                    printf("\tEmpresa cheia, tente demitir alguem.\n");
                }else{
                    printf("Quantidade de registros a criar: ");
                    scanf("%i", &aux);
                    clean_stdin();
                    if (empresa.curr_size + aux >= MAX_SIZE){
                        printf("\tQuantidade acima da capacidade, tente demitir alguem ou contratar apenas %i\n", MAX_SIZE-empresa.curr_size);
                    }else{
                        get_info(&empresa, aux);
                    }
                }
                break;
            case 12:
                init_db(&empresa, 1);
                break;
            case 2:
                read_info(&empresa);
                break;
            case 21:
                sort_name(&empresa);
                break;
            case 22:
                sort_hours(&empresa);
                break;
            case 23:
                sort_age(&empresa);
                break;
            case 24:
                sort_id(&empresa);
                break;
            case 3:
                update_info(&empresa);
                break;
            case 4:
                delete_info(&empresa);
                break;
            case 41:
                init_db(&empresa, 2);
                break;
            case 42:
                delete_files();
                break;
            case 5:
                save_to_file(&empresa);
                break;
            case 0:
                printf("\t-Byeee\n");
                break;
            default:
                printf("\tOpcao invalida");
                break;
        }
        pause();

    }while(escolha != 0);

    if(empresa.curr_size > 0){
        free(empresa.func);
    }
    printf("\t-Ana Atala\n");
    
    return 0;
}