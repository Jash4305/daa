#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct Edge {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct Graph {
    int V; 
    int E; 
    Edge* edge; // Array of edges
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

void printDistances(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void bellmanFord(Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    
    // Step 1: Initialize distances from source to all vertices as INFINITE
    for (int i = 0; i < V; ++i)
        dist[i] = INF;
    dist[source] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Step 4: Print the distances
    printDistances(dist, V);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Graph* graph = createGraph(V, E);

    printf("Enter details of each edge (source, destination, weight):\n");
    for (int i = 0; i < E; ++i) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, source);

    return 0;
}
