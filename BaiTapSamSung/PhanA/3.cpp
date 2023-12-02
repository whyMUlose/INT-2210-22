#include <vector>
#include <unordered_set>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    int countParallelEdges();

private:
    int vertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

int Graph::countParallelEdges() {
    int parallelEdges = 0;
    unordered_set<int> uniqueEdges;

    for (int i = 0; i < vertices; ++i) {
        for (int j : adjacencyList[i]) {
            int edgeHash = i * vertices + j;

            if (uniqueEdges.find(edgeHash) != uniqueEdges.end()) {
                // Đã có cạnh song song giống nhau
                parallelEdges++;
            } else {
                // Thêm cạnh vào tập hợp
                uniqueEdges.insert(edgeHash);
            }
        }
    }

    return parallelEdges;
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

    int parallelEdges = graph.countParallelEdges();

    cout << "So canh song song trong do thi la: " << parallelEdges << endl;

    return 0;
}
