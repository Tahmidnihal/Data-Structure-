#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXSTK 50

int isOperator(char c);
int precedence(char op);
int calculate(int a, int b, char op);
void evaluatePostfix(char *P);

int main()
{
    char postfix[100];
    
    printf("Enter postfix expression (use spaces between elements):\n");
    printf("Example: 5 6 2 + * 12 4 / -\n");
    fgets(postfix, sizeof(postfix), stdin);
    
    printf("\nEvaluating: %s\n", postfix);
    evaluatePostfix(postfix);
    
    return 0;
}

void evaluatePostfix(char *P)
{
    int STACK[MAXSTK];
    int TOP = -1;
    char *token;
    char temp[100];
    
    strcpy(temp, P);
    
    // Add sentinel at end - Step 1
    strcat(temp, " )");
    
    // Step 2: Scan P from left to right
    token = strtok(temp, " \n");
    
    while(token != NULL)
    {
        // Check for sentinel
        if(strcmp(token, ")") == 0)
            break;
        
        // Step 3: If operand is encountered, push onto STACK
        if(isdigit(token[0]) || (token[0] == '-' && strlen(token) > 1))
        {
            int num = atoi(token);
            TOP++;
            STACK[TOP] = num;
            printf("Push: %d, Stack TOP: %d\n", num, STACK[TOP]);
        }
        // Step 4: If operator is encountered
        else if(isOperator(token[0]) && strlen(token) == 1)
        {
            // (a) Pop A and B
            if(TOP < 1)
            {
                printf("Error: Insufficient operands\n");
                return;
            }
            
            int A = STACK[TOP];
            TOP--;
            int B = STACK[TOP];
            TOP--;
            
            // (b) Evaluate B op A
            int result = calculate(B, A, token[0]);
            
            printf("Pop: %d and %d, Compute: %d %c %d = %d\n", A, B, B, token[0], A, result);
            
            // (c) Push result back onto STACK
            TOP++;
            STACK[TOP] = result;
        }
        
        token = strtok(NULL, " \n");
    }
    
    // Step 5: Set VALUE equal to top element
    if(TOP == 0)
    {
        printf("\nFinal VALUE = %d\n", STACK[TOP]);
    }
    else
    {
        printf("Error: Invalid expression\n");
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int calculate(int b, int a, char op)
{
    switch(op)
    {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': 
            if(a == 0)
            {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return b / a;
        case '^':
            {
                int result = 1;
                for(int i = 0; i < a; i++)
                    result *= b;
                return result;
            }
        default: return 0;
    }
}
