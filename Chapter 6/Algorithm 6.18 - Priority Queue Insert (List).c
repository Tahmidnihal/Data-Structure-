#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char INFO[20];
    int PRN;
    struct Node *LINK;
};

void insertIntoPriorityQueue(struct Node **START, char ITEM[], int priority);
void displayQueue(struct Node *START);

int main()
{
    struct Node *START = NULL;
    
    printf("Priority Queue Implementation - INSERT (Linked List)\n");
    printf("Lower priority number = Higher priority\n\n");
    
    // Insert elements with different priorities
    printf("Inserting elements:\n");
    insertIntoPriorityQueue(&START, "AAA", 1);
    insertIntoPriorityQueue(&START, "BBB", 2);
    insertIntoPriorityQueue(&START, "CCC", 2);
    insertIntoPriorityQueue(&START, "DDD", 4);
    insertIntoPriorityQueue(&START, "EEE", 5);
    
    printf("\nFinal Priority Queue:\n");
    displayQueue(START);
    
    printf("\nInserting new element with priority 3:\n");
    insertIntoPriorityQueue(&START, "XXX", 3);
    
    printf("\nQueue after insertion:\n");
    displayQueue(START);
    
    return 0;
}

void insertIntoPriorityQueue(struct Node **START, char ITEM[], int priority)
{
    struct Node *NEW = (struct Node*)malloc(sizeof(struct Node));
    struct Node *PTR, *SAVE;
    
    strcpy(NEW->INFO, ITEM);
    NEW->PRN = priority;
    
    // Step 1: Traverse list to find node X whose priority exceeds new item's priority
    if(*START == NULL || (*START)->PRN > priority)
    {
        // Insert at beginning
        NEW->LINK = *START;
        *START = NEW;
        printf("Inserted %s (Priority: %d) at beginning\n", ITEM, priority);
        return;
    }
    
    PTR = *START;
    SAVE = NULL;
    
    // Step 2: Find location to insert
    while(PTR != NULL && PTR->PRN <= priority)
    {
        SAVE = PTR;
        PTR = PTR->LINK;
    }
    
    // Insert ITEM in front of node X (or at end if no such node)
    if(PTR == NULL)
    {
        // Insert at end
        SAVE->LINK = NEW;
        NEW->LINK = NULL;
        printf("Inserted %s (Priority: %d) at end\n", ITEM, priority);
    }
    else
    {
        // Insert in middle
        SAVE->LINK = NEW;
        NEW->LINK = PTR;
        printf("Inserted %s (Priority: %d) in middle\n", ITEM, priority);
    }
    
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
