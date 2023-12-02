#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void longestPath(int s) {
    dist.assign(adj.size(), INT_MIN);
    dist[s] = 0;
    for (int u = 0; u < adj.size(); u++) {
        for (auto [v, w] : adj[u]) {
            if (dist[u] != INT_MIN && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    int V, E, s, u, v, w;
    cin >> V >> E;
    adj.assign(V, vector<pair<int, int>>());
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> s;
    longestPath(s);
    for (int i = 0; i < V; i++)
        cout << "Longest path(" << s << ", " << i << ") = " << dist[i] << endl;
    return 0;
}
