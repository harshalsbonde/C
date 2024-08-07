/////////////////////////////////////////////////////////////////////////////////
/*
"Core Code   Programming    Academy "
"Core%20Code%20%20%20Programming%20%20%20%20Academy%20"

IN-PLACE REPLACEMENT
*/

#include <stdio.h> 
#include <stdlib.h> 

#define TRUE 1 

size_t cpa_strlen(char* str); 
char* cpa_strdup(char* str); 
char* URLfy(char* input_string); 

int main(void)
{
    char* given_string = " Core Code   Programming    Academy "; 
    char* input_string = NULL; 

    input_string = cpa_strdup(given_string); 
    printf("INPUT STRING BEFORE URLfy = [%s]\n", input_string); 
    input_string = URLfy(input_string); 
    printf("INPUT STRING AFTER URLfy = [%s]\n", input_string); 
    free(input_string); 
    input_string = NULL; 

    return (EXIT_SUCCESS); 
}

char* URLfy(char* input_string)
{
    size_t length; 
    size_t new_length; 
    size_t nr_spaces; 
    size_t new_size; 
    size_t i, j; 

    length = 0; 
    nr_spaces = 0; 
    i = 0; 
    while(input_string[i] != '\0')
    {
        if(input_string[i] == ' ')
            nr_spaces += 1; 
        length += 1; 
        i += 1;
    }

    if(nr_spaces == 0)
        return (input_string);

    new_size = length + 1 + 2 * nr_spaces; 
    input_string = (char*)realloc(input_string, new_size); 
    if(input_string == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }
    input_string[new_size-1] = '\0'; 

    new_length = new_size - 1; 
    
    /* 0 to new_length - 1 is a valid index range in input_string */
    j = new_length-1; 
    i = length-1; 
    while(TRUE)
    {
        if(input_string[i] != ' ')
        {
            input_string[j] = input_string[i]; 
        }
        else 
        {
            input_string[j] = '0'; 
            input_string[j-1] = '2'; 
            input_string[j-2] = '%'; 
            if(i == j-2)
                return (input_string);
            else 
                j -= 2; 
        }

        j -= 1; 
        i -= 1; 
    }

    return (input_string); 
}
//////////////////////////////////////////////////////////////
char* cpa_strdup(char* str)
{
    char* new_string = NULL; 
    size_t length; 
    size_t i; 

    length = cpa_strlen(str); 
    new_string = (char*)malloc(length + 1); 
    if(new_string == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }
    new_string[length] = '\0'; 

    i = 0; 
    while(i < length)
    {
        new_string[i] = str[i]; 
        i += 1; 
    }

    return (new_string); 
}
/////////////////////////////////////////////////////////////////////
size_t cpa_strlen(char* str)
{
    size_t i; 
    size_t length; 
    
    length = 0; 
    i = 0; 
    while(str[i] != '\0')
    {
        length += 1; 
        i += 1; 
    }

    return (length); 
}
///////////////////////////////////////////////////////////////////////
