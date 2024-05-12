#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 6
void initializeSingleSource(int dist[], int par[], bool visited[], int source)
{
    int i;
    for (i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
        par[i] = -1;
        visited[i] = false;
    }
    dist[source] = 0;
}

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void relax(int u, int graph[][V], int dist[], bool visited[], int par[])
{
    int v;
    for (int v = 0; v<V; v++)
    {
        if (graph[u][v] &&  dist[u] + graph[u][v] < dist[v])
        {
            dist[v] = dist[u] + graph[u][v];
            par[v] = u;
        }
    }
}

void dijkstra(int graph[][V], int dist[], bool visited[], int par[], int source)
{
    int u, count;
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        relax(u, graph, dist, visited, par);
        visited[u] = true;
}
}
int main () {
    int graph[V][V] = { { 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
                };
    int source = 1; // starting vertex

    int dist[V], par[V];
    bool visited[V];

    initializeSingleSource(dist, par, visited, source);

    dijkstra(graph, dist, visited, par, source);
    printf("Vertex\t\tDist\tParent\n");
    for(int i=0; i<V; i++)
        printf("%d\t\t%d\t\t%d\n", i, dist[i], par[i]);
   
}

