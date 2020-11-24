#include <stdio.h>
#include <stdlib.h>
#include "TreeTraverse.h"


struct Tree* MinValue(struct Tree* root)
{
    struct Tree* temp = root;
    while(temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

struct Tree* MaxValue(struct Tree* root)
{
    struct Tree* temp = root;
    while(temp != NULL && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

struct Tree* Insert(struct Tree* root, int data)
{
    struct Tree* tempTree = newTree(data);

    if(root == NULL)
    {
        return tempTree;
    }

    if(data<= root->data)
    {
        root->left = Insert(root->left, data);
    }

    else if(data> root->data)
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

struct Tree* deleteNode(struct Tree* root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }


    else
    {
        if (root->left == NULL)
        {
            struct Tree* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Tree* temp = root->left;
            free(root);
            return temp;
        }

        struct Tree* temp = MinValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct Tree* root = NULL;

    root = Insert(root, 5);
    Insert(root, 4);
    Insert(root, 6);
    Insert(root, 2);
    Insert(root, 3);
    Insert(root, 8);
    Insert(root, 7);
    Insert(root, 1);

    Insert(root, 15);
    Insert(root, 12);
    Insert(root, 13);
    Insert(root, 14);
    Insert(root, 9);
    Insert(root, 10);
    Insert(root, 11);
    Insert(root, 17);
    Insert(root, 19);
    Insert(root, 18);


    printf("\nIn-order   : ");
    Inorder(root);


    printf("\nEnd-order  : ");
    Endorder(root);

    printf("\nPre-order  : ");
    Preorder(root);

    printf("\nPost-order : ");
    Postorder(root);

    return 0;
}
