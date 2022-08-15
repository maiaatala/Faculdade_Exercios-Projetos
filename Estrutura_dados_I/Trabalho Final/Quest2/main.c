#include "./pilhasEmVetor.h"

void print_menu() {
  printf("\n\t+--------+------------------+\n"
        "\t| Codigo |      Opcao       |\n"
        "\t+--------+------------------+\n"
        "\t|      0 | sair             |\n"
        "\t|      1 | Imprime Pilha    |\n"
        "\t|      2 | Empilha A        |\n"
        "\t|      3 | Empilha B        |\n"
        "\t|      4 | Desempilha A     |\n"
        "\t|      5 | Desempilha B     |\n"
        "\t|      6 | Criar Nova Pilha |\n"
        "\t+--------+------------------+\n"
        "\t        Escolha: ");
}

// implementar error_aux
int main(void) {
  Pilha pilha;
  float aux;
  int escolha;
  pilha = CriarPilhas();

  do {                              //Menu switch case
    // error_aux = False;
    print_menu();
    scanf("%i", &escolha);
    switch (escolha) {
    case 1:
      ImprimePilha(pilha);
      break;
    case 2:
      printf("\nValor a Empilhar em A: ");
      scanf("%f", &aux);
      EmpilhaA(&pilha, aux);
      break;
    case 3:
      printf("\nValor a Empilhar em B : ");
      scanf("%f", &aux);
      EmpilhaB(&pilha, aux);
      break;
    case 4:
      printf("\n%f retirado de A\n", DesempilhaA(&pilha));
      break;
    case 5:
      printf("\n%f retirado de B\n", DesempilhaB(&pilha));
      break;
    case 6:
      pilha = CriarPilhas();
      break;
    case 0:
      printf("\n\tbyeee\n");
      break;
    default:
      printf("\n\tOpcao invalida");
      break;
    }
  } while (escolha != 0);
  
  // EmpilhaA(&pilha, 20.5);
  // EmpilhaB(&pilha, 8.74);
  // ImprimePilha(pilha);
  // printf("\n%f retirado de A\n", DesempilhaA(&pilha));
  // ImprimePilha(pilha);
  // printf("\n%f retirado de B\n", DesempilhaB(&pilha));
  // ImprimePilha(pilha);
  // printf("%i, %i,", pilha.topoA, pilha.topoB);
  // printf("%i, %i", vaziaA(pilha), vaziaB(pilha));
  return 0;
}