///////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h>
///////////////////////////////////////////////////////
void alloc_and_init_int(int** pp, int n); 
///////////////////////////////////////////////////////
int main(void)
{
	int* p = NULL; 

	alloc_and_init_int(&p, 500); 
	printf("*p = %d\n", *p); 
	free(p); 
	p = NULL; 

	return (0); 
}
///////////////////////////////////////////////////////
void alloc_and_init_int(int** pp, int n)
{
	int* ptr = NULL; 

	ptr = (int*)malloc(sizeof(int)); 
	if (ptr == NULL)
	{
		puts("Error in allocating memory"); 
		exit(-1); 
	}

	*ptr = n; 
	
	*pp = ptr; 
}
///////////////////////////////////////////////////////