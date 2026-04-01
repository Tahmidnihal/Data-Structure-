#include<stdio.h>

#define MAXSTK 5

void PUSH(int STACK[], int *TOP, int MAXSTK, int ITEM);
void POP(int STACK[], int *TOP, int *ITEM);

int main()
{
    int STACK[MAXSTK];
    int TOP = -1;
    int ITEM;

    // Push some elements first
    PUSH(STACK, &TOP, MAXSTK, 10);
    PUSH(STACK, &TOP, MAXSTK, 20);
    PUSH(STACK, &TOP, MAXSTK, 30);
    PUSH(STACK, &TOP, MAXSTK, 40);

    printf("Stack before POP:\n");
    for(int i = 0; i <= TOP; i++)
    {
        printf("%d ", STACK[i]);
    }
    printf("\n\n");

    // Pop elements
    printf("Popping elements:\n");
    for(int i = 0; i < 2; i++)
    {
        POP(STACK, &TOP, &ITEM);
    }

    printf("\nStack after POP operations:\n");
    if(TOP == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(int i = 0; i <= TOP; i++)
        {
            printf("%d ", STACK[i]);
        }
        printf("\n");
    }

    return 0;
}

void PUSH(int STACK[], int *TOP, int MAXSTK, int ITEM)
{
    if(*TOP == MAXSTK - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    *TOP = *TOP + 1;
    STACK[*TOP] = ITEM;
}

void POP(int STACK[], int *TOP, int *ITEM)
{
    // Step 1: Check if stack has an item to remove
    if(*TOP == -1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    
    // Step 2: Assign TOP element to ITEM
    *ITEM = STACK[*TOP];
    
    // Step 3: Decrease TOP by 1
    *TOP = *TOP - 1;
    
    printf("Popped item: %d\n", *ITEM);
    
    // Step 4: Return
    return;
}
