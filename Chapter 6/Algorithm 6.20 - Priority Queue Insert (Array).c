#include<stdio.h>
#include<string.h>

#define MAX_PRIORITY 5
#define QUEUE_SIZE 5

struct PriorityQueue
{
    char QUEUE[MAX_PRIORITY][QUEUE_SIZE][20];
    int FRONT[MAX_PRIORITY];
    int REAR[MAX_PRIORITY];
};

void initializePriorityQueue(struct PriorityQueue *pq);
void insertIntoPriorityQueue(struct PriorityQueue *pq, char ITEM[], int M);
void displayPriorityQueue(struct PriorityQueue *pq);

int main()
{
    struct PriorityQueue pq;
    initializePriorityQueue(&pq);
    
    printf("Priority Queue Implementation - INSERT (Array)\n");
    printf("Lower priority number = Higher priority\n\n");
    
    // Insert elements with different priorities
    printf("Inserting elements:\n");
    insertIntoPriorityQueue(&pq, "AAA", 1);
    insertIntoPriorityQueue(&pq, "BBB", 2);
    insertIntoPriorityQueue(&pq, "CCC", 2);
    insertIntoPriorityQueue(&pq, "DDD", 4);
    insertIntoPriorityQueue(&pq, "EEE", 4);
    insertIntoPriorityQueue(&pq, "FFF", 4);
    insertIntoPriorityQueue(&pq, "GGG", 5);
    
    printf("\nFinal Priority Queue:\n");
    displayPriorityQueue(&pq);
    
    printf("\nInserting more elements:\n");
    insertIntoPriorityQueue(&pq, "XXX", 2);
    insertIntoPriorityQueue(&pq, "YYY", 3);
    
    printf("\nPriority Queue after insertions:\n");
    displayPriorityQueue(&pq);
    
    return 0;
}

void initializePriorityQueue(struct PriorityQueue *pq)
{
    for(int i = 0; i < MAX_PRIORITY; i++)
    {
        pq->FRONT[i] = -1;
        pq->REAR[i] = -1;
    }
}

void insertIntoPriorityQueue(struct PriorityQueue *pq, char ITEM[], int M)
{
    // M is the priority number (1 to MAX_PRIORITY)
    int index = M - 1;  // Convert to 0-based index
    
    if(index < 0 || index >= MAX_PRIORITY)
    {
        printf("Invalid priority: %d\n", M);
        return;
    }
    
    // Step 1: Insert ITEM at rear of row M
    if(pq->FRONT[index] == -1)
    {
        // Queue was empty
        pq->FRONT[index] = 0;
        pq->REAR[index] = 0;
        strcpy(pq->QUEUE[index][0], ITEM);
    }
    else
    {
        // Check if queue is full
        if(pq->REAR[index] >= QUEUE_SIZE - 1)
        {
            printf("OVERFLOW in priority %d queue\n", M);
            return;
        }
        
        pq->REAR[index]++;
        strcpy(pq->QUEUE[index][pq->REAR[index]], ITEM);
    }
    
    printf("Inserted %s at priority %d\n", ITEM, M);
    
    // Step 2: Exit
    return;
}

void displayPriorityQueue(struct PriorityQueue *pq)
{
    for(int i = 0; i < MAX_PRIORITY; i++)
    {
        printf("Priority %d: ", i + 1);
        if(pq->FRONT[i] == -1)
        {
            printf("[Empty]\n");
        }
        else
        {
            printf("[");
            for(int j = pq->FRONT[i]; j <= pq->REAR[i]; j++)
            {
                printf("%s", pq->QUEUE[i][j]);
                if(j < pq->REAR[i])
                    printf(", ");
            }
            printf("]\n");
        }
    }
}
