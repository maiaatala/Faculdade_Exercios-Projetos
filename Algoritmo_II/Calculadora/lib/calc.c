#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

void soma(){
    float a, b;

    printf ("\nDigite os n%cmeros que deseja somar: \n", u_a);
    scanf("%f", &a);
    scanf("%f", &b);
    printf("A soma de %.2f e %.2f %c: %.2f\n\n", a, b, eh, a+b);
}

void sub(){
    float a, b;

    printf ("\nDigite os n%cmeros que deseja subtrair: \n", u_a);
    scanf("%f", &a);
    scanf("%f", &b);
    printf("A subtra%c%co de %.2f e %.2f %c: %.2f\n\n", cs, a_t, a, b, eh, a-b);
}

void multi(){
    float a, b;

    printf ("\nDigite os n%cmeros que deseja multiplicar: \n", u_a);
    scanf("%f", &a);
    scanf("%f", &b);
    printf("A multiplica%c%co de %.2f e %.2f %c: %.2f\n\n", cs, a_t, a, b, eh, a*b);
}

void divi(){
    float a, b;

    printf ("\nDigite o dividendo: ");
    scanf("%f", &a);
    do{
        printf ("Digite o divisor: ");
        scanf("%f", &b);
        if (b == 0.0){
            printf("divisor n%co pode ser igual a zero\n", a_t);
        }
    }while(b == 0.0);
    printf("A divis%co de %.2f e %.2f %c: %.2f\n\n", a_t, a, b, eh, a/b);
}