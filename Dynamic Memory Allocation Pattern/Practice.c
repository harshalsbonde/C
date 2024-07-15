///////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
////////////////////////////////////////////////////////////////////////////////////////////////
struct Test
{
    int a; 
    short b; 
    int c; 
}; 
//////////////////////////////////////////////////////////////////////////////////////////////
struct Test v1; 
///////////////////////////////////////////////////////////////////////////////////////////////
struct Test* allocate_and_init_Test(int init_a, short init_b, int init_c); 
///////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    v1.a = 100; 
    v1.b = 200; 
    v1.c = 300; 
    printf(
        "a = %d, b = %hd, c = %d\n", 
        v1.a, 
        v1.b, 
        v1.c
    ); 

    struct Test* pTest = &v1; 

    pTest->a = 1000; 
    pTest->b = 2000; 
    pTest->c = 3000; 

      printf(
        "a = %d, b = %hd, c = %d\n", 
        v1.a, 
        v1.b, 
        v1.c
    ); 

    pTest = (struct Test*)malloc(sizeof(struct Test)); 
    if(pTest == NULL)
    {
        puts("error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    pTest->a = -1; 
    pTest->b = -2; 
    pTest->c = -3;

    free(pTest); 
    pTest = NULL; 

    pTest = allocate_and_init_Test(150, 250, 350); 
    printf("pTest->a = %d, pTest->b = %hd, pTest->c = %d\n", pTest->a, pTest->b, pTest->c); 
    free(pTest); 
    pTest = NULL; 

    return (0); 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct Test* allocate_and_init_Test(int init_a, short init_b, int init_c)
{
    struct Test* pTest = NULL; 

    pTest = (struct Test*)malloc(sizeof(struct Test)); 
    if(pTest == NULL)
    {
        puts("error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    pTest->a = init_a; 
    pTest->b = init_b; 
    pTest->c = init_c; 

    return (pTest); 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
