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

// Insertion
Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
    {
        root->left = insert(root->left, data); // Recur left
    }
    else
    {
        root->right = insert(root->right, data); // Recur right
    }
    return root; // Return the updated root pointer
}

// Finding Rightmost Node
Node *findRightMost(Node *root)
{
    if (root->right != NULL)
    {
        return findRightMost(root->right);
    }
    return root; // Return the rightmost node
}

// Helper Function for Deletion
Node *helper(Node *root)
{
    if (root->left == NULL)
        return root->right; // If no left child
    if (root->right == NULL)
        return root->left; // If no right child

    Node *rightChild = root->right;
    Node *lastRightInLeft = findRightMost(root->left);
    lastRightInLeft->right = rightChild;
    return root->left; // Return the new root after deletion
}

// Deletion
Node *del(Node *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
    {
        Node *temp = helper(root);
        free(root);  // Free the memory of the deleted node
        return temp; // Return the new root
    }

    if (data < root->data)
    {
        root->left = del(root->left, data); // Recur left
    }
    else
    {
        root->right = del(root->right, data); // Recur right
    }
    return root; // Return the updated root pointer
}

// Inorder Traversal
void in(Node *root)
{
    if (root == NULL)
        return;
    in(root->left);
    printf("%d ", root->data);
    in(root->right);
}

int main()
{
    Node *root = NULL;
    int ch, val;
    while (1)
    {
        printf("Enter your choice: 1-ins 2-del 3-trv 4-exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &val);
            root = insert(root, val); // Update root
            break;
        case 2:
            printf("Enter value to be deleted: ");
            scanf("%d", &val);
            root = del(root, val); // Update root
            break;
        case 3:
            printf("\nINORDER: ");
            in(root);
            printf("\n"); // Newline for better output formatting
            break;
        case 4:
            exit(0);
            break;
        default: // Corrected typo
            printf("Wrong choice\n");
        }
    }
    return 0;
}
