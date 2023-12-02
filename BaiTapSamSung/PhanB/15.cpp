#include<bits/stdc++.h>

using namespace std;

vector<int>adj[1000];
bool visited[1000];
int a[1000][1000];
int n,m;
vector<int>topo;
stack<int>q;
int in[1000];//mang de tinh ban bac vao


void inp(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		in[y]++;
	}
	memset(visited,false,sizeof(visited));
}

void kahn(){
	queue<int>q;
	for(int i = 1;i <= n;i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		topo.push_back(u);
		for(int v : adj[u]){
			in[v]--;
			if(in[v] == 0) q.push(v);
		}
	}
	for(int x : topo) cout << x <<" ";
}


int main(){
	inp();
	kahn();
}
