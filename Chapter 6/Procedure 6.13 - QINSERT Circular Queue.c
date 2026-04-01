#include<stdio.h>

#define N 5

void QINSERT(int QUEUE[], int N, int *FRONT, int *REAR, int ITEM);

int main()
{
    int QUEUE[N];
    int FRONT = -1;
    int REAR = -1;
    int ITEM;
    
    printf("Circular Queue Implementation (Array)\n");
    printf("Queue size: %d\n\n", N);
    
    // Insert elements
    printf("Inserting elements:\n");
    QINSERT(QUEUE, N, &FRONT, &REAR, 10);
    QINSERT(QUEUE, N, &FRONT, &REAR, 20);
    QINSERT(QUEUE, N, &FRONT, &REAR, 30);
    QINSERT(QUEUE, N, &FRONT, &REAR, 40);
    
    printf("\nQueue contents:\n");
    if(FRONT == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = FRONT;
        printf("FRONT -> ");
        while(1)
        {
            printf("%d ", QUEUE[i]);
            if(i == REAR)
                break;
            i = (i == N - 1) ? 0 : i + 1;
        }
        printf("<- REAR\n");
    }
    
    return 0;
}

void QINSERT(int QUEUE[], int N, int *FRONT, int *REAR, int ITEM)
{
    // Step 1: Check if queue is already filled
    if((*FRONT == 0 && *REAR == N - 1) || (*FRONT == *REAR + 1))
    {
        printf("OVERFLOW\n");
        return;
    }
    
    // Step 2: Find new value of REAR
    if(*FRONT == -1)  // Queue initially empty
    {
        *FRONT = 0;
        *REAR = 0;
    }
    else if(*REAR == N - 1)  // Wrap around
    {
        *REAR = 0;
    }
    else
    {
        *REAR = *REAR + 1;
    }
    
    // Step 3: Insert new element
    QUEUE[*REAR] = ITEM;
    printf("Inserted: %d at position %d\n", ITEM, *REAR);
    
    // Step 4: Return
    return;
}
