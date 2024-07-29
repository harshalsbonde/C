////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
//////////////////////////////////////////////////////////////////////
int* compute_union(int* pa1, int N1, int* pa2, int N2, int* p_union_N); 
///////////////////////////////////////////////////////////////////////
int main(void)
{
    int* p_union_array = NULL; 
    int N = 0; 
    int i; 

    int a1[] = {10, 20, 30, 40, 10, 40, 50, 60, 70}; 
    int a2[] = {20, 30, 100, 300, 10, 500, 700}; 
    int N1 = (int)(sizeof(a1)/sizeof(a1[0])); 
    int N2 = (int)(sizeof(a2)/sizeof(a2[0])); 

    p_union_array = compute_union(a1, N1, a2, N2, &N); 

    puts("Union of array:"); 
    for(i = 0; i < N; ++i)
        printf("p_union_array[%d]:%d\n", i, p_union_array[i]); 

    free(p_union_array); 
    p_union_array = NULL; 

    return (0); 
}
////////////////////////////////////////////////////////////////////////////
int* compute_union(int* pa1, int N1, int* pa2, int N2, int* p_union_N)
{
    int* a_union = NULL; 
    int N = 0; 
    int i; 
    int j; 
    int flag; 

    for(i = 0; i < N1; ++i)
    {
        flag = 0; 
        if(N > 0)
        {
            for(j = 0; j < N; ++j)
                if(a_union[j] == pa1[i])
                {
                    flag = 1; 
                    break; 
                }
        }

        if(!flag)
        {
            a_union = (int*)realloc(a_union, (N+1)*sizeof(int)); 
            N += 1; 
            a_union[N-1] = pa1[i]; 
        }
    }

    // repeat same loop for pa2 

    *p_union_N = N; 
    return (a_union); 
}
////////////////////////////////////////////////////////////////////////////////
