#include <stdio.h>
#include <stdlib.h>

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
Node *createTree()
{
    int data;
    printf("enter data");
    scanf("%d", &data);
    Node *newNode = createNode(data);
    printf("enter the left then right child of %d", data);
    newNode->left = createTree();
    newNode->right = createTree();
    return newNode;
}
void pre(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    pre(root->left);
    pre(root->right);
}
void in(Node *root)
{
    if (root == NULL)
        return;
    in(root->left);
    printf("%d ", root->data);
    in(root->right);
}
void post(Node *root)
{
    if (root == NULL)
        return;
    post(root->left);
    post(root->right);
    printf("%d ", root->data);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    printf("CreateBinary Tree");
    Node *root = createTree();
    pre(root);
    in(root);
    post(root);
    return 0;
    freeTree(root);
}