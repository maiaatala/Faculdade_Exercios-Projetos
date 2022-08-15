#include "./Lista.h"

void print_menu(void){
  printf("\n\t+--------+------------------------------+\n"
        "\t| codigo |            opcao             |\n"
        "\t+--------+------------------------------+\n"
        "\t|      0 | sair                         |\n"
        "\t|      1 | inserir                      |\n"
        "\t|      2 | remover                      |\n"
        "\t|      3 | consultar elemento           |\n"
        "\t|      4 | imprimir lista1              |\n"
        "\t|      5 | imprimir lista2              |\n"
        "\t|      6 | copiar lista1 para lista2    |\n"
        "\t|      7 | concatenar lista1 com lista2 |\n"
        "\t|      8 | apagar lista1                |\n"
        "\t|      9 | apagar lista2                |\n"
        "\t+--------+------------------------------+\n"
        "\t        Escolha: ");
}

int main(void) {
  Lista *lista, *L2;
  L2 = criaLista();
  lista = criaLista();
  int escolha, aux;

  
  do {
    // error_aux = False;
    print_menu();
    scanf("%i", &escolha);
    switch (escolha) {
    case 1:
      printf("\nValor a inserir na lista: ");
      scanf("%i", &aux);
      insereLista(lista, aux);
      break;
    case 2:
      printf("\nValor a remover da lista: ");
      scanf("%i", &aux);
      removeElemento(lista, aux);
      break;
    case 3:
      printf("\nValor a conferir na lista: ");
      scanf("%i", &aux);
      if(buscaElemento(lista, aux) != NULL){
        printf("Valor existe na lista");
      }else{
        printf("Valor NAO existe na lista");
      }
      break;
    case 4:
      printf("\nLista 1:\n");
      imprimeLista(lista);
      break;
    case 5:
      printf("\nLista 2:\n");
      imprimeLista(L2);
      break;
    case 6:
      copiaLista(lista, L2);
      break;
    case 7:
      concatenaLista(lista, L2);
      break;
    case 8:
      apagaLista(lista);
      printf("\nLista1 Apagada\n");
      break;
    case 9:
      apagaLista(L2);
      printf("\nLista2 Apagada\n");
      break;
    case 0:
      printf("\n\tbyeee\n");
      break;
    default:
      printf("\n\tOpcao invalida");
      break;
    }
  } while (escolha != 0);
  apagaLista(lista);
  apagaLista(L2);
  free(lista);
  free(L2);
  
  return 0;
}
