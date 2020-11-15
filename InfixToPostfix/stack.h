struct Stack
{
    int size;
    int top;
    char * arr;

};

int IsFull(struct Stack* stack)
{
    return (stack->top == (stack->size -1)) ? 1 : 0;
}

int IsEmpty(struct Stack* stack)
{
    return (stack->top == -1) ? 1 : 0;
}


void Push (struct Stack* stack, char data)
{
    if(!IsFull(stack))
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
}

char Pop(struct Stack* stack)
{
    char value = stack->arr[stack->top];
    if(!IsEmpty(stack))
        stack->top--;
    return value;
}

char Peek(struct Stack* stack, int index)
{
    return stack->arr[(index-1)];

}

char PeekTop(struct Stack* stack)
{
    return stack->arr[(stack->top)];

}

void Traverse(struct Stack* stack)
{
    int index = stack->top;
    while(index!=-1)
    {
        printf("%c\n", stack->arr[index]);
        index--;
    }
}
