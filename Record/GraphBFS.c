#include <stdio.h>
#include <stdlib.h>

void BFS(int graph[10][10], int start, int n) {
    int visited[10] = {0};
    int queue[10];
    int fr = 0, re = -1;
    visited[start] = 1;
    queue[++re] = start;

    while (fr <= re) {
        int curr = queue[fr++];
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++re] = i;
            }
        }
    }
}

void main() {
    int n, graph[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    int start;
    scanf("%d", &start);
    printf("BFS traversal: ");
    BFS(graph, start, n);
}
