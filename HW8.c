#include <stdio.h>
#include <stdbool.h>

#define MAX 100


int graph[MAX][MAX];
bool visited[MAX];
int n; 

void DFS(int v) {
    visited[v] = true;
    printf("%d ", v); 

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void findClusters() {
    int clusterCount = 0;
    
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    printf("النتائج (Clusters Found):\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            DFS(i);
            printf("}\n");
        }
    }
}

int main() {
    n = 5;

    int exampleGraph[5][5] = {
        {0, 1, 0, 0, 0}, 
        {1, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 1}, 
        {0, 0, 1, 0, 0}, 
        {0, 0, 1, 0, 0}  
    };

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            graph[i][j] = exampleGraph[i][j];

    findClusters();

    return 0;
}