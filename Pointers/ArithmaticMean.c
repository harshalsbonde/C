///////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
////////////////////////////////////////////////////////////////////////
int main(void)
{
    double* p_array = NULL; 
    int N; 
    int i; 
    double total_sum; 
    double arithmetic_mean; 

    printf("Enter the size of the array:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    p_array = (double*)malloc(N * sizeof(double)); 
    if(p_array == NULL)
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    i = 0; 
    while(i < N)
    {
        printf("Enter value at index %d:", i); 
        scanf("%d", p_array + i); 
        i = i + 1; 
    }

    total_sum = 0.0; 
    i = 0; 
    while(i < N)
    {
        total_sum = total_sum + *(p_array + i); 
        i = i + 1; 
    }

    arithmetic_mean = total_sum / N; 
    printf("arithmetic_mean:%.3lf\n", arithmetic_mean); 

    free(p_array); 
    p_array = NULL; 

    return (0); 
}
/////////////////////////////////////////////////////////////////////////////
