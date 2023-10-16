#include <bits/stdc++.h>
using namespace std;
int n, m, s ,t ;
vector<int>a[100];
bool visited[100];
int parent[100];

void dfs(int u) {
visited[u] = true;
for(int x : a[u]) {
    if(!visited[x]) {
            // ghi nhan cha cua v la u
            parent[x] = u;
        dfs(x);
    }
}
}

void bfs(int u ) {
    queue <int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
            int m = q.front();
    q.pop();
    for(int x : a[m]) {
        if(!visited[x]) {q.push(x);
        parent[x] = m;
        visited[x]  = true;
        }
    }
}
}

void Path(int s, int t) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    bfs(s);
    if(!visited[t]) return;
    else {
        vector <int> path;
        while( t != s) {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(auto x : path) {
            cout << x << " ";
        }
    }
}
//10 8 1 7
//1 2
//2 3
//2 4
//3 6
//3 7
//6 7
//5 8
//8 9

int main()
{
cin >> n >> m >> s >> t;
for (int i =0 ;i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
}
Path(s, t);
     return 0;
 }
