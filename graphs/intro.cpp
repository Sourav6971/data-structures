#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, bool isDirected = false)
    {
        adjList[u].push_back(v);
        if (!isDirected)
        {
            adjList[v].push_back(u); // If undirected, add edge both ways
        }
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (int neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5); // Graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    return 0;
}
