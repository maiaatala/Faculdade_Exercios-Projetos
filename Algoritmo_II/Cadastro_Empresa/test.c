#include "./lib/str.h"
#include "./lib/cadastro.h"
#include <string.h>

int main(){

    // char name1[] = "abc", name2[] = "abb";
    SFuncionario func1;
    SFuncionario func2;
    printf("write a string: ");
    func1.name = getstr(stdin, true);
    printf("write another string: ");
    func2.name = getstr(stdin, true);
    printf("input: %s, str_len = %i, strlen = %li\n", func1.name, str_len(func1.name), strlen(func1.name));

    printf("\"%s\" \"%s\" str_comp result = %i\n", func1.name, func2.name, str_cmp(func1.name, func2.name));

    something();
}