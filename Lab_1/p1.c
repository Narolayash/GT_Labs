// Given the number of vertices and edges of a graph, the task is to represent the adjacency list of a 
// directed graph.

#include <stdio.h>

int main() {
    int noOfvertex;
    int noOfEdges;

    printf("Enter the no. of vertex: ");
    scanf("%d", &noOfvertex);

    printf("Enter the no. of edges: ");
    scanf("%d", &noOfEdges);

    int edges[noOfEdges][2];

    for (int i=0; i<noOfEdges; i++) {
        for (int j=0; j<2; j++) {
            edges[i][j] = 0;
        }
    }

    printf("--- Enter the edges --- \n");
    for (int i=0; i<noOfEdges; i++) {
        for (int j=0; j<2; j++) {
            printf("Enter the value of edges[%d][%d]: ", i, j);
            scanf("%d", &edges[i][j]);
        }
    }

    for (int i=0; i<noOfvertex; i++) {
        printf("%d -> ", i);
        for (int j=0; j<noOfEdges; j++) {
            if (i == edges[j][0]) printf("%d ", edges[j][1]);
        }
        printf("\n");
    }

    return 0;
}