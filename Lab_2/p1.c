#include <stdio.h>

void enque(int qu[], int size, int* f, int* r, int val) {
    if (*r >= size) return;
    qu[++(*r)] = val;
    if (*f == -1) (*f)++;
}

int dque(int qu[], int size, int* f, int* r) {
    if (*f > *r) return -1;
    int val = qu[*f];
    if (*f == *r) {
        *f = -1;
        *r = -1;
    }
    else (*f)++;
    return val;
}



int main() {
    int qu[100];
    int front = - 1;
    int rear = -1;

    // int input[5][5] = {
    //     {1, 2, 0, 0, 0},
    //     {0, 2, 3, 0, 0},
    //     {0, 1, 4, 0, 0},
    //     {1, 4, 0, 0, 0},
    //     {2, 3, 0, 0, 0}
    // };
    // int inputSize[5] = {2, 3, 3, 2, 2};

    int adj[5][5] = {
        {0, 1, 1, 0, 0}, 
        {1, 0, 1, 1, 0}, 
        {1, 1, 0, 0, 1}, 
        {0, 1, 0, 0, 1}, 
        {0, 0, 1, 1, 0}
    };

    int visited[5] = {0, 0, 0, 0, 0};

    enque(qu, 100, &front, &rear, 0);

    while (front != -1) {
        int curr = dque(qu, 100, &front, &rear);
        printf("%d ", curr);
        visited[curr] = 1;

        for (int i=0; i<5; i++) {
            if (adj[curr][i] == 1 && visited[i] == 0) {
                enque(qu, 100, &front, &rear, i);
                visited[i] = 1;
            }
        }
    }
}
