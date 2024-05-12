#include <stdio.h>
#include <limits.h>

int minFunction(int a, int b) {
    return (a < b) ? a : b;
}

int multistageGraph(int vertex, int graph[vertex][vertex]) {
    int dist[vertex]; 
    for (int i = 0; i < vertex; i++)
        dist[i] = INT_MAX;

    dist[vertex-1] = 0;

    for (int i = vertex - 2; i >= 0; i--) {
        for (int j = i; j < vertex; j++) {
            if (graph[i][j] != 0) {
                dist[i] = minFunction(dist[i], graph[i][j] + dist[j]);
            }
        }
    }
    return dist[0];
}

//user inputs and multistageGraph() call
int main() {
    int vertex, edgeCount;

    printf("Enter the total vertices of the graph : ");
    scanf("%d", &vertex);
    int G[vertex][vertex];
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < vertex; i++)
    {
        printf("Total Edges of vertex %d : ", i + 1);
        scanf("%d", &edgeCount);
        for (int j = 0; j < edgeCount; j++)
        {
            int vertexIndex, edgeWeight;
            printf("Enter the vertex number : ");
            scanf("%d", &vertexIndex);
            printf("Enter the edge weight : ");
            scanf("%d", &edgeWeight);
            G[i][vertexIndex - 1] = edgeWeight; // Corrected index
        }

        printf("\n");
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            printf("%d ", G[i][j]);
        printf("\n");
    }
    printf("Minimum distance from the first stage to the last stage: %d\n", multistageGraph(vertex, G));

    return 0;
}
