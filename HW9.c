#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

void BFS(int graph[SIZE][SIZE], int startNode) {
    int queue[SIZE], front = 0, rear = 0;
    bool visited[SIZE] = {false};

    visited[startNode] = true;
    queue[rear++] = startNode;

    printf("BFS Traversal: ");

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        for (int i = 0; i < SIZE; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}


bool visitedDFS[SIZE] = {false};

void DFS(int graph[SIZE][SIZE], int v) {
    visitedDFS[v] = true;
    printf("%d ", v);

    for (int i = 0; i < SIZE; i++) {
        if (graph[v][i] == 1 && !visitedDFS[i]) {
            DFS(graph, i);
        }
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    BFS(graph, 0);  

    printf("DFS Traversal: ");
    DFS(graph, 0); 
    printf("\n");

    return 0;
}