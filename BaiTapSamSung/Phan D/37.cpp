#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vi dist;

void dijkstra(int s, int C) {
    dist.assign(AdjList.size(), INF);
    dist[s] = 0;
    vector<deque<int>> buckets(2*C+1);
    buckets[C].push_back(s);
    for (int d = 0; d <= 2*C; d++) {
        for (int i = 0; i < buckets[d].size(); i++) {
            int u = buckets[d][i];
            if (dist[u] < d - C) continue;
            for (auto &[v, w] : AdjList[u]) {
                int nd = dist[u] + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    if (nd - d + C >= 0 && nd - d + C <= 2*C)
                        buckets[nd - d + C].push_back(v);
                    else
                        buckets[2*C].push_back(v);
                }
            }
        }
        buckets[d].clear();
    }
}

int main() {
    int V, E, s, t, u, v, w, C;
    cin >> V >> E >> C;
    AdjList.assign(V, vii());
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
    }
    cin >> s;
    dijkstra(s, C);
    for (int i = 0; i < V; i++)
        cout << "SSSP(" << s << ", " << i << ") = " << dist[i] << endl;
    return 0;
}
