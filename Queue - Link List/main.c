#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front;
struct Node* rare;

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int IsFull(struct Node* node)
{
    return (node == NULL) ? 1: 0;
}

int IsEmpty()
{
    return (front == NULL) ? 1: 0;
}

void Enqueue(int data)
{
    struct Node* node =  newNode(data);
    if(!IsFull(node))
    {
        if(front == NULL)
        {
            front = node;
            rare = node;

            front->next = NULL;
            rare->next = NULL;
        }
        else
        {
            rare->next = node;
            rare = node;
            rare->next = NULL;
        }
    }
    else
    {
        printf("Overflow ...!\n");
    }
}

void Dequeue ()
{
    if(!IsEmpty())
    {
        struct Node* ptr = front;
        front= front->next;
        free(ptr);
    }
    else
    {
        printf("Underflow..!\n");
    }
}

void Traverse()
{
    struct Node* ptr = front;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int input;
    int data ;
    while(input != 4)
    {
        printf("\n*************************Main Menu*****************************\n");
        printf("\n=================================================================\n");
        printf("\n1.Insert \n2.Delete\n3.Display the queue\n4.Exit\n");
        printf("\nSelect your input ?");
        scanf("%d",& input);
        switch(input)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &data);
            Enqueue(data);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Traverse();
            getch();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter the valid input??\n");
        }
        system("cls");
    }
    return 0;
}
