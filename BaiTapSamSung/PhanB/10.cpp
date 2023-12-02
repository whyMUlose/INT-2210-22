#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int>adj[1001],r_adj[1001];
bool visited[1001];
stack<int>st;


void inp(){
	cin >> n >> m;
	memset(visited,false,sizeof(visited));
	for(int i = 0;i < m;i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}

void DFS1(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			 DFS1(v);
		}
	}
	st.push(u);
}

void DFS2(int u){
	visited[u] = true;
	cout << u <<" ";//in ra dinh cua moi tp lien thong manh
	for(int v : r_adj[u]){
		if(!visited[v]) DFS2(v);
	}
}

void SCC(){
	for(int i = 1;i <= n;i++){
		if(!visited[i]) DFS1(i);// them dinh vao stack
	}
	memset(visited,false,sizeof(visited));
	int cnt = 0;
	while(!st.empty()){
		int u = st.top(); st.pop();
		if(!visited[u]){
			cnt++;
			DFS2(u);// in ra tung dinh cua 1 tp lien thong manh
			cout << endl;
		}
	}
	cout <<"So thanh phan lien thong manh: "<<cnt<<endl;

}
int main(){
	inp();
	SCC();
}
