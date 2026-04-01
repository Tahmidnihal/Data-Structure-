#include<stdio.h>

#define MAXSTK 50

void TOWER_NONRECURSIVE(int N, char BEG, char AUX, char END);

int moves = 0;

int main()
{
    int N;
    
    printf("Enter number of disks: ");
    scanf("%d", &N);
    
    printf("\nSolution for Tower of Hanoi with %d disks (Non-Recursive):\n", N);
    printf("Move from peg A to peg C using peg B as auxiliary\n\n");
    
    moves = 0;
    TOWER_NONRECURSIVE(N, 'A', 'B', 'C');
    
    printf("\nTotal moves: %d\n", moves);
    
    return 0;
}

void TOWER_NONRECURSIVE(int N, char BEG, char AUX, char END)
{
    // Stacks for parameters
    int STN[MAXSTK];
    char STBEG[MAXSTK], STAUX[MAXSTK], STEND[MAXSTK];
    int STADD[MAXSTK];  // Return addresses
    int TOP = -1;
    int ADD;
    char TEMP;
    
    // Step 0: Set TOP = NULL (or -1 in array implementation)
    TOP = -1;
    
    // Start execution
    while(1)
    {
        // Step 1: If N = 1
        if(N == 1)
        {
            // (a) Write: BEG -> END
            printf("Move %d: %c -> %c\n", ++moves, BEG, END);
            
            // (b) Go to Step 5 (Return)
            goto step5;
        }
        
        // Step 2: Simulate Call TOWER(N-1, BEG, END, AUX) with return to Step 3
        TOP++;
        STN[TOP] = N;
        STBEG[TOP] = BEG;
        STAUX[TOP] = AUX;
        STEND[TOP] = END;
        STADD[TOP] = 3;  // Return address
        
        // Set new parameters
        N = N - 1;
        TEMP = AUX;
        AUX = END;
        END = TEMP;
        
        // Go to Step 1
        continue;
        
        step3:
        // Step 3: Write: BEG -> END
        printf("Move %d: %c -> %c\n", ++moves, BEG, END);
        
        // Step 4: Simulate Call TOWER(N-1, AUX, BEG, END) with return to Step 5
        TOP++;
        STN[TOP] = N;
        STBEG[TOP] = BEG;
        STAUX[TOP] = AUX;
        STEND[TOP] = END;
        STADD[TOP] = 5;  // Return address
        
        // Set new parameters
        N = N - 1;
        TEMP = BEG;
        BEG = AUX;
        AUX = TEMP;
        
        // Go to Step 1
        continue;
        
        step5:
        // Step 5: Return
        if(TOP == -1)
        {
            // Return to main program
            return;
        }
        
        // Pop all stacks and restore values
        N = STN[TOP];
        BEG = STBEG[TOP];
        AUX = STAUX[TOP];
        END = STEND[TOP];
        ADD = STADD[TOP];
        TOP--;
        
        // Go to return address
        if(ADD == 3)
            goto step3;
        else if(ADD == 5)
            goto step5;
    }
}
