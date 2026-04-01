#include<stdio.h>

void FACTORIAL_ITERATIVE(int *FACT, int N);

int main()
{
    int N, FACT;
    
    printf("Enter a number to find its factorial (iterative): ");
    scanf("%d", &N);
    
    if(N < 0)
    {
        printf("Factorial not defined for negative numbers\n");
        return 1;
    }
    
    FACTORIAL_ITERATIVE(&FACT, N);
    
    printf("%d! = %d\n", N, FACT);
    
    return 0;
}

void FACTORIAL_ITERATIVE(int *FACT, int N)
{
    // Step 1: If N = 0, set FACT = 1 and return
    if(N == 0)
    {
        *FACT = 1;
        return;
    }
    
    // Step 2: Initialize
    *FACT = 1;
    
    // Step 3: Loop from 1 to N
    for(int K = 1; K <= N; K++)
    {
        *FACT = K * (*FACT);
    }
    
    // Step 4: Return
    return;
}
