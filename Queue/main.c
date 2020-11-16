#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int first;
    int last;
    int* arr;
};

struct Queue* queue;

int IsEmpty()
{
    return (queue->first == queue->last)? 1 : 0;
}
int IsFull()
{
    return (queue->last  == queue->size-1)? 1 : 0;
}

void Enqueue (int data)
{

    if(!IsFull())
    {
        queue->arr[++queue->last] = data;
    }
    else
    {
        printf("Queue is full\n");
    }
}

int Dequeue ()
{
    int value =-1;
    if(!IsEmpty())
    {
        queue->first++;
        value = queue->arr[queue->first];
    }
    else
    {
        printf("Queue is empty\n");
    }
    return value;
}

void Traverse()
{
    printf("\nQueue: ");
    int index = queue->first;
    while(index != queue->last)
    {
        printf("%d ", queue->arr[++index]);
    }
}

void InitalizeQueue(int size)
{
    queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->size = size;
    queue->first = -1;
    queue->last = -1;
    queue->arr = (int*) malloc(queue->size*sizeof(int));
}

int main()
{
    InitalizeQueue(100);
    while(1)
    {
        int input, data;
        printf("\n1. Enqueue\n2. Dequeue\n3. Get All\nSelect any:");
        scanf("%d", &input);

        switch(input)
        {
        case 1:
            printf("Value to insert: ");
            scanf("%d", &data);
            Enqueue(data);
            break;
        case 2:
            printf("%d is dequeued\n",Dequeue());
            getch();
            break;
        case 3:
            Traverse();
            getch();
            break;
        default:
            printf("Invalid Input !\n");
            break;
        }
        system("cls");
    }
    return 0;
}
