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
void deleteFromPriorityQueue(struct PriorityQueue *pq);
void displayPriorityQueue(struct PriorityQueue *pq);

int main()
{
    struct PriorityQueue pq;
    initializePriorityQueue(&pq);
    
    printf("Priority Queue Implementation (Array - Multiple Queues)\n");
    printf("Lower priority number = Higher priority\n\n");
    
    // Initialize some data
    strcpy(pq.QUEUE[0][0], "AAA");
    pq.FRONT[0] = 0;
    pq.REAR[0] = 0;
    
    strcpy(pq.QUEUE[1][0], "BBB");
    strcpy(pq.QUEUE[1][1], "CCC");
    strcpy(pq.QUEUE[1][2], "XXX");
    pq.FRONT[1] = 0;
    pq.REAR[1] = 2;
    
    strcpy(pq.QUEUE[3][0], "DDD");
    strcpy(pq.QUEUE[3][1], "EEE");
    strcpy(pq.QUEUE[3][2], "FFF");
    pq.FRONT[3] = 0;
    pq.REAR[3] = 2;
    
    strcpy(pq.QUEUE[4][0], "GGG");
    pq.FRONT[4] = 0;
    pq.REAR[4] = 0;
    
    printf("Initial Priority Queue:\n");
    displayPriorityQueue(&pq);
    
    printf("\nDeleting elements:\n");
    deleteFromPriorityQueue(&pq);
    deleteFromPriorityQueue(&pq);
    deleteFromPriorityQueue(&pq);
    
    printf("\nPriority Queue after deletions:\n");
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

void deleteFromPriorityQueue(struct PriorityQueue *pq)
{
    char ITEM[20];
    int K;
    
    // Step 1: Find smallest K such that FRONT[K] != NULL (not -1)
    K = -1;
    for(int i = 0; i < MAX_PRIORITY; i++)
    {
        if(pq->FRONT[i] != -1)
        {
            K = i;
            break;
        }
    }
    
    if(K == -1)
    {
        printf("All queues are empty\n");
        return;
    }
    
    // Step 2: Delete and process front element in row K
    strcpy(ITEM, pq->QUEUE[K][pq->FRONT[K]]);
    
    if(pq->FRONT[K] == pq->REAR[K])
    {
        // Queue becomes empty
        pq->FRONT[K] = -1;
        pq->REAR[K] = -1;
    }
    else
    {
        pq->FRONT[K]++;
    }
    
    printf("Deleted and Processing: %s (Priority: %d)\n", ITEM, K + 1);
    
    // Step 3: Exit
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
