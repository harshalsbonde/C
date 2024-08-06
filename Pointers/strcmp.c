//////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////
int cpa_strcmp(char* s1, char* s2); 
/////////////////////////////////////////////////////////
int main(void)
{
    char* s1 = NULL; 
    char* s2 = NULL; 
    int ret_val; 

    s1 = "Hello"; 
    s2 = "Hello"; 

    ret_val = cpa_strcmp(s1, s2); 
    printf("s1 = [%s], s2 = [%s], ret_val = [%d]\n", s1, s2, ret_val); 

    s1 = ""; 
    s2 = ""; 
    ret_val = cpa_strcmp(s1, s2); 
    printf("s1 = [%s], s2 = [%s], ret_val = [%d]\n", s1, s2, ret_val); 

    s1 = "abc"; 
    s2 = "abcdefg"; 
    ret_val = cpa_strcmp(s1, s2); 
    printf("s1 = [%s], s2 = [%s], ret_val = [%d]\n", s1, s2, ret_val);

    s1 = "abcdefg"; 
    s2 = "abc"; 
    ret_val = cpa_strcmp(s1, s2); 
    printf("s1 = [%s], s2 = [%s], ret_val = [%d]\n", s1, s2, ret_val);

    s1 = "abcZ"; 
    s2 = "abca"; 
    ret_val = cpa_strcmp(s1, s2); 
    printf("s1 = [%s], s2 = [%s], ret_val = [%d]\n", s1, s2, ret_val);

    s1 = "CoreProgrammingAcademy"; 
    s2 = "CoreManifacturingIndustry"; 
    ret_val = cpa_strcmp(s1, s2); 
    printf("s1 = [%s], s2 = [%s], ret_val = [%d]\n", s1, s2, ret_val);

    s1 = " "; 
    s2 = ""; 
    ret_val = cpa_strcmp(s1, s2); 
    printf("s1 = [%s], s2 = [%s], ret_val = [%d]\n", s1, s2, ret_val);

    return (EXIT_SUCCESS); 
}
////////////////////////////////////////////////////////////////////////////////////////
int cpa_strcmp(char* s1, char* s2)
{
    size_t i;     

    i = 0; 
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] != s2[i])
        {
            if(s1[i] < s2[i])
                return (-1); 
            else 
                return (1); 
        }

        i = i + 1; 
    }

    if(s1[i] == '\0' && s2[i] == '\0')
        return (0); 

    if(s1[i] != '\0')
        return (1); 
    else 
        return (-1); 
}
///////////////////////////////////////////////////////////////////////////
