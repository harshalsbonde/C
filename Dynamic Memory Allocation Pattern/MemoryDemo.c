//////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////////////////
int* allocate_int(void); 
int get(int* p); 
void set(int* p, int new_val); 
void show(int* p); 
///////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    int* new_int = NULL; 

    new_int = allocate_int(); 
    set(new_int, 400); 
    show(new_int); 
    set(new_int, 500); 
    show(new_int); 

    free(new_int); 
    new_int = 0; 

    return (0); 
}
//////////////////////////////////////////////////////////////////////////////
int* allocate_int(void)
{
    int* p = NULL; 

    puts("allocate_int():entered");
    p = (int*)malloc(sizeof(int)); 
    if(p == NULL)
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }
    puts("allocate_int():returning"); 
    return (p);  
}
///////////////////////////////////////////////////////////////////////////////
int get(int* p)
{
    int val; 

    puts("get():entered"); 
    val = *p; 
    puts("get():returning"); 
    return val; 
}
///////////////////////////////////////////////////////////////////////////////
void set(int* p, int new_val)
{
    puts("set():entered"); 
    *p = new_val; 
    puts("set():returning"); 
}
////////////////////////////////////////////////////////////////////////////////
void show(int* p)
{
    printf("show():*p = %d\n", *p); 
}
//////////////////////////////////////////////////////////////////////////////////
