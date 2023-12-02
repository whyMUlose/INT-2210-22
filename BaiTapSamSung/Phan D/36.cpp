#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AdjList;
vi dist;

void dijkstra(int s) {
    dist.assign(AdjList.size(), INF);
    dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d == dist[u])
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
    }
}

int main() {
    int V, E, s, t, u, v, w;
    cin >> V >> E >> s >> t;
    AdjList.assign(V, vii());
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
    }
    dijkstra(s);
    int shortest = dist[t];
    int critical_increase = 0;
    ii critical_edge;
    for (u = 0; u < V; u++)
        for (auto &[v, w] : AdjList[u]) {
            AdjList[u].erase(remove(AdjList[u].begin(), AdjList[u].end(), make_pair(v, w)), AdjList[u].end());
            dijkstra(s);
            if (dist[t] > shortest + critical_increase) {
                critical_increase = dist[t] - shortest;
                critical_edge = {u, v};
            }
            AdjList[u].push_back({v, w});
        }
    cout << "Critical edge is " << critical_edge.first << " " << critical_edge.second << endl;
    return 0;
}
