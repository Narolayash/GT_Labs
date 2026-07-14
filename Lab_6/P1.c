// Objective: To identify articulation points in an undirected graph and determine connectivity and separability of 
// a graph. 
// Problem: Write a program to find all cut-vertices of a graph. 
// Input: Connected graph with vertices and edges. 
// Output:  
// List of articulation points.

#include <stdio.h>
#include <stdlib.h>

void dfs(int** adj, int adjRowLenght[], int visited[], int remove, int start) {
    visited[start] = 1;
    // printf("%d ", start);

    for (int i=0; i<adjRowLenght[start]; i++) {
        if (visited[adj[start][i]] != 1 && adj[start][i] != remove) {
            dfs(adj, adjRowLenght, visited, remove, adj[start][i]);
        }
    }
}

int main() {
    int v = 6;
    int adjRowLenght[6] = {1, 3, 1, 3, 1, 1};

    int** adj = (int **) malloc(v * sizeof(int *));

    for (int i=0; i<v; i++) {
        adj[i] = (int *) malloc(adjRowLenght[i] * sizeof(int));
    }

    printf("--- enter elements of adj\n");
    for (int i=0; i<v; i++) {
        for (int j=0; j<adjRowLenght[i]; j++) {
            printf("%d %d: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i=0; i<v; i++) {
        for (int j=0; j<adjRowLenght[i]; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int remove = 0; remove < v; remove++) {
        int visited[6] = {0, 0, 0, 0, 0, 0};

        dfs(adj, adjRowLenght, visited, remove, adj[remove][0]);

        int sum = 0;
        for (int i=0; i<v; i++) {
            sum += visited[i];
        }

        if (sum != v - 1)
            printf("%d ", remove);
    }

    
    
    
    return 0;
}
