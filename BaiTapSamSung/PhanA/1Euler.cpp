
#include<bits/stdc++.h>

using namespace std;
///// Chu trình Euler
set<int>adj[1000];
int n,m;
int degree[1000];
void inp(){
	cin >> n >> m;
	for(int i = 1; i <= m;i++){
		int x,y; cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
		degree[x]++;
		degree[y]++;
	}
}

void Euler(int u){
	stack<int>st;
	vector<int>EC;
	st.push(u);
	while(!st.empty()){
		int x = st.top();
		if(adj[x].size() != 0){
			int y = *adj[x].begin();
			st.push(y);
			adj[x].erase(y);
			adj[y].erase(x);
		}
		else{
			st.pop();
			EC.push_back(x);
		}
	}
	for(int x : EC) cout << x <<' ';
}



int main(){
	inp();
	Euler(0);
}
//Kết luận
//Có chu trình Euler : Đồ thị 2
