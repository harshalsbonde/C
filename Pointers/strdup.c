//////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
//////////////////////////////////////////////////////////////////////////
size_t cpa_strlen(char* str); 
char* cpa_strdup(char* source_string, size_t* p_size); 
////////////////////////////////////////////////////////////////////
int main(void)
{
    char* src = "CoreCode Programming Academy"; 
    char* dest = NULL; 
    size_t N = 0; 

    dest = cpa_strdup(src, &N); 

    printf("SOURCE STRING = [%s]. DUPLCATED STRING = [%s]\n", 
        src, dest); 
    
    free(dest); 
    dest = NULL; 

    return (EXIT_SUCCESS); 
}
//////////////////////////////////////////////////////////////////////
char* cpa_strdup(char* source_string, size_t* p_size)
{
    char* destination_string = NULL; 
    size_t n_src; 
    size_t i; 

    n_src = cpa_strlen(source_string); 
    destination_string = (char*)malloc(n_src + 1); 
    if(destination_string == NULL)
    {
        puts(
            "Error in allocating memory"
        ); 
        exit(EXIT_FAILURE); 
    }

    i = 0; 
    while(i <= (n_src-1))
    {
        destination_string[i] = source_string[i]; 
        i = i + 1; 
    }

    destination_string[i] = '\0'; 

    *p_size = n_src; 
    return (destination_string); 
}
///////////////////////////////////////////////////////////////
size_t cpa_strlen(char* str)
{
    size_t i; 
    size_t length; 

    length = 0; 
    i = 0; 
    while(str[i] != '\0')
    {
        length = length + 1; 
        i = i + 1;
    }

    return (length); 
}
//////////////////////////////////////////////////////////////////////
