#include "./deque.h"

void print_menu() {
  printf("\n\t+--------+-----------------------------+\n"
        "\t| codigo |            opcao            |\n"
        "\t+========+=============================+\n"
        "\t|      0 | Sair                        |\n"
        "\t|      1 | Inserir Inicio              |\n"
        "\t|      2 | Inserir Fim                 |\n"
        "\t|      3 | Retirar Inicio              |\n"
        "\t|      4 | Retirar Fim                 |\n"
        "\t|      5 | Imprime Deque comeco -> fim |\n"
        "\t|      6 | Imprime Deque fim -> Comeco |\n"
        "\t|      7 | E um palindromo?            |\n"
        "\t|      8 | Criar novo Deque            |\n"
        "\t+--------+-----------------------------+\n"
        "\t        Escolha: ");
}

void f_flush(void){
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

// implementar error_aux
int main(void) {
  char aux;
  int escolha;
  Deque* d = criaDeque();

  do {
    // error_aux = False;
    print_menu();
    scanf("%i", &escolha);
    switch (escolha) {
    case 1:
      printf("\nValor a inserir no comeco do Deque: ");
      f_flush();
      scanf("%c", &aux);
      insereInicio(d, aux);
      break;
    case 2:
      printf("\nValor a inserir no fim do Deque: ");
      f_flush();
      scanf("%c", &aux);
      insereFim(d, aux);
      break;
    case 3:
      printf("\n%c retirado do comeco do Deque\n", retiraInicio(d));
      break;
    case 4:
      printf("\n%c retirado do fim do Deque\n", retiraFim(d));
      break;
    case 5:
      imprimeComecoFim(d);
      break;
    case 6:
      imprimeFimComeco(d);
      break;
    case 7:
      imprimeComecoFim(d);
      if(ehSimetrico(d)){
        printf("O Deque contem um palindromo");
      }else{
        printf("O Deque nao e um palindromo");
      }
      break;
    case 8:
      liberaDeque(d);
      d = criaDeque();
      break;
    case 0:
      printf("\n\tbyeee\n");
      break;
    default:
      printf("\n\tOpcao invalida");
      break;
    }
  } while (escolha != 0);
  
  // printf("%s\n", d->ini);
  // printf("Hello World\n");
  // insereInicio(d, 'a');
  // insereInicio(d, 'b');
  // insereInicio(d, 'c');
  // insereInicio(d, 'b');
  // insereInicio(d, 'a');
  // insereInicio(d, 'd');
  // imprimeComecoFim(d);
  // printf("\n%c foi retirado do comeco\n", retiraInicio(d));
  // printf("\n%c foi retirado do fim\n", retiraFim(d));
  // printf("\n%c foi retirado do comeco\n", retiraInicio(d));

  // insereFim(d, 'c');
  // insereFim(d, 'a');
  // insereFim(d, 'c');
  // insereFim(d, 'h');
  // insereFim(d, 'o');
  // imprimeComecoFim(d);
  // imprimeFimComeco(d);
  // printf("\nO deque e simetrico %i", ehSimetrico(d));
  return 0;
}