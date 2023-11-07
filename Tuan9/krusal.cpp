#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, d;

    bool operator<(const Edge& other) const {
        return d < other.d;
    }
};

vector<Edge> edges;
vector<int> parent;

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    ifstream infile("connection.txt");
    ofstream outfile("connection.out");

    int n, m;
    infile >> n >> m;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i; // Khoi tao cac tap con rieng le
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        infile >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    sort(edges.begin(), edges.end());

    long long total_cost = 0;
    vector<Edge> mst;

    for (const Edge& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unionSets(edge.u, edge.v);
            total_cost += edge.d;
            mst.push_back(edge);
        }
    }

    outfile << total_cost << endl;
    for (const Edge& edge : mst) {
        outfile << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}

