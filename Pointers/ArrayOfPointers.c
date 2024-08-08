//////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int** pp_arr = NULL; 
    int N = 5;
    int i; 

    pp_arr = (int**)malloc(N * sizeof(int*)); 
    if(pp_arr == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        pp_arr[i] = (int*)malloc(sizeof(int)); 
        if(pp_arr[i] == NULL)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE); 
        }
        *pp_arr[i] = (i + 1) * 100; 
    }

    for(i = 0; i < N; ++i)
        printf("*pp_arr[%d]:%d\n", i, *pp_arr[i]); 

    for(i = 0; i < N; ++i)
        free(pp_arr[i]);
    
    free(pp_arr); 
    pp_arr = NULL; 

    return (EXIT_SUCCESS); 
}
///////////////////////////////////////////////////////////////////////////////////
