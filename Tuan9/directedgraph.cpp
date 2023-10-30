#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ifstream infile("jobs.txt");
    ofstream outfile("jobs.out");

    int n, m;
    infile >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        infile >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (order.size() != n) {
        outfile << "Khong ton tai thu tu thoa man" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            outfile << order[i] << " ";
        }
    }

    infile.close();
    outfile.close();

    return 0;
}

