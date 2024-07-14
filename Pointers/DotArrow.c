///////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
///////////////////////////////////////////////////////////////////////////////
struct Date
{
    int day; 
    int month; 
    int year; 
}; 
///////////////////////////////////////////////////////////////////////////////
int main(void)
{
    struct Date myDate = {14, 3, 2024}; 
    struct Date* p = &myDate; 

    printf("%d-%d-%d\n", myDate.day, myDate.month, myDate.year); 
    printf("%d-%d-%d\n", p->day, p->month, p->year); 
    printf("%d-%d-%d\n", (*p).day, (*p).month, (*p).year); 

    return (0); 
}
//////////////////////////////////////////////////////////////////////////////
/* 
    type(p) == struct Date* 
    type(*p) == struct Date 

    type(myDate) == struct Date 

    myDate.day          (*p).day        p->day 
    myDate.month        (*p).month      p->month 
    myDate.year         (*p).year       p->year
*/
/////////////////////////////////////////////////////////////////////////////////
