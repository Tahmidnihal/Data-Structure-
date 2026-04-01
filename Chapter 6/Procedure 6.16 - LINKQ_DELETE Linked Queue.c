#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

void LINKQ_INSERT(struct Node **FRONT, struct Node **REAR, struct Node **AVAIL, int ITEM);
void LINKQ_DELETE(struct Node **FRONT, struct Node **REAR, struct Node **AVAIL, int *ITEM);
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
    
    printf("Linked Queue Implementation - INSERT and DELETE\n\n");
    
    // Insert elements
    printf("Inserting elements:\n");
    LINKQ_INSERT(&FRONT, &REAR, &AVAIL, 10);
    LINKQ_INSERT(&FRONT, &REAR, &AVAIL, 20);
    LINKQ_INSERT(&FRONT, &REAR, &AVAIL, 30);
    
    printf("\nQueue before deletion:\n");
    displayQueue(FRONT);
    
    // Delete elements
    int ITEM;
    printf("\nDeleting elements:\n");
    LINKQ_DELETE(&FRONT, &REAR, &AVAIL, &ITEM);
    LINKQ_DELETE(&FRONT, &REAR, &AVAIL, &ITEM);
    
    printf("\nQueue after deletion:\n");
    displayQueue(FRONT);
    
    return 0;
}

void LINKQ_INSERT(struct Node **FRONT, struct Node **REAR, struct Node **AVAIL, int ITEM)
{
    struct Node *NEW;
    
    if(*AVAIL == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    
    NEW = *AVAIL;
    *AVAIL = (*AVAIL)->LINK;
    NEW->INFO = ITEM;
    NEW->LINK = NULL;
    
    if(*FRONT == NULL)
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
}

void LINKQ_DELETE(struct Node **FRONT, struct Node **REAR, struct Node **AVAIL, int *ITEM)
{
    struct Node *TEMP;
    
    // Step 1: Check if queue is empty
    if(*FRONT == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    
    // Step 2: Save FRONT pointer
    TEMP = *FRONT;
    
    // Step 3: Copy data from front node
    *ITEM = TEMP->INFO;
    
    // Step 4: Move FRONT to next node
    *FRONT = (*FRONT)->LINK;
    
    // If queue becomes empty, update REAR
    if(*FRONT == NULL)
    {
        *REAR = NULL;
    }
    
    // Step 5: Return deleted node to AVAIL list
    TEMP->LINK = *AVAIL;
    *AVAIL = TEMP;
    
    printf("Deleted: %d\n", *ITEM);
    
    // Step 6: Exit
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
