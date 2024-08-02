/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 

unsigned long long int cpa_strlen(char* s); 
///////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    char* s1 = ""; 
    char* s2 = "CoreCode Programming Academy" ; 
    unsigned long long int N1; 
    unsigned long long int N2; 
    
    N1 = cpa_strlen(s1); 
    N2 = cpa_strlen(s2); 

    printf("Length of [%s] = %llu\n", s1, N1); 
    printf("Length of [%s] = %llu\n", s2, N2); 

    return (0); 
}
//////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////
