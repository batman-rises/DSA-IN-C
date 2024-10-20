#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void DFS(int graph[MAX][MAX], int vis[MAX], int vertex, int n)
{
    vis[vertex] = 1;
    printf("%d", vertex);
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(graph, vis, i, n);
        }
    }
}

int main()
{
    int graph[MAX][MAX];
    int vis[MAX];

    int n, m;
    printf("enter the no.of vertices then edges:");
    scanf("%d", &n);
    scanf("%d", &m);

    printf("enter the edges:-//u & v");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &u);
        scanf("%d", &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int startingVertex;
    printf("enter starting vertex");
    scanf("%d", &startingVertex);

    printf("DFS starting from vertex %d", startingVertex);
    DFS(graph, vis, startingVertex, n);
}