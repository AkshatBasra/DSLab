#include <stdio.h>

int graph[10][10], visited[10] = {0}, n, i, j;

void DFS(int v)
{
    visited[v] = 1;
    for(i = 0 ;i < n; i++)
    {
        if(graph[v][i] && !visited[i])
            DFS(i);
    }
}

void main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter Adjecency Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    DFS(0);
    int notConnected = 0;
    for(i = 0; i < n; i++)
        if(!visited[i])
            notConnected = 1;
    if(notConnected)
        printf("Graph is not connected");
    else
        printf("Graph is connected");
}
