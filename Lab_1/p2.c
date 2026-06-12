// Write a program to perform the following basic graph-related operations: 
// 1. Represent a graph using adjacency matrix. 
// 2. Represent a graph using adjacency list. 
// 3. Find the degree of each vertex in the graph. 
// 4. Determine whether the graph is simple, complete, or connected. 
// 5. Display total number of vertices and edges. 

#include <stdio.h>

int main() {
    int noOfvertex;
    int noOfEdges;

    printf("Enter the no. of vertex: ");
    scanf("%d", &noOfvertex);

    printf("Enter the no. of edges: ");
    scanf("%d", &noOfEdges);

    int edges[noOfEdges][2];
    int adjacenyMatrix[noOfvertex][noOfvertex];
    int degree[noOfvertex];

    for (int i=0; i<noOfvertex; i++) {
        degree[i] = 0;
    }

    printf("--- Enter the edges --- \n");
    for (int i=0; i<noOfEdges; i++) {
        for (int j=0; j<2; j++) {
            printf("Enter the value of edges[%d][%d]: ", i, j);
            scanf("%d", &edges[i][j]);

            degree[edges[i][j]]++;
        }
    }


    // 1 adjaceny matrix
    for (int i=0; i<noOfvertex; i++) {
        for (int j=0; j<noOfvertex; j++) {
            adjacenyMatrix[i][j] = 0;
        }
        
    }

    for (int i=0; i<noOfEdges; i++) {
        adjacenyMatrix[edges[i][0]][edges[i][1]]++;
    }

    printf("--- Adjaceny Matrix --- \n");
    for (int i=0; i<noOfvertex; i++) {
        for (int j=0; j<noOfvertex; j++) {
            printf("%d ", adjacenyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    // 2. Adjaceny List
    printf("--- Adjaceny List --- \n");
    for (int i=0; i<noOfvertex; i++) {
        printf("%d -> ", i);
        for (int j=0; j<noOfEdges; j++) {
            if (edges[j][0] == i) 
                printf("%d ", edges[j][1]);
        }
        printf("\n");
    }


    // 3. degree of each vertes
    printf("\n");
    for (int i=0; i<noOfvertex; i++) {
        printf("degree of %d vertex -> %d\n", i, degree[i]);
    }

    printf("\n");
    // 4. simple, complete, or connected. 
    int simple = 1;
    for (int i=0; i<noOfvertex; i++) {
        for (int j=0; j<noOfvertex; j++) {
            if ((i == j && adjacenyMatrix[i][j] > 0) || adjacenyMatrix[i][j] > 1) {
                simple = 0;
                break;
            }
        }
    }
    if (simple) printf("graph is simple.\n");
    else printf("graph is not simple.\n");

    int complete = 1;
    for (int i=0; i<noOfvertex; i++) {
        if (degree[i] != noOfvertex - 1) {
            complete = 0;
            break;
        }
    }
    if (complete) printf("graph is complete.\n");
    else printf("graph is not complete.\n");

    // if (noOfEdges == noOfvertex * (noOfvertex - 1) / 2) printf("graph is complete.\n");
    // else printf("graph is not complete.\n"); 

    // connected graph mate login lakh vanu baki chhe...
    // int connected = 1;

    printf("\n");
    // 5. total no of vertices and edges
    printf("no of vertices: %d\n", noOfvertex);
    printf("no of edges: %d\n", noOfEdges);
}