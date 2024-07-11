//////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
///////////////////////////////////////////////////////////////////////////
struct Date
{
    int day; 
    int month; 
    int year; 
}; 

//////////////////////////////////////////////////////////////////////////
struct Date* a[5]; 
////////////////////////////////////////////////////////////////////////
int main(void)
{
    int i; 

    i = 0; 
    while(i <= 4)
    {
        a[i] = (struct Date*)malloc(sizeof(struct Date)); 
        if(a[i] == NULL)
        {
            puts("Error in allocating memory"); 
            exit(-1); 
        }
        a[i]->day = 1; 
        a[i]->month = 1; 
        a[i]->year = 1970; 
        i = i + 1;
    }

    for(i = 0; i <= 4; ++i)
    {
        free(a[i]); 
        a[i] = NULL; 
    }

    return (0); 
}
/////////////////////////////////////////////////////////////////////
