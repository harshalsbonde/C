////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////
/* 
    ALGORITHM: cpa_strcat()
    Precondition: 
    1) s1 is a string. s1 != NULL. 
    2) s2 is a string. s2 != NULL 
    (s1 or 2 or both are allowed to be empty)

    Post-condition: 
    1) The function should return a DYNAMICALLY ALLOCATED 
    string which is a concatenation of s1 and s2. 

    e.g. 
    char* s1 = "Hello"; 
    char* s2 = "World"; 

    char* s3 = NULL; 

    s3 = cpa_strcat(s1, s2); 

    s3 == "HelloWorld"; 

    free(s3); 
    s3 = NULL; 
*/

unsigned long long int cpa_strlen(char* s); 
char* cpa_strcat(char* s1, char* s2); 

int main(void)
{
    char* s1 = "Hello"; 
    char* s2 = "World!"; 
    char* s3 = NULL; 

    s3 = cpa_strcat(s1, s2); 
    printf("[%s]+[%s]==[%s]\n", s1, s2, s3);

    free(s3); 
    s3 = NULL; 

    return (EXIT_SUCCESS); 
}
///////////////////////////////////////////////////////////
char* cpa_strcat(char* s1, char* s2)
{
    unsigned long long N1; 
    unsigned long long N2; 
    unsigned long long i; 
    char* s3 = NULL; 

    N1 = cpa_strlen(s1); 
    N2 = cpa_strlen(s2); 

    s3 = (char*)malloc(N1 + N2 + 1); 
    if(s3 == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    i = 0; 
    while(i <= (N1-1))
    {
        s3[i] = s1[i]; 
        i = i + 1; 
    }

    i = 0; 
    while(i <= (N2-1))
    {
        s3[N1 + i] = s2[i]; 
        i = i + 1;
    }

    s3[N1 + N2] = '\0';

    return (s3); 
}

unsigned long long int cpa_strlen(char* s)
{
    unsigned long long N; 
    unsigned long long i; 
    
    N = 0; 
    i = 0; 
    while(s[i] != '\0')
    {
        N = N + 1; 
        i = i + 1; 
    }

    return (N); 
}

/* 
///////////////////////////////////////////////////////////
int main(void)
{
    char* str_1 = "Hello"; 
    char* str_2 = "World!"; 
    char* str_3 = NULL; 

    //  Before call : str_3 == 0 
    cpa_strcat(str_1, str_2, &str_3); 
    // str_3 == ADDRESS 
}
/////////////////////////////////////////////////////////////
void cpa_strcat(char* s1, char* s2, char** pp_s3)
{
    unsigned long long N1; 
    unsigned long long N2; 
    unsigned long long i; 
    char* s3 = NULL; 

    N1 = cpa_strlen(s1); 
    N2 = cpa_strlen(s2); 

    s3 = (char*)malloc(N1 + N2 + 1); 
    if(s3 == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    i = 0; 
    while(i <= (N1-1))
    {
        s3[i] = s1[i]; 
        i = i + 1; 
    }

    i = 0; 
    while(i <= (N2-1))
    {
        s3[N1 + i] = s2[i]; 
        i = i + 1;
    }

    s3[N1 + N2] = '\0';

    *pp_s3 = s3; 
}

unsigned long long int cpa_strlen(char* s)
{
    unsigned long long N; 
    unsigned long long i; 
    
    N = 0; 
    i = 0; 
    while(s[i] != '\0')
    {
        N = N + 1; 
        i = i + 1; 
    }  
}

*/
