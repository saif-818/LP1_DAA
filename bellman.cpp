#include <bits/stdc++.h> 
using namespace std;
struct Edge
{
    int src;
    int dest;
    float wt;
};
struct Graph
{
    int v;
    int e;
    struct Edge *edge;
};
void printResult(Graph *graph, int *parent, int *dist, int src_vertex)
{
    for (int i = 1; i <= graph->v; i++)
    {
        vector<int> res;
        int temp = (graph->v) - i;
        while (temp != src_vertex)
        {
            res.push_back(temp);
            temp = parent[temp];
        }
        res.push_back(src_vertex);
        reverse(res.begin(), res.end());

        cout << "Shortest path for vertex " << (graph->v) - i << " is"
             << "\n";
        cout << res[0];
        for (int i = 1; i < res.size(); i++)
        {
            cout << "-->" << res[i];
        }
        cout << "\n";
        cout << "Shortest distance is:" << dist[(graph->v) - i] << "\n";
        cout << " "
             << "\n";
    }
}
void bellmanFord(Graph *graph, int src_vertex)
{
    int V = graph->v;
    int E = graph->e;
    int dist[V], parent[V];
    int u, v, weight;
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = src_vertex;
    }
    dist[src_vertex] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            u = graph->edge[j].src;
            v = graph->edge[j].dest;
            weight = graph->edge[j].wt;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
            {

                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
    for (int j = 0; j < E; j++)
    {
        u = graph->edge[j].src;
        v = graph->edge[j].dest;
        weight = graph->edge[j].wt;
        if (dist[u] != INT_MAX && dist[v] > dist[u] + weight)
        {
            cout << "Graph contains negative edge cycle"
                 << "\n";
            return;
        }
    }
    printResult(graph, parent, dist, src_vertex);
    return;
}
int main()
{
    int V, E;
    cout << "Enter the no of vertices"
         << "\n";
    cin >> V;
    cout << "Enter the no of edges"
         << "\n";
    cin >> E;
    struct Graph *graph = new Graph;
    graph->v = V;
    graph->e = E;
    graph->edge = new Edge[E];

    for (int i = 0; i < E; i++)
    {
        cout << "Enter the source,destination and weight of edge " << i + 1 << "\n";
        cout << "Source: ";
        cin >> graph->edge[i].src;
        cout << "Destination: ";
        cin >> graph->edge[i].dest;
        cout << "weight: ";
        cin >> graph->edge[i].wt;
        cout << "\n";
    }
    int src;
    cout << "Enter the source vertex"
         << "\n";
    cin >> src;
    bellmanFord(graph, src);
    return 0;
}