#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
};


struct Tree* newTree(int data)
{
    struct Tree* node = (struct Tree*) malloc(sizeof(struct Tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void Postorder(struct Tree* node)
{
    if(node == NULL)
    {
        return ;
    }
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}

void Preorder(struct Tree* node)
{
    if(node == NULL)
    {
        return ;
    }
    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

void Inorder(struct Tree* node)
{
    if(node == NULL)
    {
        return ;
    }
    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

int main()
{
    struct Tree* root;
    struct Tree* second;
    struct Tree* third;
    struct Tree* fourth;
    struct Tree* fifth;
    struct Tree* six;

    root = newTree(5);
    second = newTree(4);
    third = newTree(6);
    fourth = newTree(1);
    fifth = newTree(2);
    six = newTree(10);

    root->left = second;
    root->right = third;

    second->left = fourth;
    second->right = fifth;

    third->right = six;
    printf("Preorder : ");
    Preorder(root);
    printf("\nInorder : ");
    Inorder(root);
    printf("\nPostorder : ");
    Postorder(root);

    return 0;
}
