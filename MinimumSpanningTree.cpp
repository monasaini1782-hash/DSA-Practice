#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

struct Edge
{
    int u, v, w;
};

// Sort edges according to weight
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

// Find parent
int findParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, x);
}

// Join two sets
void unionSet(int parent[], int a, int b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a != b)
        parent[b] = a;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100];

    cout << "\nEnter edges (u v weight):\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    // Start execution time
    auto start = high_resolution_clock::now();

    // Sort edges
    sort(edges, edges + E, compare);

    int parent[100];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int count = 0;

    cout << "\n--- Minimum Spanning Tree ---\n";

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(parent, u) != findParent(parent, v))
        {
            cout << u << " - " << v
                 << "  Weight = " << edges[i].w << endl;

            totalCost += edges[i].w;

            unionSet(parent, u, v);

            count++;
        }
    }

    // End execution time
    auto end = high_resolution_clock::now();

    cout << "\nTotal Cost of MST = "
         << totalCost << endl;

    cout << "Execution Time = "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n";

    cout << "\n--- Time Complexity ---\n";
    cout << "Best Case    : O(E log E)" << endl;
    cout << "Average Case : O(E log E)" << endl;
    cout << "Worst Case   : O(E log E)" << endl;

    return 0;
}