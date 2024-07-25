///////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int* base_of_array = NULL; 
    int N; 
    int i; 

    printf("Enter number of elements in array:"); 
    scanf("%d", &N); 

    if(N <= 0)
    {
        puts("Size of array cannot be zero or negative. exiting..."); 
        exit(-1); 
    }
    
    base_of_array = (int*)malloc(N * sizeof(int)); 
    if(base_of_array == NULL)
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    i = 0; 
    while(i < N)
    {
        printf("Enter value for element at index %d:", i); 
        scanf("%d", base_of_array + i); 

        i = i + 1; 
    }

    puts("Showing the entered input values:"); 

    i = 0; 
    while(i < N)
    {
        printf("Element at index %d = %d\n", i, *(base_of_array + i)); 
        i = i + 1; 
    }

    puts("Freeing the storage allocated to array"); 
    free(base_of_array); 
    base_of_array = NULL; 

    return (0); 
}
//////////////////////////////////////////////////////////////////////////////////////
