#include <stdio.h>

#define INF 99999

void bellmanFord(int V, int graph[V][V], int src) {
  int dist[V];
  for (int i = 0; i < V; i++) dist[i] = INF;
  dist[src] = 0;

  for (int k = 0; k < V - 1; k++) {
    for (int j = 0; j < V; j++) {
      for (int i = 0; i < V; i++) {
        if (graph[i][j] != INF && dist[i] != INF && dist[i] + graph[i][j] < dist[j]) {
          dist[j] = dist[i] + graph[i][j];
        }
      }
    }
  }

  for (int i = 0; i < V; i++) {
    printf("Distance to %d: %d\n", i, dist[i]);
  }
}

int main() {
  int graph[6][6] = {
    {0, 5, INF, 10, INF, INF},
    {INF, 0, 3, INF, INF, INF},
    {INF, INF, 0, 1, INF, INF},
    {INF, INF, INF, 0, 6, INF},
    {INF, INF, 2, INF, 0, 2},
    {INF, INF, INF, INF, INF, INF}
  };
  bellmanFord(6, graph, 0);
}

