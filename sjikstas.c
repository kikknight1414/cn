#include <stdio.h>
#define MAX 9999
int V;

int minDistance(int dist[], int sptSet[]) {
int min_index, min = MAX;
for (int v = 0; v < V; v++)
if (sptSet[v] == 0 && dist[v] <= min)
min = dist[v], min_index = v;

return min_index;
}

void dijkstra(int graph[V][V], int src) {
int dist[V];
int sptSet[V];
for (int i = 0; i < V; i++)
dist[i] = MAX, sptSet[i] = 0;
dist[src] = 0;

for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, sptSet);
sptSet[u] = 1;

for (int v = 0; v < V; v++)
if (!sptSet[v] && graph[u][v] && dist[u] != MAX && dist[u] + graph[u][v] < dist[v])
dist[v] = dist[u] + graph[u][v];
}

printf("Vertex \t\t Distance from Source\n");
for (int i = 0; i < V; i++)
printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void main() {
int sc;
printf("Enter the no of vertices:");
scanf("%d", &V);
int graph[V][V];
printf("Enter the adjacency matrix:\n");

for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
scanf("%d", &graph[i][j]);
if (graph[i][j] == -1) {
graph[i][j] = MAX;
}
}
}

printf("Enter the source vertex:");
scanf("%d", &sc);
dijkstra(graph, sc);
}
