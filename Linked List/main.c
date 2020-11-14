#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

//O(1)
struct Node* InsertAtBeginning(struct Node* head, int data )
{

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = head;
    return newNode;
}

//O(n)
struct Node* InsertInBetween(struct Node* head, int data, int index )
{
    struct Node* root_node = head;
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;

    int list_index = 0;
    while(list_index !=index-1)
    {
        if(root_node == NULL)
        {
            root_node=NULL;
            break;
        }
        root_node = root_node->next;
        list_index++;
    }
    if(root_node!=NULL)
    {
        newNode->next = root_node->next;
        root_node->next = newNode;

    }
    return head;

}

//O(n)
struct Node* InsertAtEnd(struct Node* head, int data)
{
    struct Node* root_node = head;
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;

    while(root_node->next != NULL)
    {
        root_node= root_node->next;
    }

    root_node->next = newNode;
    newNode->next = NULL;

    return head;
}

//O(1)
void InsertAfter(struct Node* previousNode, int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = previousNode->next;
    previousNode->next = newNode;
}

//Delete From First/Head/Root
//O(1)
struct Node* DeleteFirst(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//O(n)
struct Node* DeleteAtIndex(struct Node* head, int index)
{
    struct Node* first = head;
    struct Node* second = head->next;

    for(int i =0; i<index-1; i++)
    {
        if(second != NULL)
        {
            first = first->next;
            second = second->next;
        }
        else{
            first = NULL;
            second = NULL;
            break;
        }
    }

    if(first != NULL || second != NULL){
        first->next = second->next;
        free(second);
    }
    return head;

}

//O(n)
struct Node* DeleteByValue(struct Node* head, int value)
{
    struct Node* first = head;
    struct Node* second = head->next;

    while(second->data != value && second->next != NULL ){
        first = first->next;
        second = second->next;
    }

    if(second->data == value){
        first->next = second->next;
        free(second);
    }
    return head;
}

//O(n)
struct Node* DeleteAtLast(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// SEARCHING
//Using While Loop - O(n)
void FindValue(struct Node* node, int value)
{
    while(node != NULL)
    {
        if(value == node->data)
        {
            printf("%d ", node->data);
            return;
        }
        else
        {
            node = node->next;
        }
    }
}

//GET ALL VALUE
//Using Recursion - O(n)
void LinkListTraversal(struct Node* node)
{
    if(node != NULL)
    {
        printf("%d ", node->data);
        LinkListTraversal(node->next);
    }
}

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* end;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    end = (struct Node*) malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 9;
    third->next = end;

    end->data = 15;
    end->next = NULL;

    printf("List before inserting\n");
    LinkListTraversal(head);

    //head = InsertAtBeginning(head, 100);
    //head = InsertInBetween(head, 100, 3);
    //head = InsertAtEnd(head, 100);
    //InsertAfter(second, 500);

    //Delete
    //head = DeleteFirst(head);
    //head = DeleteAtIndex(head, 3);
    //head = DeleteAtLast(head);
    //head = DeleteByValue(head,10);

    printf("\nList After inserting\n");
    LinkListTraversal(head);

    return 0;
}
