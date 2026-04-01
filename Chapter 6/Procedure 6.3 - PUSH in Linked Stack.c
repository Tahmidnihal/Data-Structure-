#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

void PUSH_LINKSTACK(struct Node **TOP, struct Node **AVAIL, int ITEM);
void displayStack(struct Node *TOP);

int main()
{
    struct Node *TOP = NULL;
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
    
    printf("Pushing elements onto linked stack:\n");
    PUSH_LINKSTACK(&TOP, &AVAIL, 10);
    PUSH_LINKSTACK(&TOP, &AVAIL, 20);
    PUSH_LINKSTACK(&TOP, &AVAIL, 30);
    
    printf("\nStack contents (TOP to bottom):\n");
    displayStack(TOP);
    
    return 0;
}

void PUSH_LINKSTACK(struct Node **TOP, struct Node **AVAIL, int ITEM)
{
    struct Node *NEW;
    
    // Step 1: Check if there is available space
    if(*AVAIL == NULL)
    {
        printf("OVERFLOW\n");
        return;
    }
    
    // Step 2: Remove first node from AVAIL list
    NEW = *AVAIL;
    *AVAIL = (*AVAIL)->LINK;
    
    // Step 3: Copy ITEM into new node
    NEW->INFO = ITEM;
    
    // Step 4: New node points to old top
    NEW->LINK = *TOP;
    
    // Step 5: TOP now points to new node
    *TOP = NEW;
    
    printf("Pushed: %d\n", ITEM);
    
    // Step 6: Exit
    return;
}

void displayStack(struct Node *TOP)
{
    struct Node *PTR = TOP;
    
    if(PTR == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    
    while(PTR != NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR = PTR->LINK;
    }
}
