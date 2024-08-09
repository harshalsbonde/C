//////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 

void allocate_and_init(int** pp_arr, int N); 
void show(int** pp_arr, int N); 
void release(int** pp_arr, int N); 

int main(void)
{
    /* 
        arr is array 5 of pointer to int. 
        As array is not initialized, and its 
        defined locally, all five pointers will 
        contain a garbage addresses. 
    */
    int* arr[5]; 

    allocate_and_init(&arr[0], 5); 
    show(arr, 5); 
    release(arr, 5); 

    return (EXIT_SUCCESS); 
}

void allocate_and_init(int** pp_arr, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
    {
        *(pp_arr + i) = (int*)malloc(sizeof(int));  // pp_arr[i] = (int*)malloc(sizeof(int)); 
        if(*(pp_arr + i) == NULL)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE); 
        }
        *pp_arr[i] = (i + 1) * 100; 
    }
}

void show(int** pp_arr, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
        printf("*(*(pp_arr + %d)) = %d\n", i, *(*(pp_arr + i))); 
}

void release(int** pp_arr, int N)
{
    int i; 

    for(i = 0; i < N; ++i)
        free(pp_arr[i]); 
}
//////////////////////////////////////////////////////////////////////////////////////////////
