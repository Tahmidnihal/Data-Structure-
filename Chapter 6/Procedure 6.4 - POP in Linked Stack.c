#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

void PUSH_LINKSTACK(struct Node **TOP, struct Node **AVAIL, int ITEM);
void POP_LINKSTACK(struct Node **TOP, struct Node **AVAIL, int *ITEM);
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
    
    // Push some elements
    printf("Pushing elements onto linked stack:\n");
    PUSH_LINKSTACK(&TOP, &AVAIL, 10);
    PUSH_LINKSTACK(&TOP, &AVAIL, 20);
    PUSH_LINKSTACK(&TOP, &AVAIL, 30);
    
    printf("\nStack before POP:\n");
    displayStack(TOP);
    
    // Pop elements
    int ITEM;
    printf("\nPopping elements:\n");
    POP_LINKSTACK(&TOP, &AVAIL, &ITEM);
    POP_LINKSTACK(&TOP, &AVAIL, &ITEM);
    
    printf("\nStack after POP operations:\n");
    displayStack(TOP);
    
    return 0;
}

void PUSH_LINKSTACK(struct Node **TOP, struct Node **AVAIL, int ITEM)
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
    NEW->LINK = *TOP;
    *TOP = NEW;
    
    printf("Pushed: %d\n", ITEM);
}

void POP_LINKSTACK(struct Node **TOP, struct Node **AVAIL, int *ITEM)
{
    struct Node *TEMP;
    
    // Step 1: Check if stack has an item
    if(*TOP == NULL)
    {
        printf("UNDERFLOW\n");
        return;
    }
    
    // Step 2: Copy top element to ITEM
    *ITEM = (*TOP)->INFO;
    
    // Step 3: Move TOP to next node
    TEMP = *TOP;
    *TOP = (*TOP)->LINK;
    
    // Step 4: Return deleted node to AVAIL list
    TEMP->LINK = *AVAIL;
    *AVAIL = TEMP;
    
    printf("Popped: %d\n", *ITEM);
    
    // Step 5: Exit
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
