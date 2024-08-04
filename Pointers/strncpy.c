///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////////////////
size_t cpa_min(size_t a, size_t b); 
size_t cpa_strlen(char* str); 
char* cpa_strncpy(char* destination_string, char* source_string, size_t n); 
//////////////////////////////////////////////////////////////////////////////
int main(void)
{
    char* source_string = "CoreCode Programming Academy"; 
    char* destination_string = NULL; 
    size_t n_src; 

    n_src = cpa_strlen(source_string); 
    destination_string = (char*)malloc(n_src + 1); 
    if(destination_string == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    cpa_strncpy(destination_string, source_string, n_src); 

    printf(
            "SOURCE STRING = [%s], DESTINATION STRING = [%s]\n", 
            source_string, 
            destination_string
        ); 

    free(destination_string); 
    destination_string = NULL; 

    n_src = cpa_strlen("CoreCode"); 
    destination_string = (char*)malloc(n_src + 1); 
    if(destination_string == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    cpa_strncpy(destination_string, source_string, n_src); 
    printf(
            "SOURCE STRING = [%s], DESTINATION STRING = [%s]\n", 
            source_string, 
            destination_string
        ); 

    free(destination_string); 
    destination_string = NULL; 

    return (EXIT_SUCCESS); 
}
/////////////////////////////////////////////////////////////////////////
char* cpa_strncpy(char* destination_string, char* source_string, size_t n)
{
    size_t n_src; 
    size_t n_min; 
    size_t i; 

    n_src = cpa_strlen(source_string); 
    n_min = cpa_min(n_src, n); 

    i = 0; 
    while(i <= (n_min-1))
    {
        destination_string[i] = source_string[i]; 
        i = i + 1; 
    }

    destination_string[i] = '\0'; 
    return (destination_string); 
}
//////////////////////////////////////////////////////////////////
size_t cpa_strlen(char* str)
{
    size_t length = 0; 
    size_t i; 

    i = 0; 
    while(str[i] != '\0')
    {
        length += 1; 
        i += 1;
    }

    return (length); 
}
////////////////////////////////////////////////////////////////////////
size_t cpa_min(size_t a, size_t b)
{
    if(a < b)
        return (a); 
    return (b); 
}
///////////////////////////////////////////////////////////////////////
