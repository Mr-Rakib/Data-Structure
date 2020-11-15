#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int * arr;

};

int IsFull(struct Stack* stack)
{
    return (stack->top == (stack->size -1)) ? 1 : 0;
}

int IsEmpty(struct Stack* stack)
{
    return (stack->top == -1) ? 1 : 0;
}


void Push (struct Stack* stack, int data)
{
    if(!IsFull(stack))
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
}

int Pop(struct Stack* stack)
{
    int value = stack->arr[stack->top];
    if(!IsEmpty(stack))
        stack->top--;
    return value;
}

int Peek(struct Stack* stack, int index)
{
    return stack->arr[(index-1)];

}

int PeekTop(struct Stack* stack)
{
    return stack->arr[(stack->top)];

}

void Traverse(struct Stack* stack)
{
    int index = stack->top;
    while(index!=-1)
    {
        printf("%d\n", stack->arr[index]);
        index--;
    }
}


int main()
{
    struct Stack* stack = (struct Stack*) malloc (sizeof(struct Stack));

    stack->size = 100;
    stack->top = -1;
    stack->arr = (int *) malloc(stack->size * sizeof(int));

    Push(stack, 20);
    Push(stack, 10);
    Push(stack, 90);
    Push(stack, 2);
    Push(stack, 21);
    Push(stack, 12);
    Push(stack, 120);
    Traverse(stack);
    printf("After --\n");
    printf("Peek : %d\n", PeekTop(stack));
    Traverse(stack);
    return 0;
}
