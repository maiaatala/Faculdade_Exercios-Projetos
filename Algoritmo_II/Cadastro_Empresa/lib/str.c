#include "str.h"

// function receives a pointer to the string and return it's length
unsigned int str_len(const char *s){
    unsigned int i = 0;

    //\0 is the end of the str
    while (*s != '\0' && *s != '\n') 
    {
        s++;
        i++;
    }
    return (i);  // returns the same as strlen() from string.h library
}


void to_lower(int* c){
    // UPPERCASE ASCII = 65 to 90
    // lowercase ascii = 97 to 122
    if ((*c >=65) && (*c <= 90)){
        *c += 32;
    }
}

// function that will the user input from fp and save it in a string of variable size
char* getstr(FILE *fp, bool lower){
    int character; // every character in the line
    size_t len = 0, size = 5; // Initial string size and the step of the size
    char *input_string; 
    input_string = malloc(sizeof(*input_string)*size); // creates the variable that will read the input line.

    /* while the character read is not End Of Line or \n
    we can read from other places with FILE *fp and seting fgetc(fp). stdin for the command line input */
    while(EOF != (character=fgetc(fp)) && character != '\n'){ 
        if (lower){
            to_lower(&character);
        }
        input_string[len++] = character; // attributs the character to the input string
        if (len == size){
            // if the current lenght is equal to the allocated memory, alocate more memory.
            input_string = realloc(input_string, sizeof(*input_string)*(size+=size));
        }
    }
    fflush(stdin);
    input_string[len++] = '\0'; // sets the End of Line character to indicate the end of the string.

    // functions returns a pointer to this memory allocation.
    return realloc(input_string, sizeof(*input_string)*len); 
}

// function to compare between two strings and return which comes first alphabetically
int str_cmp(const char* str1, const char* str2){
    // while the char aren't the end of line character, and they are the same, continue to iteract
    while ((*str1 != '\0' && *str2 != '\0') && (*str1 == *str2)){
        str1++; // weird pointer logic
        str2++;
    }
    // after the loop, they'll either be the same end of line character or different ascii values
    // in the ascii tables, the clozer to Z the higher the integer value. 
    return (*str1-*str2);
}