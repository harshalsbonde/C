//////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
//////////////////////////////////////////////////////////////////////////////////////
struct Date
{
    int day; 
    int month; 
    int year; 
}; 
//////////////////////////////////////////////////////////////////////////////////////
void allocate_array_of_Date(struct Date*** pppDate, int* pN); 
/////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int i; 
    int N;
    struct Date** ppDate = NULL; 

    allocate_array_of_Date(&ppDate, &N); 

    for(i = 0; i < N; ++i)
    {
        printf("%d-%d-%d\n", ppDate[i]->day, ppDate[i]->month, ppDate[i]->year); 
    }

    for(i = 0; i < N; ++i)
    {
        free(ppDate[i]); 
        ppDate[i] = NULL;
    }

    free(ppDate); 
    ppDate = NULL; 

    return (EXIT_SUCCESS); 
}
///////////////////////////////////////////////////////////////////////////////
void allocate_array_of_Date(struct Date*** pppDate, int* pN)
{
    int i; 
    int N; 
    struct Date** p_ptr_Date = NULL; 

    printf("Enter size of array[5-15]:"); 
    scanf_s("%d", &N); 

    if(N < 5 || N > 15)
    {
        puts("bad length for array"); 
        exit(EXIT_FAILURE); 
    }

    p_ptr_Date = (struct Date**)malloc(N * sizeof(struct Date*)); 
    if(p_ptr_Date == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < N; ++i)
    {
        p_ptr_Date[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(p_ptr_Date[i] == NULL)
        {
            puts("Error in allocating memory"); 
            exit(EXIT_FAILURE);
        }
        p_ptr_Date[i]->day = 1; 
        p_ptr_Date[i]->month = 1; 
        p_ptr_Date[i]->year = 1970;
    }
    
    *pppDate = p_ptr_Date; 
    *pN = N; 
}
/////////////////////////////////////////////////////////////////////////////////////////
