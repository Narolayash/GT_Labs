// #include <stdio.h>

// void enque(int qu[], int size, int* f, int* r, int val) {
//     if (*r >= size) return;
//     qu[++(*r)] = val;
//     if (*f == -1) (*f)++;
// }

// int dque(int qu[], int size, int* f, int* r) {
//     if (*f > *r) return -1;
//     int val = qu[*f];
//     if (*f == *r) {
//         *f = -1;
//         *r = -1;
//     }
//     else (*f)++;
//     return val;
// }



// int main() {
//     int qu[100];
//     int front = - 1;
//     int rear = -1;

//     // int input[5][5] = {
//     //     {1, 2, 0, 0, 0},
//     //     {0, 2, 3, 0, 0},
//     //     {0, 1, 4, 0, 0},
//     //     {1, 4, 0, 0, 0},
//     //     {2, 3, 0, 0, 0}
//     // };
//     // int inputSize[5] = {2, 3, 3, 2, 2};

//     int adj[5][5] = {
//         {0, 1, 1, 0, 0}, 
//         {1, 0, 1, 1, 0}, 
//         {1, 1, 0, 0, 1}, 
//         {0, 1, 0, 0, 1}, 
//         {0, 0, 1, 1, 0}
//     };

//     int visited[5] = {0, 0, 0, 0, 0};

//     enque(qu, 100, &front, &rear, 0);

//     while (front != -1) {
//         int curr = dque(qu, 100, &front, &rear);
//         printf("%d ", curr);
//         visited[curr] = 1;

//         for (int i=0; i<5; i++) {
//             if (adj[curr][i] == 1 && visited[i] == 0) {
//                 enque(qu, 100, &front, &rear, i);
//                 visited[i] = 1;
//             }
//         }
//     }
// }


#include <stdio.h>
#include <stdlib.h>


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

    int queue[v];
    int front = 0, rear = 0;
    int visited[v];

    for (int i=0; i<v; i++) {
        visited[i] = 0;
    }

    queue[rear++] = 0;
    visited[0] = 1;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i=0; i<adjRowLenght[curr]; i++) {
            int neighbor = adj[curr][i];

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] =  neighbor;
            }
        }
    }

    return 0;
}
