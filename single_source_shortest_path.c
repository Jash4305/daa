#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Define a structure to represent an edge
struct Edge {
    int source;
    int destination;
    int weight;
};

// Define a structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    struct Edge* edge; // Array of edges
};

// Function to create a new graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to print the distances from the source vertex
void printDistances(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Bellman-Ford algorithm implementation
void bellmanFord(struct Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    
    // Initialize distances from source to all vertices as INFINITE
    for (int i = 0; i < V; ++i)
        dist[i] = INF;
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print the distances
    printDistances(dist, V);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; ++i)
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, source);

    return 0;
}
