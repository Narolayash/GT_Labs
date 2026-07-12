// Problem 2: Write a program to perform the following operations on a connected graph: 
// 1. Construct a spanning tree of the graph.  
// 2. Identify all branches and chords.  
// 3. Find all fundamental circuits 
// 4. Calculate: Rank and Nullity of the graph  
// 5. Verify that: Number of branches = Rank and Number of chords = Nullity. 
// Input:  
// Enter number of vertices: 5 
// Enter number of edges: 6 
// edges[][] = {(0,1),(0,2),(1,2),(1,3),(2,4),(3,4)} 
// Output:  
// Branches: 
// (0,1) 
// (0,2) 
// (1,3) 
// (2,4) 
// Chords: 
// (1,2) 
// (3,4) 
// Fundamental Circuits: C1 = {(0,1),(0,2),(1,2)} C2 = {(1,3),(2,4),(3,4)}  
// Rank of Graph = 4 
// Nullity of Graph = 2 

#include <stdio.h>

void queue(int adj[][], int n, int visited[], int spanningEdges[][2]) {

}

int main () {
    int V = 5;
    int E = 6;
    int edges[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};

    int adj[][5] = {
        {0, 1, 1, 0, 0}, 
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0}
    };

    int visited[5] = {0, 0, 0, 0, 0};

    int spanningEdges[V - 1][2];

    void queue(adj, n, visited, spanningEdges);

    return 0;
}
