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
    printf("Enter data (or -1 to stop): ");
    scanf("%d", &data);

    if (data == -1) // Use -1 to indicate no node (base case)
        return NULL;

    Node *newNode = createNode(data);
    printf("Enter left child of %d:\n", data);
    newNode->left = createTree(); // Recursive call for left child
    printf("Enter right child of %d:\n", data);
    newNode->right = createTree(); // Recursive call for right child
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
    Node *node = root; // Start from the root node
    while (node != NULL || top >= 0)
    {
        while (node != NULL)
        {
            st[++top] = node;
            node = node->left; // Go to the leftmost child
        }
        node = st[top--]; // Backtrack
        printf("%d ", node->data);
        node = node->right; // Visit the right subtree
    }
}

void post(Node *root)
{
    if (root == NULL)
        return;

    Node *st1[100];
    int top1 = -1;
    Node *st2[100];
    int top2 = -1;

    st1[++top1] = root;
    while (top1 >= 0)
    {
        Node *node = st1[top1--];
        st2[++top2] = node; // Push to second stack

        if (node->left)
            st1[++top1] = node->left; // Left child first
        if (node->right)
            st1[++top1] = node->right; // Right child next
    }
    while (top2 >= 0)
    {
        Node *node = st2[top2--];
        printf("%d ", node->data);
    }
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
    Node *root = createTree();
    printf("Pre-order Traversal: ");
    pre(root);
    printf("\nIn-order Traversal: ");
    in(root);
    printf("\nPost-order Traversal: ");
    post(root);
    printf("\n");
    freeTree(root);
    return 0;
}
