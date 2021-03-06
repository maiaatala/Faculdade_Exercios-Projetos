#ifndef STR_H
#define STR_H

#include "def.h"

/*Reads the string from an input, returns PTstring,
if second argument is set to true, it becomes only lower_case input*/
char* getstr(FILE *fp, bool lower);

/* Reads the *string from an input, returns void 
if last argument is set to true, it becoes only lower_case input*/
void f_gets(char *input, FILE *fp, bool lower);

/*returns the size of the string*/
unsigned int str_len(const char *s);

/* changes the char to it's lowercase form */
void to_lower(int* c);

/*returns = 0: str1 and str2 are exactly the same
returns > 0: str1 comes AFTER str2 alphabetically
returns < 0: str1 comes BEFORE str2 alphabetically*/
int str_cmp(const char* str1, const char* str2);

/* copies the contet of the second *string to the first *string */
void str_cpy(char* dest, const char * source);

#endif