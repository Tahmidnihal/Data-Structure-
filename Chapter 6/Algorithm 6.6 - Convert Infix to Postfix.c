#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXSTK 50

int isOperator(char c);
int precedence(char op);
void infixToPostfix(char *Q, char *P);

int main()
{
    char infix[100], postfix[100];
    
    printf("Enter infix expression (no spaces):\n");
    printf("Example: A+(B*C-(D/E^F)*G)*H\n");
    scanf("%s", infix);
    
    printf("\nInfix: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    
    return 0;
}

void infixToPostfix(char *Q, char *P)
{
    char STACK[MAXSTK];
    int TOP = -1;
    int i = 0, j = 0;
    char temp[100];
    
    strcpy(temp, Q);
    
    // Step 1: Push "(" onto STACK and add ")" to end of Q
    TOP++;
    STACK[TOP] = '(';
    strcat(temp, ")");
    
    // Step 2: Scan Q from left to right
    while(i < strlen(temp))
    {
        char ch = temp[i];
        
        // Step 3: If operand, add to P
        if(isalnum(ch))
        {
            P[j++] = ch;
            P[j++] = ' ';  // Add space for readability
        }
        // Step 4: If left parenthesis, push onto STACK
        else if(ch == '(')
        {
            TOP++;
            STACK[TOP] = ch;
        }
        // Step 6: If right parenthesis
        else if(ch == ')')
        {
            // (a) Pop operators until left parenthesis
            while(TOP >= 0 && STACK[TOP] != '(')
            {
                P[j++] = STACK[TOP];
                P[j++] = ' ';
                TOP--;
            }
            // (b) Remove left parenthesis
            if(TOP >= 0)
                TOP--;
        }
        // Step 5: If operator
        else if(isOperator(ch))
        {
            // (a) Pop operators with same or higher precedence
            while(TOP >= 0 && STACK[TOP] != '(' && 
                  precedence(STACK[TOP]) >= precedence(ch))
            {
                P[j++] = STACK[TOP];
                P[j++] = ' ';
                TOP--;
            }
            // (b) Push operator onto STACK
            TOP++;
            STACK[TOP] = ch;
        }
        
        i++;
    }
    
    P[j] = '\0';
    
    // Step 7: Exit
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char op)
{
    switch(op)
    {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
