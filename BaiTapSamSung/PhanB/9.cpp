#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void findEulerCycle();

private:
    int vertices;
    vector<vector<int>> adjList;
    stack<int> circuit;

    void DFS(int start);
    bool isEulerianCycleExists();
    bool isNextEdge(int u, int v);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

void Graph::DFS(int start) {
    stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        for (int neighbor : adjList[currentVertex]) {
            if (isNextEdge(currentVertex, neighbor)) {
                stack.push(neighbor);
                circuit.push(neighbor);
            }
        }
    }
}

bool Graph::isNextEdge(int u, int v) {

    for (int neighbor : adjList[u]) {
        if (neighbor == v) {
            return true;
        }
    }
    return false;
}

bool Graph::isEulerianCycleExists() {
    for (int i = 0; i < vertices; ++i) {
        if (adjList[i].size() % 2 != 0) {
            return false;
        }
    }
    return true;
}

void Graph::findEulerCycle() {
    if (!isEulerianCycleExists()) {
        cout << "Khong ton tai chu trinh Euler.\n";
        return;
    }

    int startVertex = 0;
    circuit.push(startVertex);

    while (!circuit.empty()) {
        int currentVertex = circuit.top();

        if (adjList[currentVertex].empty()) {
            circuit.pop();
        } else {
            int nextVertex = adjList[currentVertex].back();
            adjList[currentVertex].pop_back();

            circuit.push(nextVertex);
        }
    }

    // In chu trình Euler
    while (!circuit.empty()) {
        cout << circuit.top() << " ";
        circuit.pop();
    }
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

    cout << "Chu trinh Euler: ";
    graph.findEulerCycle();

    return 0;
}
