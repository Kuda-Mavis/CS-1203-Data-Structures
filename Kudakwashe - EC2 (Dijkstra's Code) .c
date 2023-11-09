#include <stdio.h>
#include <limits.h>

#define V 6

void printPath(int parent[], int j) {
    // Base Case: If j is the source
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf(" -> %d", j);
}

void printSolution(int dist[], int parent[]) {
    printf("Vertex   Distance from Source   Path\n");
    for (int i = 1; i < V; i++) {
        printf("%d \t\t %d \t\t\t 0", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int parent[V];
    int sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent);
}

int main() {
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                       {1, 0, 4, 2, 7, 0},
                       {4, 4, 0, 3, 5, 0},
                       {0, 2, 3, 0, 4, 6},
                       {0, 7, 5, 4, 0, 7},
                       {0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
