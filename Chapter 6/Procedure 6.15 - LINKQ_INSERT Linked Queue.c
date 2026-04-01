#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

void LINKQ_INSERT(struct Node **FRONT, struct Node **REAR, struct Node **AVAIL, int ITEM);
void displayQueue(struct Node *FRONT);

int main()
{
    struct Node *FRONT = NULL;
    struct Node *REAR = NULL;
    struct Node *AVAIL;
    
    // Initialize AVAIL list with some free nodes
    struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node4 = (struct Node*)malloc(sizeof(struct Node));
    
    node1->LINK = node2;
    node2->LINK = node3;
    node3->LINK = node4;
    node4->LINK = NULL;
    
    AVAIL = node1;
    
    printf("Linked Queue Implementation - INSERT\n\n");
    
    // Insert elements
    printf("Inserting elements:\n");
    LINKQ_INSERT(&FRONT, &REAR, &AVAIL, 10);
    LINKQ_INSERT(&FRONT, &REAR, &AVAIL, 20);
    LINKQ_INSERT(&FRONT, &REAR, &AVAIL, 30);
    
    printf("\nQueue contents (FRONT to REAR):\n");
    displayQueue(FRONT);
    
    return 0;
}

void LINKQ_INSERT(struct Node **FRONT, struct Node **REAR, struct Node **AVAIL, int ITEM)
{
    struct Node *NEW;
    
    // Step 1: Check if there is available space
    if(*AVAIL == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    
    // Step 2: Get new node from AVAIL list
    NEW = *AVAIL;
    *AVAIL = (*AVAIL)->LINK;
    
    // Step 3: Copy data into new node
    NEW->INFO = ITEM;
    NEW->LINK = NULL;
    
    // Step 4: Add to queue
    if(*FRONT == NULL)  // Queue was empty
    {
        *FRONT = NEW;
        *REAR = NEW;
    }
    else
    {
        (*REAR)->LINK = NEW;
        *REAR = NEW;
    }
    
    printf("Inserted: %d\n", ITEM);
    
    // Step 5: Exit
    return;
}

void displayQueue(struct Node *FRONT)
{
    struct Node *PTR = FRONT;
    
    if(PTR == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("FRONT -> ");
    while(PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }
    printf("<- REAR\n");
}
