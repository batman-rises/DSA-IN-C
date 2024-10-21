#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
}
// creation
Node *
createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = 0;
    newNode->height = 1;
    return newNode;
}

int height(Node *node)
{
    return node ? node->height : 0;
}

int getBal(Node *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}
// insertion
Node *rightRot(Node *root)
{
    Node *child = root->left;
    Node *rightChild = child->right;
    child->right = root;
    root->left = rightChild;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    child->height = 1 + (height(child->left) > height(child->right) ? height(child->left) : height(child->right));

    return child;
}
Node *leftRot(Node *root)
{
    Node *child = root->right;
    Node *leftChild = child->left;
    child->left = root;
    root->right = leftChild;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    child->height = 1 + (height(child->left) > height(child->right) ? height(child->left) : height(child->right));

    return child;
}
Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (root->data > data)
        root->left = insert(root->left, data);
    if (root->data < data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int bal = getBal(root);
    // LL
    if (bal > 1 && root->left->data > data)
        return rightRot(root);
    // LR
    if (bal > 1 && root->left->data < data)
    {
        root->left = leftRot(root->left);
        return rightRot(root);
    }
    // RR
    if (bal < -1 && root->right->data < data)
        return leftRot(root);
    // RL
    if (bal < -1 && root->right->data > data)
    {
        root->right = rightRot(root->right);
        return leftRot(root);
    }
    return root;
}

// deletion

// traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// main
int main()
{
    Node *root = NULL;
    int ch, value;
    while (1)
    {
        printf("1.INSERT 2.DELETE 3.TRAVERSAL 4.EXIT");
        printf("enter your choice");
        switch (ch)
        {
        case 1:
            printf("enter value to insert");
            scanf("%d", &value);
            insert(root, value);
            break;
        case 2:
            printf("enter value to delete");
            scanf("%d", &value);
            delete (root, value);
            break;
        case 3:
            printf("TRAVERSAL:/n");
            inorder(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("wrong choice");
        }
    }
}