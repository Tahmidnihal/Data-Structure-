#include<stdio.h>

void FIBONACCI(int *FIB, int N);

int main()
{
    int N, FIB;
    
    printf("Enter n to find nth Fibonacci number: ");
    scanf("%d", &N);
    
    if(N < 0)
    {
        printf("Fibonacci not defined for negative numbers\n");
        return 1;
    }
    
    FIBONACCI(&FIB, N);
    
    printf("F(%d) = %d\n", N, FIB);
    
    printf("\nFibonacci sequence up to F(%d):\n", N);
    for(int i = 0; i <= N; i++)
    {
        FIBONACCI(&FIB, i);
        printf("F(%d) = %d\n", i, FIB);
    }
    
    return 0;
}

void FIBONACCI(int *FIB, int N)
{
    int FIBA, FIBB;
    
    // Step 1: Base cases - If N = 0 or N = 1, set FIB = N and return
    if(N == 0 || N == 1)
    {
        *FIB = N;
        return;
    }
    
    // Step 2: Recursive call for (N-2)
    FIBONACCI(&FIBA, N - 2);
    
    // Step 3: Recursive call for (N-1)
    FIBONACCI(&FIBB, N - 1);
    
    // Step 4: FIB = FIBA + FIBB
    *FIB = FIBA + FIBB;
    
    // Step 5: Return
    return;
}
