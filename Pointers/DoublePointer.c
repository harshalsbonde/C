/////////////////////////////////////////////////////////////////////////////
int n; 
type(n) == int

type(&n) == int* 

int* p; 

type(p) == int*

type(&p) == int**

int** pp = &p; 

type(pp) == int** ->given by programmer
type(*pp) == int*
type(**pp) = int

int* ret = *pp

* pp = p; 
*pp = &n; 

*pp

Let us substitute *pp by p 

*pp		==	p 
*(*pp)  == *p == n 

**pp == n 
  /////////////////////////////////////////////////////////////////////////////////
