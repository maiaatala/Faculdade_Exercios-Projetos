#include "./lib/str.h"
#include "./lib/cadastro.h"
#include "./lib/def.h"
#include <string.h>

struct person
{
    int id;
    char fname[20];
    char lname[20];
};

void file_write(){
    // a struct to read and write
    FILE *outfile;
    
    // open file for writing
    outfile = fopen ("person.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    struct person input1 = {1, "rohan", "sharma"};
    struct person input2 = {2, "mahendra", "dhoni"};
    
    // write struct to file
    fwrite (&input1, sizeof(struct person), 1, outfile);
    fwrite (&input2, sizeof(struct person), 1, outfile);
    
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);
}

void file_read(){
    FILE *infile;
    struct person input;
    
    // Open person.dat for reading
    infile = fopen ("person.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    
    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, infile))
        printf ("id = %d name = %s %s\n", input.id,
        input.fname, input.lname);

    printf("name = %s\n", input.fname);
    // close file
    fclose (infile);
}

int main(){
    file_write();
    file_read();


    return 0;
}