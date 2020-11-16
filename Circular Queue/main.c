#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int first;
    int last;
    int* arr;
};

struct CircularQueue* queue;

int IsEmpty()
{
    return (queue->first == queue->last)? 1 : 0;
}
int IsFull()
{
    return ((queue->last+1)%queue->size == queue->first)? 1 : 0;
}

void Enqueue (int data)
{
    if(!IsFull())
    {
        queue->last = (queue->last+1)%queue->size;
        queue->arr[queue->last] = data;
    }
    else
    {
        printf("CircularQueue is full\n");
    }
}

int Dequeue ()
{
    int value =-1;
    if(!IsEmpty())
    {
        queue->first = (queue->first+1)%queue->size;
        value = queue->arr[queue->first];
    }
    else
    {
        printf("CircularQueue is empty\n");
    }
    return value;
}

void Traverse()
{
    printf("\nCercularQueue: ");
    int index = queue->first;
    while(index != queue->last)
    {
        printf("%d ", queue->arr[++index]);
    }
}

void InitalizeQueue(int size)
{
    queue = (struct CircularQueue*) malloc(sizeof(struct CircularQueue));
    queue->size = size;
    queue->first =0;
    queue->last = 0;
    queue->arr = (int*) malloc(queue->size*sizeof(int));
}

int main()
{
    InitalizeQueue(3);
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
            Traverse();
            break;
        case 2:
            printf("%d is dequeued\n",Dequeue());
            Traverse();
            break;
        case 3:
            Traverse();
            break;
        default:
            printf("Invalid Input !\n");
            break;
        }
        getch();
        system("cls");
    }
    return 0;
}
