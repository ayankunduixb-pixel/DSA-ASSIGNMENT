#include <stdio.h>

int adj[20][20],visited[20],n;

void BFS(int start){
    int queue[20],front = 0,rear = -1;

    for(int i = 0;i<n;i++){
        visited[i] = 0;
    }

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal");
    while(front <= rear){
        int v = queue[front++];
        printf("%d ",v);

        for(int i = 0;i<n;i++){
            if(adj[v][i] == 1 && visited[i] == 0){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int v){
    int i;
    visited[v] = 1;
    printf("%d ",v);

    for(int i = 0;i<n;i++){
        if(adj[v][i] == 1 && visited[i] == 0){
            DFS(i);
        }
    }
}

int main() {
    printf("Enetr number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    int start;
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    DFS(start);
    return 0;
}