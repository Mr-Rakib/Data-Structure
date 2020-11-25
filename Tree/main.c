#include <stdio.h>
#include <stdlib.h>
#include "TreeTraverse.h"
#include "Operations.h"

// Tree Traverse: In-order,Pre-order, Post-order, End-order*
// Operations: Search(BST), Insert, Delete, Min, Max,

int MaxDepth(struct Tree* root)
{
    if(root == NULL)
        return 0;
    else
    {
        int ldepth = MaxDepth(root->left);
        int rdepth = MaxDepth(root->right);

        //printf("L: %d   R: %d\n", ldepth, rdepth);
        return (ldepth >= rdepth) ? ldepth+1 : rdepth+1;
    }
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

    Delete(root, 9);

    printf("\nIn-order   : ");
    Inorder(root);

    printf("\nEnd-order  : ");
    Endorder(root);

    printf("\nPre-order  : ");
    Preorder(root);

    printf("\nPost-order : ");
    Postorder(root);

    printf("\nSearch Result: %d\n", Search(root, 11)->data);
    printf("Max Height : %d\n",MaxDepth(root));

    return 0;
}
