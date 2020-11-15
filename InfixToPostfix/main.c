#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

struct Stack* stack;


int Precedence(char ch)
{
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int IsOperator(char ch)
{
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char* InfixToPostFix(char* infix)
{
    stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = 100;
    stack->top = -1;
    stack->arr = (char*) malloc(stack->size * sizeof(char));

    char* postfix = (char*) malloc(strlen(infix)*sizeof(char));
    int i=0, j=0;

    while(infix[i] != '\0')
    {
        if(!IsOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if(Precedence(infix[i]) > Precedence(PeekTop(stack)))
            {
                Push(stack, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = Pop(stack);
                j++;
            }
        }
    }
    while(!IsEmpty(stack))
    {
        postfix[j] = Pop(stack);
        j++;
    }
    return postfix;
}
int main()
{
    char* infix = "a*b+c*d";
    printf("Infix : %s\n", infix);
    printf("Prefix : %s", InfixToPostFix(infix));
    return 0;
}
