//////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h> 
////////////////////////////////////////////////
int main(void)
{
	int m = 100;
	int n = 200;
	int k = 300;
	int* p = NULL;
	int** pp = NULL;

	printf("Address OF m = %p\n", &m);
	printf("Address OF n = %p\n", &n);
	printf("Address OF k = %p\n", &k);

	p = &m;

	printf("Address IN p = %p\n", p);

	printf("BEFORE:m = %d\n", m);
	*p = 1000;
	printf("AFTER:m = %d\n", m);

	pp = &p;

	printf("Address OF p = %p\n", &p);
	printf("Address IN pp = %p\n", pp);

	*pp = &n; // address in p will be &n 

	printf("BEFORE:n = %d\n", n); 
	*p = 2000; 
	printf("AFTER:n = %d\n", n); 

	return (0);
}
////////////////////////////////////////////////////
/*
	int m;

	type(m) ==		int
	type(&m) ==		int*

	int* p;

	type(p) == int*

	Let us substitute T for int*

	type(p) == T
	type(&p) == T*

	Let us substitue back int* for T

	type(&p) == int**

	int** pp;
	pp = &p;

	Let us substitue int** by X.

	type(pp) == int**
	type(pp) == X <substituting X for int**>
	type(&pp) == X* (by rule of type system)
	type(&pp) == int*** <substituting back int** for X>

	int*** ptr = &pp;
*/
/////////////////////////////////////////////////////////
