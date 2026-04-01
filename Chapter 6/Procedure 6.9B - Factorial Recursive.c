#include<stdio.h>

void FACTORIAL_RECURSIVE(int *FACT, int N);

int main()
{
    int N, FACT;
    
    printf("Enter a number to find its factorial (recursive): ");
    scanf("%d", &N);
    
    if(N < 0)
    {
        printf("Factorial not defined for negative numbers\n");
        return 1;
    }
    
    FACTORIAL_RECURSIVE(&FACT, N);
    
    printf("%d! = %d\n", N, FACT);
    
    return 0;
}

void FACTORIAL_RECURSIVE(int *FACT, int N)
{
    // Step 1: Base case - If N = 0, set FACT = 1 and return
    if(N == 0)
    {
        *FACT = 1;
        return;
    }
    
    // Step 2: Recursive call
    FACTORIAL_RECURSIVE(FACT, N - 1);
    
    // Step 3: Multiply result by N
    *FACT = N * (*FACT);
    
    // Step 4: Return
    return;
}
