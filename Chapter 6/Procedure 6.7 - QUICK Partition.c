#include<stdio.h>

void QUICK(int A[], int N, int BEG, int END, int *LOC);

int main()
{
    int A[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int N = 12;
    int LOC;
    
    printf("Original array:\n");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n\n");
    
    // Test QUICK procedure on the array
    QUICK(A, N, 0, N-1, &LOC);
    
    printf("\nArray after partitioning:\n");
    for(int i = 0; i < N; i++)
    {
        if(i == LOC)
            printf("[%d] ", A[i]);
        else
            printf("%d ", A[i]);
    }
    printf("\n");
    printf("Pivot %d is at final position %d\n", A[LOC], LOC);
    
    return 0;
}

void QUICK(int A[], int N, int BEG, int END, int *LOC)
{
    int LEFT, RIGHT, TEMP;
    
    // Step 1: Initialize
    LEFT = BEG;
    RIGHT = END;
    *LOC = BEG;
    
    // Step 2: Scan from right to left
    while(1)
    {
        // Step 2(a): Move RIGHT pointer left
        while(A[*LOC] <= A[RIGHT] && *LOC != RIGHT)
        {
            RIGHT = RIGHT - 1;
        }
        
        // Step 2(b): If LOC = RIGHT, return
        if(*LOC == RIGHT)
            return;
        
        // Step 2(c): If A[LOC] > A[RIGHT]
        if(A[*LOC] > A[RIGHT])
        {
            // (i) Interchange A[LOC] and A[RIGHT]
            TEMP = A[*LOC];
            A[*LOC] = A[RIGHT];
            A[RIGHT] = TEMP;
            
            // (ii) Set LOC = RIGHT
            *LOC = RIGHT;
            
            // (iii) Go to Step 3
            break;
        }
    }
    
    // Step 3: Scan from left to right
    while(1)
    {
        // Step 3(a): Move LEFT pointer right
        while(A[LEFT] <= A[*LOC] && LEFT != *LOC)
        {
            LEFT = LEFT + 1;
        }
        
        // Step 3(b): If LOC = LEFT, return
        if(*LOC == LEFT)
            return;
        
        // Step 3(c): If A[LEFT] > A[LOC]
        if(A[LEFT] > A[*LOC])
        {
            // (i) Interchange A[LEFT] and A[LOC]
            TEMP = A[LEFT];
            A[LEFT] = A[*LOC];
            A[*LOC] = TEMP;
            
            // (ii) Set LOC = LEFT
            *LOC = LEFT;
            
            // (iii) Go to Step 2
            // Step 2: Scan from right to left
            while(1)
            {
                while(A[*LOC] <= A[RIGHT] && *LOC != RIGHT)
                {
                    RIGHT = RIGHT - 1;
                }
                
                if(*LOC == RIGHT)
                    return;
                
                if(A[*LOC] > A[RIGHT])
                {
                    TEMP = A[*LOC];
                    A[*LOC] = A[RIGHT];
                    A[RIGHT] = TEMP;
                    *LOC = RIGHT;
                    break;
                }
            }
        }
    }
}
