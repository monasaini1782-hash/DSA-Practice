#include <iostream>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edge[100];

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    int dist[100];

    // Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = 9999;

    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].weight;

            if (dist[u] != 9999 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < E; j++) {
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].weight;

        if (dist[u] != 9999 && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle exists.\n";
            return 0;
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " = " << dist[i] << endl;
    }

    return 0;
}