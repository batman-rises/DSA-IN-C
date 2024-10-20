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

    Node *st[100];
    int top = -1;
    st[++top] = root;

    while (top >= 0)
    {

        Node *node = st[top--];
        printf("%d ", node->data);

        if (node->right)
            st[++top] = node->right;
        if (node->left)
            st[++top] = node->left;
    }
}
void in(Node *root)
{
    if (root == NULL)
        return;

    Node *st[100];
    int top = -1;
    Node *node = root;
    while (node != NULL || top >= 0)
    {

        while (node != NULL)
        {
            st[++top] = node;
            node = node->left;
        }
        node = st[top--];
        printf("%d", node->data);

        node = node->right;
    }
}
void post(Node *root)
{
    if (root == NULL)
        return;

    Node *st1[100];
    Node *st2[100];
    int top1 = -1;
    int top2 = -1;

    st1[++top1] = root;
    while (top1 >= 0)
    {
        Node *node = st1[top1--];
        st2[++top2] = node;

        if (node->left)
            st1[++top1] = node->left;
        if (node->right)
            st1[++top1] = node->right;
    }
    while (top2 >= 0)
    {
        Node *node = st2[top2--];
        printf("%d ", node->data);
    }
}
int main()
{
    printf("CreateBinary Tree");
    Node *root = createTree();
    pre(root);
    in(root);
    post(root);
    return 0;
}