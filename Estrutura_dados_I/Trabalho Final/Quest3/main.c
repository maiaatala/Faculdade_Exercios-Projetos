#include "./filaVetor.h"

void print_menu() {
  printf("\n\t+--------+-------------+\n"
          "\t| codigo |    opcao    |\n"
          "\t+========+=============+\n"
          "\t|      0 | Sair        |\n"
          "\t|      1 | Push        |\n"
          "\t|      2 | Pop         |\n"
          "\t|      3 | Imprimir    |\n"
          "\t|      4 | Nova Fila   |\n"
          "\t|      5 | Fila vazia? |\n"
          "\t+--------+-------------+\n"
          "\t        Escolha: ");
}

int main(void) {                //Menu switch case que abriga as funções
  Fila fila;
  fila = criarFila();
  float aux;
  int escolha;

  do {
    // error_aux = False;
    print_menu();
    scanf("%i", &escolha);
    switch (escolha) {
    case 1:
      printf("\nValor a inserir na fila: ");
      scanf("%f", &aux);
      insereFila(&fila, aux);
      break;
    case 2:
      printf("\n%f retirado da fila\n", removeFila(&fila));
      break;
    case 3:
      imprimeFila(&fila);
      break;
    case 4:
      printf("\nFila Nova Criada\n");
      fila = criarFila();
      break;
    case 5:
      if(fila_vazia(&fila)){
        printf("\nA fila esta vazia\n");
      }else{
        printf("\nA fila NAO esta vazia\n");
      }
      break;
    case 0:
      printf("\n\tbyeee\n");
      break;
    default:
      printf("\n\tOpcao invalida");
      break;
    }
  } while (escolha != 0);
  return 0;
}