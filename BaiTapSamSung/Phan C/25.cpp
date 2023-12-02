#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void primMST(vector<pair<int,int> > adj[], int V)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    int src = 0;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main()
{
    int V = 5;
    vector<iPair > adj[V];
    adj[0].push_back(make_pair(1, 2));
    adj[1].push_back(make_pair(0, 2));
    adj[1].push_back(make_pair(2, 3));
    adj[2].push_back(make_pair(1, 3));
    adj[0].push_back(make_pair(3, 6));
    adj[3].push_back(make_pair(0, 6));
    adj[1].push_back(make_pair(4, 5));
    adj[4].push_back(make_pair(1, 5));
    adj[1].push_back(make_pair(3, 7));
    adj[3].push_back(make_pair(1, 7));
    primMST(adj, V);
    return 0;
}
