#include<stdio.h>

#define N 5

void QINSERT(int QUEUE[], int N, int *FRONT, int *REAR, int ITEM);
void QDELETE(int QUEUE[], int N, int *FRONT, int *REAR, int *ITEM);

int main()
{
    int QUEUE[N];
    int FRONT = -1;
    int REAR = -1;
    int ITEM;
    
    printf("Circular Queue Implementation - INSERT and DELETE\n");
    printf("Queue size: %d\n\n", N);
    
    // Insert elements
    printf("Inserting elements:\n");
    QINSERT(QUEUE, N, &FRONT, &REAR, 10);
    QINSERT(QUEUE, N, &FRONT, &REAR, 20);
    QINSERT(QUEUE, N, &FRONT, &REAR, 30);
    QINSERT(QUEUE, N, &FRONT, &REAR, 40);
    
    printf("\nDeleting elements:\n");
    QDELETE(QUEUE, N, &FRONT, &REAR, &ITEM);
    QDELETE(QUEUE, N, &FRONT, &REAR, &ITEM);
    
    printf("\nInserting more elements:\n");
    QINSERT(QUEUE, N, &FRONT, &REAR, 50);
    QINSERT(QUEUE, N, &FRONT, &REAR, 60);
    
    printf("\nFinal Queue contents:\n");
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
    if((*FRONT == 0 && *REAR == N - 1) || (*FRONT == *REAR + 1))
    {
        printf("OVERFLOW\n");
        return;
    }
    
    if(*FRONT == -1)
    {
        *FRONT = 0;
        *REAR = 0;
    }
    else if(*REAR == N - 1)
    {
        *REAR = 0;
    }
    else
    {
        *REAR = *REAR + 1;
    }
    
    QUEUE[*REAR] = ITEM;
    printf("Inserted: %d at position %d\n", ITEM, *REAR);
}

void QDELETE(int QUEUE[], int N, int *FRONT, int *REAR, int *ITEM)
{
    // Step 1: Check if queue is already empty
    if(*FRONT == -1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    
    // Step 2: Assign FRONT element to ITEM
    *ITEM = QUEUE[*FRONT];
    
    // Step 3: Find new value of FRONT
    if(*FRONT == *REAR)  // Queue had only one element
    {
        *FRONT = -1;
        *REAR = -1;
    }
    else if(*FRONT == N - 1)  // Wrap around
    {
        *FRONT = 0;
    }
    else
    {
        *FRONT = *FRONT + 1;
    }
    
    printf("Deleted: %d\n", *ITEM);
    
    // Step 4: Return
    return;
}
