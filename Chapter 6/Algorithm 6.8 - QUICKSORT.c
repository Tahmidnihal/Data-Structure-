#include<stdio.h>

#define MAXSTK 50

void QUICK(int A[], int N, int BEG, int END, int *LOC);
void QUICKSORT(int A[], int N);
void displayArray(int A[], int N);

int main()
{
    int A[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int N = 12;
    
    printf("Original array:\n");
    displayArray(A, N);
    
    QUICKSORT(A, N);
    
    printf("\nSorted array:\n");
    displayArray(A, N);
    
    return 0;
}

void QUICKSORT(int A[], int N)
{
    int LOWER[MAXSTK], UPPER[MAXSTK];
    int TOP = -1;
    int BEG, END, LOC;
    
    // Step 1: Initialize
    TOP = -1;
    
    // Step 2: Push initial boundaries if N > 1
    if(N > 1)
    {
        TOP = TOP + 1;
        LOWER[TOP] = 0;
        UPPER[TOP] = N - 1;
    }
    
    // Step 3: Repeat while TOP != NULL
    while(TOP != -1)
    {
        // Step 4: Pop sublist boundaries
        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP = TOP - 1;
        
        // Step 5: Call QUICK to partition
        QUICK(A, N, BEG, END, &LOC);
        
        printf("\nPartitioned: ");
        displayArray(A, N);
        printf("Pivot at position %d\n", LOC);
        
        // Step 6: Push left sublist if it has 2+ elements
        if(BEG < LOC - 1)
        {
            TOP = TOP + 1;
            LOWER[TOP] = BEG;
            UPPER[TOP] = LOC - 1;
        }
        
        // Step 7: Push right sublist if it has 2+ elements
        if(LOC + 1 < END)
        {
            TOP = TOP + 1;
            LOWER[TOP] = LOC + 1;
            UPPER[TOP] = END;
        }
    }
    
    // Step 8: Exit
}

void QUICK(int A[], int N, int BEG, int END, int *LOC)
{
    int LEFT, RIGHT, TEMP;
    
    LEFT = BEG;
    RIGHT = END;
    *LOC = BEG;
    
    while(1)
    {
        while(A[*LOC] <= A[RIGHT] && *LOC != RIGHT)
            RIGHT = RIGHT - 1;
        
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
    
    while(1)
    {
        while(A[LEFT] <= A[*LOC] && LEFT != *LOC)
            LEFT = LEFT + 1;
        
        if(*LOC == LEFT)
            return;
        
        if(A[LEFT] > A[*LOC])
        {
            TEMP = A[LEFT];
            A[LEFT] = A[*LOC];
            A[*LOC] = TEMP;
            *LOC = LEFT;
            
            while(1)
            {
                while(A[*LOC] <= A[RIGHT] && *LOC != RIGHT)
                    RIGHT = RIGHT - 1;
                
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

void displayArray(int A[], int N)
{
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
