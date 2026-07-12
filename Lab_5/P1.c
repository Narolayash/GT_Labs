// Problem 1: In a social network of N people, some of them are directly connected as friends. If person A is a friend 
// of person B, and person B is a friend of person C, then A, B, and C are all part of the same friend circle (a connected 
// component in graph terms). You are given an undirected graph represented by an adjacency matrix of size N x N, 
// where matrix[i][j] = 1 indicates a direct friendship between person i and person j.  
// Your task is to determine the total number of friend circles. 
// Input: 
// 4 // total N people  
// 1 1 0 0 // adj. Matrix 
// 1 1 0 0 
// 0 0 1 1 
// 0 0 1 1 
// Output:  
// 2 


#include <stdio.h>

void bfs(int array[][4], int n, int visited[], int src) {
    int queue[n];
    int first = 0, last = 0;

    queue[last++] = src;
    visited[src] = 1;

    while (first < last) {
        int curr = queue[first++];
        printf("%d ", curr);

        for (int i=0; i<n; i++) {
            if (array[curr][i] && !visited[i]) {
                visited[i]=1;
                queue[last++] = i;
            }
        }
    }
} 

int main () {
    int V = 4;

    int adj[][4] = {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}};
    int visited[4] = {0, 0, 0, 0};

    int group = 0;

    for (int i=0; i<4; i++) {
        if (!visited[i]) {
            group++;
            bfs(adj, 4, visited, i);
            printf("\n");
        }
    }

    printf("ans = %d ", group);
}
