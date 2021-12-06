#include "def.h"
#include "file.h"

void open_file(char* str){
    FILE* f;
    f = fopen(path, "w");

    if(f == NULL){
        perror(path);
        exit(EXIT_FAILURE);
    }

    fwrite(str, 1, sizeof(str), f);
    fclose(f);

}