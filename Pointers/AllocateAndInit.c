///////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
///////////////////////////////////////////////////////////////////////////////////////////
struct Date
{
    int day; 
    int month; 
    int year; 
}; 
///////////////////////////////////////////////////////////////////////////////////////////
struct Date* allocate_and_init_1(int init_day, int init_month, int init_year); 
void allocate_and_init_2(struct Date** ppDate, int init_day, int init_month, int init_year); 
///////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    /*********************FUNCTION:allocate_and_init_1() TEST****************/
    struct Date* pDate_1 = NULL; 

    printf("pDate_1 = %p\n", pDate_1); 
    pDate_1 = allocate_and_init_1(13, 3, 2024); 
    printf("pDate_1 = %p\n", pDate_1); 

    printf("%d-%d-%d\n", pDate_1->day, pDate_1->month, pDate_1->year); 

    free(pDate_1); 
    pDate_1 = NULL; 

    /*********************FUNCTION:allocate_and_init_2() TEST****************/

    struct Date* pDate_2 = NULL; 

    printf("pDate_2 = %p\n", pDate_2); 
    allocate_and_init_2(&pDate_2, 13, 3, 2024); 
    printf("pDate_2 = %p\n", pDate_2); 

    printf("%d-%d-%d\n", pDate_2->day, pDate_2->month, pDate_2->year); 

    free(pDate_2); 
    pDate_2 = NULL; 

}
///////////////////////////////////////////////////////////////////////////////////////
struct Date* allocate_and_init_1(int init_day, int init_month, int init_year)
{
    struct Date* ptrDate = NULL; 

    ptrDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(ptrDate == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    ptrDate->day = init_day; 
    ptrDate->month = init_month; 
    ptrDate->year = init_year; 

    return (ptrDate); 
}
//////////////////////////////////////////////////////////////////////////////////////////////
void allocate_and_init_2(struct Date** ppDate, int init_day, int init_month, int init_year)
{
    struct Date* ptrDate = NULL; 

    ptrDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(ptrDate == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    ptrDate->day = init_day; 
    ptrDate->month = init_month; 
    ptrDate->year = init_year;   

    *ppDate = ptrDate; 
}
////////////////////////////////////////////////////////////////////////////////////////////////
