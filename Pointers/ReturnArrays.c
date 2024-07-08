///////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h>
///////////////////////////////////////////////////////////////////////////////////////////////
void get_assorted_lists(int** pp_even_array, int* p_even_N, int** pp_odd_array, int* p_odd_N); 
////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int* even_array = NULL; 
    int even_N = 0; 

    int* odd_array = NULL; 
    int odd_N = 0; 

    int i; 

    printf("even_array = %p, even_N = %d\n", even_array, even_N); 
    printf("odd_array = %p, odd_N = %d\n", odd_array, odd_N); 

    get_assorted_lists(&even_array, &even_N, &odd_array, &odd_N); 

    printf("even_array = %p, even_N = %d\n", even_array, even_N); 
    printf("odd_array = %p, odd_N = %d\n", odd_array, odd_N); 

    for(i = 0; i < even_N; ++i)
        printf("*(even_array + %d) = %d\n", i, *(even_array + i)); 

    for(i = 0; i < odd_N; ++i)
        printf("*(odd_array + %d) = %d\n", i, *(odd_array + i)); 

    free(even_array); 
    even_array = NULL; 

    free(odd_array); 
    odd_array = NULL; 

    return (0); 
}
//////////////////////////////////////////////////////////////////////////////////////////////
void get_assorted_lists(int** pp_even_array, int* p_even_N, int** pp_odd_array, int* p_odd_N)
{
    int* p_array = NULL; 
    int N = 0; 
    int i; 

    int* p_even_array = NULL; 
    int N_even = 0; 

    int* p_odd_array = NULL; 
    int N_odd = 0; 

    printf("Enter the desired length of array[5-15]:"); 
    scanf_s("%d", &N); 

    if(N < 5 || N > 15)
    {
        puts("bad value of array length. exiting..."); 
        exit(EXIT_FAILURE); 
    } 

    p_array = (int*)malloc(N * sizeof(int)); 
    if(p_array == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    for(i = 0; i < N; ++i)
    {
        printf("Enter element at index = %d\n", i); 
        scanf_s("%d", p_array + i); 
    }

    for(i = 0; i < N; ++i)
        printf("*(p_array + %d) = %d\n", i, *(p_array + i)); 

    for(i = 0; i < N; ++i)
    {
        if(*(p_array + i) % 2 == 0)
        {
            /*Current Element in array is even*/
            p_even_array = (int*)realloc(p_even_array, (N_even + 1) * sizeof(int));
            if(p_even_array == NULL)
            {
                puts("Error in allocating memory"); 
                exit(EXIT_FAILURE); 
            }
            N_even = N_even + 1;
            *(p_even_array + N_even - 1) = *(p_array + i); 
        }
        else  
        {
            /* Current Element in array is odd */
            p_odd_array = (int*)realloc(p_odd_array, (N_odd + 1) * sizeof(int));
            if(p_odd_array == NULL)
            {
                puts("Error in allocating memory"); 
                exit(EXIT_FAILURE); 
            }
            N_odd = N_odd + 1;
            *(p_odd_array + N_odd - 1) = *(p_array + i); 
        }
    }

    *pp_even_array = p_even_array; 
    *p_even_N = N_even; 

    *pp_odd_array = p_odd_array; 
    *p_odd_N = N_odd; 

    free(p_array); 
    p_array = NULL; 
}
/////////////////////////////////////////////////////////////////////////////////
/* 
    double* p = 5000; 

    p + i; 

    address in p + i * sizeof(double)

    5000 + i * 8 

*/
/////////////////////////////////////////////////////////////////////////////////////
