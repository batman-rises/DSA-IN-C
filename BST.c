#include <stdio.h>
#include <stdlib.h>

// creation
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// insertion
Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    Node *cur = root;
    while (1)
    {
        if (data < cur->data)
        {
            if (cur->left != NULL)
            {
                cur = cur->left;
            }
            else
            {
                cur->left = createNode(data);
                break;
            }
        }
        else
        {
            if (cur->right != NULL)
            {
                cur = cur->right;
            }
            else
            {
                cur->right = createNode(data);
                break;
            }
        }
    }
    return root;
}
// deletion
Node *findRightMost(Node *root)
{
    if (root->right == NULL)
        return;

    return findRightMost(root->right);
}

Node *helper(Node *root)
{
    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;

    Node *rightChild = root->right;
    Node *lastRightinLeft = findRightMost(root->left);
    lastRightinLeft->right = rightChild;
    return root->left;
}
Node *delete(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return helper(root);

    Node *dummy = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}
// traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
// main
int main()
{
    Node *root = NULL;
    int val[] = {20, 30, 40, 50};
    int n = sizeof(val) / sizeof(val[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, val[i]);

    int ch, value;
    while (1)
    {
        printf("enter choice: 1.INSERT 2.DELETE 3. TRAVERSAL 4.EXIT");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter value to be inserted");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("enter value to be deleted");
            scanf("%d", &value);
            root = delete (root, value);
            break;
        case 3:
            printf("inorder");
            inorder(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("wrong choice");
        }
    }
    return 0;
}