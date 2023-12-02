#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    bool hasHamiltonianPath();

private:
    int vertices;
    vector<vector<int>> adjList;
    vector<int> inDegree;
    vector<int> topologicalOrder;

    void topologicalSort();
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
    inDegree.resize(vertices, 0);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    inDegree[v]++;
}

void Graph::topologicalSort() {
    stack<int> s;

    for (int i = 0; i < vertices; ++i) {
        if (inDegree[i] == 0) {
            s.push(i);
        }
    }

    while (!s.empty()) {
        int currentVertex = s.top();
        s.pop();
        topologicalOrder.push_back(currentVertex);

        for (int neighbor : adjList[currentVertex]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                s.push(neighbor);
            }
        }
    }
}

bool Graph::hasHamiltonianPath() {
    topologicalSort();
    for (int i = 0; i < vertices - 1; ++i) {
        bool found = false;
        for (int neighbor : adjList[topologicalOrder[i]]) {
            if (neighbor == topologicalOrder[i + 1]) {
                found = true;
                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    return true;
}

int main() {
    int V, E;
    cout << "Nhap so dinh V va so canh E: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Nhap " << E << " canh (u, v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.hasHamiltonianPath()) {
        cout << "Do thi co duong di Hamilton.\n";
    } else {
        cout << "Do thi khong co duong di Hamilton.\n";
    }

    return 0;
}
