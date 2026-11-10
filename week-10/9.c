// Write a program to implement Cycle detection in undirected graph.

#include <stdio.h>

int adj[20][20],visited[20],n;

int isCycle(int v,int parent){
    visited[v] = 1;
    for(int i = 0;i<n;i++){
        if(adj[v][i] == 1){
            if(visited[i] == 0){
                if(isCycle(i,v)){
                    return 1;
                }
            }
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    
    int cycle = 0;
    for(int i = 0;i<n;i++){
        if(visited[i] == 0){
            if(isCycle(i,-1)){
                cycle = 1;
                break;
            }
        }
    }

    if (cycle){
        printf("Cycle detected in the graph.");
    }
    else{
        printf("No cycle detected in the graph.");
    }

    return 0;
}