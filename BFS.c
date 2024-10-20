#include <stdio.h>
#include <stdlib.h>

// Structure to represent an adjacency list node
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Structure to represent a queue
typedef struct Queue
{
    int *items;
    int front;
    int rear;
    int maxSize;
} Queue;

// Structure to represent a graph
typedef struct Graph
{
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;

// Function to create a node
Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
Queue *createQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->maxSize = size;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == -1;
}

// Enqueue function
void enqueue(Queue *q, int value)
{
    if (q->rear == q->maxSize - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Dequeue function
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1; // Reset the queue
        }
        return item;
    }
}

// Function to create a graph
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Mark all vertices as unvisited initially
    }

    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS algorithm
void BFS(Graph *graph, int startVertex)
{
    Queue *q = createQueue(graph->numVertices);
    graph->visited[startVertex] = 1; // Mark the starting vertex as visited
    enqueue(q, startVertex);         // Enqueue the starting vertex

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex;

            // Visit unvisited adjacent vertices
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1; // Mark as visited
                enqueue(q, adjVertex);         // Enqueue
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int vertices, edges, src, dest;

    // User input for number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // User input for edges
    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    BFS(graph, startVertex);

    return 0;
}
