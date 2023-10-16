#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>a[100];
bool visited[100];

void inp() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dfs(int u ) {
visited[u] = true;
for(auto x: a[u]) {
    if(!visited[x]) {dfs(x);}
}
}
void concomponent() {
int cnt = 0;
memset(visited, false, sizeof(visited));
for(int i =1 ; i <= n; i++) {

    if(!visited[i]) {
             ++cnt;
    dfs(i);}
}
cout << cnt;
}
int main()
{
inp();
concomponent();
     return 0;
 }
