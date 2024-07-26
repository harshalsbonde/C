//////////////////////////////////////////////////////////////////////////
#include <stdio.h> 
#include <stdlib.h> 
/////////////////////////////////////////////////////////////////////////
int main(void)
{
    int* p_array = NULL; 
    int N = 0; 
    int choice; 
    int data; 
    int i; 

    while(1)
    {
        printf("Do you want to enter one more integer?:[1|Yes, 0|No]");
        scanf("%d", &choice); 

        if(choice != 0 && choice != 1)
        {
            puts("Bad value for choice. exiting the app."); 
            exit(-1); 
        } 

        if(choice == 0)
            break; 

        printf("Enter the value for data:"); 
        scanf("%d", &data); 

        p_array = (int*)realloc(p_array, (N+1) * sizeof(int)); 
        if(p_array == NULL)
        {
            puts("Error in allocating memory"); 
            exit(-1); 
        }

        N = N + 1; 
        *(p_array + N - 1) = data; 
    }

    puts("Elements entered by the end user are:"); 
    for(i = 0; i < N; ++i)
        printf("*(p_array + %d) == %d\n", i, *(p_array + i)); 

    free(p_array); 
    p_array = NULL;     

    puts("End of app"); 

    return (0); 
}
/////////////////////////////////////////////////////////////////////////////
