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
    if(node != NULL)
    {
        Postorder(node->left);
        Postorder(node->right);
        printf("%d ", node->data);
    }
}

void Preorder(struct Tree* node)
{
    if(node != NULL)
    {
        printf("%d ", node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Inorder(struct Tree* node)
{
    if(node != NULL)
    {
        Inorder(node->left);
        printf("%d ", node->data);
        Inorder(node->right);
    }
}

void Endorder(struct Tree* node)
{
    if(node != NULL)
    {
        Endorder(node->right);
        printf("%d ", node->data);
        Endorder(node->left);
    }
}
