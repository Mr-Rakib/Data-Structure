#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack* next;
};

//Declare Globally
struct Stack* top_node;

//O(1)
int IsEmpty(struct Stack* top)
{
    return (top == NULL) ? 1 : 0;
}

//O(1)
int IsFull()
{
    struct Stack* ptr = (struct Stack*) malloc(sizeof(struct Stack));
    return (ptr == NULL) ? 1 : 0;
}

//O(1)
struct Stack* Push(struct Stack* top, int data)
{
    if(!IsFull(top))
    {
        struct Stack* ptr = (struct Stack*) malloc(sizeof(struct Stack));
        ptr->data = data;
        ptr->next = top;

        return ptr;
    }
    else
    {
        return top;
    }
}

//O(1)
int Pop(struct Stack* top)
{
    if(!IsEmpty(top))
    {
        struct Stack* ptr = top;
        top = top->next;

        int data = ptr->data;
        free(ptr);
        return data;
    }
}

//O(n)
int PeekAtIndex(struct Stack* top, int index)
{
    if(!IsEmpty(top))
    {
        int i = 0;
        while(top->next != NULL && i<index){
            top= top->next;
            i++;
        }
        if(index == i){
            return top->data;
        }
    }
    else
    {
        printf("Nothing to Peek");
    }
}

//O(1)
int Peek(struct Stack* top)
{
    if(!IsEmpty(top))
        return top->data;
    else
    {
        printf("Nothing to Peek");
    }
}

//O(n)
void Traverse(struct Stack* top)
{
    while(top!=NULL)
    {
        printf("%d\n", top->data);
        top= top->next;
    }
}

int main()
{
    top_node = NULL;

    top_node = Push(top_node, 15);
    top_node = Push(top_node, 12);
    top_node = Push(top_node, 155);
    top_node = Push(top_node, 157);
    top_node = Push(top_node, 13);

    Traverse(top_node);
    Pop(top_node);

    printf("\n-------AFTER--------\n");
    Traverse(top_node);

    printf("\n-------AFTER--------\n%d", Peek(top_node));
    printf("\n-------AFTER--------\n%d", PeekAtIndex(top_node, 2));
    return 0;
}
