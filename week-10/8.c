// Write a program to implement BFS & DFS algorithm.
#include <stdio.h>

int a[20][20], visited[20], q[20];
int n, i, f = 0, r = -1;

void bfs(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for(i = 1; i <= n; i++)
    {
        if(a[v][i] && !visited[i])
        {
            q[++r] = i;
            visited[i] = 1;
        }
    }

    if(f <= r)
        bfs(q[f++]);
}

void dfs(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for(i = 1; i <= n; i++)
    {
        if(a[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for(i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    for(i = 1; i <= n; i++)
        visited[i] = 0;

    f = 0;
    r = -1;
    bfs(start);

    printf("\nDFS Traversal: ");
    for(i = 1; i <= n; i++)
        visited[i] = 0;

    dfs(start);

    printf("\n");
    return 0;
}