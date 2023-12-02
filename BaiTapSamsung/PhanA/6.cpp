#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    bool isEdgeConnected();

private:
    int vertices;
    vector<vector<int>> adjacencyList;
    vector<int> discoveryTime;
    vector<int> low;
    vector<bool> visited;
    int time;

    void DFS(int u, int parent);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
    discoveryTime.resize(vertices, -1);
    low.resize(vertices, -1);
    visited.resize(vertices, false);
    time = 0;
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

void Graph::DFS(int u, int parent) {
    visited[u] = true;
    discoveryTime[u] = low[u] = ++time;

    for (int v : adjacencyList[u]) {
        if (!visited[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > discoveryTime[u]) {
                cout << "Cau found: " << u << " - " << v << endl;
            }
        } else if (v != parent) {
            low[u] = min(low[u], discoveryTime[v]);
        }
    }
}

bool Graph::isEdgeConnected() {
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            DFS(i, -1);
        }
    }

    // Nếu có cầu, đồ thị không liên thông cạnh
    for (int i = 0; i < vertices; ++i) {
        if (discoveryTime[i] == -1) {
            return false;
        }
    }

    return true;
}

int main() {
    int V, E;
    cout << "Nhap so dinh V: ";
    cin >> V;
    cout << "Nhap so canh E: ";
    cin >> E;

    Graph graph(V);

    cout << "Nhap " << E << " canh (u, v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.isEdgeConnected()) {
        cout << "Do thi lien thong canh.\n";
    } else {
        cout << "Do thi khong lien thong canh.\n";
    }

    return 0;
}
