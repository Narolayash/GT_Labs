#include <stdio.h>
#include <stdlib.h>

void dfs(int** adj, int adjRowLenght[], int visited[], int start) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i=0; i<adjRowLenght[start]; i++) {
        if (visited[adj[start][i]] != 1) {
            dfs(adj, adjRowLenght, visited, adj[start][i]);
        }
    }
}

int main () {
    int v;

    printf("Enter the no of vertices: ");
    scanf("%d", &v);

    printf("--- enter row length ---\n");
    int adjRowLenght[v];
    for (int i=0; i<v; i++) {
        printf("%d row length: ", i);
        scanf("%d", &adjRowLenght[i]);
    }

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

    int visited[5] = {0};
    dfs(adj, adjRowLenght, visited, 0);

    return 0;
}