#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
//O(n)
void ListTraverse(struct Node* head )
{

    while(head != NULL)
    {
        printf("%d ", head->data);
        head= head->next;
    }
}
//O(1)
struct Node* InsertFirst(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*) malloc (sizeof(struct Node));
    ptr->data = data;
    ptr->prev = head->prev;
    ptr->next = head;
    head->prev = ptr;
    return ptr;
};
//O(1)
struct Node* InsertLast(struct Node* head, int data)
{
    struct Node* last = head;
    struct Node* ptr = (struct Node*) malloc (sizeof(struct Node));
    ptr->data = data;

    while(last->next != NULL)
    {
        last = last->next;
    }
    ptr->next = last->next;
    ptr->prev = last;
    last->next= ptr;

    return head;
};
//O(1)
struct Node* DeleteFirst(struct Node* head)
{
    struct Node* ptr = head;

    head = head->next;
    head->prev = NULL;

    free(ptr);

    return head;
};

//O(1)
struct Node* DeleteLast(struct Node* head)
{
    struct Node* ptr = head;

    while(ptr-> next !=NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = ptr->next;
    free(ptr);

    return head;
};

//O(n)
struct Node* DeleteByValue(struct Node* head, int value)
{

    struct Node* ptr = head;

    while(ptr->data != value && ptr-> next != NULL)
    {
        ptr = ptr->next;
    }

    if(ptr->data == value)
    {
        if(ptr == head)
        {
            head = DeleteFirst(head);
        }
        else
        {
            ptr->prev->next = ptr->next;
        }
        free(ptr);
    }
    return head;
};


int main()
{

    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* four;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    four = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev= head;
    second->next= third;

    third->data = 15;
    third->prev = second;
    third->next = four;


    four->data = 25;
    four->prev = third;
    four->next = NULL;

    ListTraverse(head);
    printf("\nAfter Insertion : \n");
    head = DeleteByValue(head, 30);
    ListTraverse(head);
    return 0;
}
