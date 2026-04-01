#include<stdio.h>

#define MAXSTK 5

void PUSH(int STACK[], int *TOP, int MAXSTK, int ITEM);

int main()
{
    int STACK[MAXSTK];
    int TOP = -1;
    int ITEM;

    printf("Enter elements to push (enter -999 to stop):\n");
    
    while(1)
    {
        printf("Enter item: ");
        scanf("%d", &ITEM);
        
        if(ITEM == -999)
            break;
            
        PUSH(STACK, &TOP, MAXSTK, ITEM);
    }

    printf("\nStack after PUSH operations:\n");
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
    // Step 1: Check if stack is already filled
    if(*TOP == MAXSTK - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    
    // Step 2: Increase TOP by 1
    *TOP = *TOP + 1;
    
    // Step 3: Insert ITEM at new TOP position
    STACK[*TOP] = ITEM;
    
    // Step 4: Return
    return;
}
