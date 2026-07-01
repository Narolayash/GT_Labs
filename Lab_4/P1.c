#include <stdio.h>

int main () {
    int V = 6;
    int E = 5;
    int edges[][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};
    int degree[V];

    for (int i=0; i<V; i++) {
        degree[i] = 0;
    }
    
    for (int i=0; i<E; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }


    for (int i=0; i<V; i++) {
        if (degree[i] == 1) 
            printf("%d ", i);
    }


    int adj[V][V];
    int distance[V][V];
    
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            adj[i][j] = 0;
            distance[i][j] = 0;
        }
    }

    for (int i=0; i<E; i++) {
        adj[edges[i][0]][edges[i][1]]++;
        adj[edges[i][1]][edges[i][0]]++;
    }

    printf("\n");
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }


    printf("\n");
    for (int i=0; i<V; i++) {
        printf("%d ", degree[i]);
    }

    int queue[V];
    int visited[V];

    printf("\n");
    for (int s=0; s<V; s++) {
        // printf("%d: ", s);
        for (int i=0; i<V; i++) {
            queue[i] = 0;
            visited[i] = 0;
        }

        int f = 0, r = 0;
        queue[r++] = s;
        visited[s] = 1;
        
        while (f < r) {
            int curr = queue[f++];
            // printf("%d ", curr);

            for (int i=0; i<V; i++) {
                if (adj[curr][i] != 0 && visited[i] == 0) {
                    visited[i] = 1;
                    distance[s][i] = distance[s][curr] + 1;
                    queue[r++] = i;
                }
            }
        }
        // printf("\n");
    }

    printf("\n");
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            printf("%d ", distance[i][j]);
        }

        printf("\n");
    }

    int eccentricity[V];
    for (int i=0; i<V; i++) {
        printf("%d: ", i);
        int max = 0;
        for (int j=0; j<V; j++) {
            if (distance[i][j] > max) max = distance[i][j];
        }
        eccentricity[i] = max;
        printf("%d ", max);
        printf("\n");
    }

    int min_eccentricity = V;
    for (int i=0; i<V; i++) {
        if (min_eccentricity > eccentricity[i]) min_eccentricity = eccentricity[i];
    }

    printf("\n");
    printf("Center of tree: ");
    for (int i=0; i<V; i++) {
        if (min_eccentricity == eccentricity[i]) printf("%d ", i);
    }

    printf("\n");

    if (E == V - 1) 
        printf("Graph is tree");
    else 
        printf("Graph is not tree");

    return 0;
}
