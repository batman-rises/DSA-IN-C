#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertB(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}
void insertE(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
    }
}
void insertK(Node **head, int k, int data)
{

    if (k == 0)
    {
        insertB(head, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = *head;
    int i = 0;
    while (i < k - 1 && temp->next != *head)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteB(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    Node *temp = *head;
    if (*head->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}
void deleteE(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }

    if (*head->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        Node *temp = *head;
        Node *prev;
        while (temp->next != *head)
        {
            prev = temp;
            temp->next = prev;
        }
        prev->next = *head;
        free(temp);
    }
}
void deleteK(Node **head, int k)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }

    if (*head->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        Node *temp = *head;
        Node *prev;
        int i = 0;
        while (i < k && temp->next != *head)
        {
            prev = temp;
            temp->next = prev;
        }
        prev->next = temp->next;
        free(temp);
    }
}
void display(Node *head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}
int main()
{
}