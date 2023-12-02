#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};

vector<int> parent, rankk;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    rankk[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap(a, b);
        parent[b] = a;
        if (rankk[a] == rankk[b])
            rankk[a]++;
    }
}

int main() {
    int n;
    vector<Edge> edges;
    sort(edges.begin(), edges.end());
    parent.resize(n);
    rankk.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    vector<Edge> result;
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    for (Edge e : result) {
        cout << e.u << " " << e.v << " " << e.weight << endl;
    }
    return 0;
}

// Về độ phức tạp của thuật toán, nếu E là số lượng cạnh và V là số lượng đỉnh,
//thì độ phức tạp thời gian của thuật toán này là O(ElogE) do việc sắp xếp các cạnh,
//và O(ElogV do việc tìm và hợp nhất các tập hợp. Do đó, độ phức tạp tổng thể là O(ElogE + ElogV).
//Trong trường hợp tồi nhất,
//khi E = V^2, độ phức tạp sẽ là O(V^2 log V).
