#include<stdio.h>

void TOWER(int N, char BEG, char AUX, char END);

int moves = 0;

int main()
{
    int N;
    
    printf("Enter number of disks: ");
    scanf("%d", &N);
    
    printf("\nSolution for Tower of Hanoi with %d disks:\n", N);
    printf("Move from peg A to peg C using peg B as auxiliary\n\n");
    
    moves = 0;
    TOWER(N, 'A', 'B', 'C');
    
    printf("\nTotal moves: %d\n", moves);
    printf("Formula: 2^%d - 1 = %d\n", N, moves);
    
    return 0;
}

void TOWER(int N, char BEG, char AUX, char END)
{
    // Step 1: Base case - If N = 1
    if(N == 1)
    {
        // (a) Write: BEG -> END
        printf("Move %d: %c -> %c\n", ++moves, BEG, END);
        // (b) Return
        return;
    }
    
    // Step 2: Move N-1 disks from BEG to AUX (using END as auxiliary)
    TOWER(N - 1, BEG, END, AUX);
    
    // Step 3: Move largest disk from BEG to END
    printf("Move %d: %c -> %c\n", ++moves, BEG, END);
    
    // Step 4: Move N-1 disks from AUX to END (using BEG as auxiliary)
    TOWER(N - 1, AUX, BEG, END);
    
    // Step 5: Return
    return;
}
