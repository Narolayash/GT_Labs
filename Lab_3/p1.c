#include<stdio.h>
#include<stdlib.h>


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

    int stack[100];
    int top = -1;

    int visited[v];

    for (int i=0; i<v; i++) {
        visited[i] = 0;
    }

    stack[++top] = 0;
    visited[0] = 1;

    while (top != -1) {
        int curr = stack[top--];
        printf("%d ", curr);

        for (int i= adjRowLenght[curr]-1; i>=0; i--) {
            if (visited[adj[curr][i]] != 1) {
                stack[++top] = adj[curr][i];
                visited[adj[curr][i]] = 1;
            }
        }
    }

    return 0;
}