////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////
struct Date{
    int day; 
    int month; 
    int year;
};  
/////////////////////////////////////////////////////////////////////
int main(void)
{
    int N = 5; 
    int i; 
    int dd, mm, yy; 

    struct Date* pDate = (struct Date*)malloc(N * sizeof(struct Date)); 
    if(pDate == NULL)
    {
        puts("Error in allocating memory"); 
        exit(-1);
    }

    i = 0; 
    while(i < N)
    {
        (*(pDate + i)).day = 1; 
        (*(pDate + i)).month = 1;
        (*(pDate + i)).year = 1970; 
        i = i + 1;
    }

    i = 0; 
    while(i < N)
    {
        (pDate + i)->day = 1; 
        (pDate + i)->month = 1; 
        (pDate + i)->year = 1970;
        i = i + 1;
    }

    i = 0; 
    while(i < N)
    {
        dd = (*(pDate + i)).day; 
        mm = (*(pDate + i)).month;
        yy = (*(pDate + i)).year; 
        i = i + 1; 
    }

        i = 0; 
    while(i < N)
    {
        dd = (pDate + i)->day;
        mm = (pDate + i)->month; 
        yy = (pDate + i)->year; 
        i = i + 1; 
    }
    
    free(pDate); 
    pDate = NULL; 

    return (0); 
}

/* 
    pDate == base address of array 5 of struct Date 
    pDate == contains the base address of instance of struct Date at index 0 

    pDate + 0 == Base address of instance of struct Date at index 0 
    pDate + 1 == Base address of instance of struct Date at index 1 
    pDate + 2 == Base address of instance of struct Date at index 2 
    pDate + 3 == Base address of instnace of struct Date at index 3 
    pDate + 4 == Base address of instance of struct Date at index 4 

    i = 0; 
    while(i <= 4)
    {
        pDate + i; 
        i = i + 1; 
    }

    type(pDate) == struct Date* 
    type(pDate + i) == struct Date*

    (pDate + i)->day        ==  (*(pDate+i)).day 
    (pDate + i)->month      ==  (*(pDate+i)).month 
    (pDate + i)->year       ==  (*(pDate+i)).year

    *(pDate+i) == pDate[i]

    i = 0; 
    while(i <= 4)
    {
        pDate[i].day 
        pDate[i].month 
        pDate[i].year
        i = i + 1; 
    }

    int a[8]; 
    int* p = &a[0]; 

    *(p + i) == p[i]; 

    a[i] == *(a + i)

    struct Date{} myDate; 
    struct Date* p = &myDate; 

    *p  -> struct Date 
        -> evaluate -> myDate

    (*p).day/month/year
    
    struct T inT; 
    struct T* p = &inT; 

    p->mem == (*p).mem
*/
//////////////////////////////////////////////////////////////////////////
