#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char INFO[20];
    int PRN;  // Priority Number
    struct Node *LINK;
};

void deleteFromPriorityQueue(struct Node **START);
void displayQueue(struct Node *START);

int main()
{
    struct Node *START;
    
    // Create priority queue with different priorities
    struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node5 = (struct Node*)malloc(sizeof(struct Node));
    
    sprintf(node1->INFO, "AAA");
    node1->PRN = 1;
    node1->LINK = node2;
    
    sprintf(node2->INFO, "BBB");
    node2->PRN = 2;
    node2->LINK = node3;
    
    sprintf(node3->INFO, "CCC");
    node3->PRN = 2;
    node3->LINK = node4;
    
    sprintf(node4->INFO, "DDD");
    node4->PRN = 4;
    node4->LINK = node5;
    
    sprintf(node5->INFO, "EEE");
    node5->PRN = 5;
    node5->LINK = NULL;
    
    START = node1;
    
    printf("Priority Queue Implementation (Linked List)\n");
    printf("Lower priority number = Higher priority\n\n");
    
    printf("Initial Queue:\n");
    displayQueue(START);
    
    printf("\nDeleting from priority queue:\n");
    deleteFromPriorityQueue(&START);
    deleteFromPriorityQueue(&START);
    
    printf("\nQueue after deletions:\n");
    displayQueue(START);
    
    return 0;
}

void deleteFromPriorityQueue(struct Node **START)
{
    struct Node *TEMP;
    char ITEM[20];
    
    // Step 1: Save first node's data
    if(*START == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    
    sprintf(ITEM, "%s", (*START)->INFO);
    
    // Step 2: Delete first node from list
    TEMP = *START;
    *START = (*START)->LINK;
    
    // Step 3: Process ITEM
    printf("Deleted and Processing: %s (Priority: %d)\n", ITEM, TEMP->PRN);
    
    free(TEMP);
    
    // Step 4: Exit
    return;
}

void displayQueue(struct Node *START)
{
    struct Node *PTR = START;
    
    if(PTR == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("START -> ");
    while(PTR != NULL)
    {
        printf("[%s, PRN:%d] -> ", PTR->INFO, PTR->PRN);
        PTR = PTR->LINK;
    }
    printf("NULL\n");
}
