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

struct Tree* Search (struct Tree* root, int data)
{
    if(root == NULL)
    {
        printf("\n%d Not found...\n", data);
    }
    if(root->data  == data)
    {
        return root;
    }

    if(data < root->data)
        return Search(root->left, data);

    if(data > root->data)
        return Search(root->right, data);
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

struct Tree* Delete(struct Tree* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
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
        root->right = Delete(root->right, temp->data);
    }
    return root;
}
