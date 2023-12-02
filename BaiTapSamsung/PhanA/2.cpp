#include <iostream>
#include <vector>

using namespace std;

int countGraphs(int V, int E, vector<vector<bool>>& edges, vector<bool>& visited, int start, int currentEdges) {
    if (currentEdges == E) {
        return 1;
    }

    int count = 0;
    for (int i = start; i < V; ++i) {
        if (!visited[i]) {
            for (int j = i + 1; j < V; ++j) {
                if (!visited[j] && !edges[i][j]) {
                    // Thử thêm cạnh i-j
                    visited[i] = visited[j] = edges[i][j] = true;
                    count += countGraphs(V, E, edges, visited, i, currentEdges + 1);
                    // Quay lui
                    visited[i] = visited[j] = edges[i][j] = false;
                }
            }
        }
    }

    return count;
}

int main() {
    int V, E;
    cout << "Nhap so dinh V: ";
    cin >> V;
    cout << "Nhap so canh E: ";
    cin >> E;

    if (E > V * (V - 1) / 2) {
        cout << "So canh khong hop le!\n";
        return 1;
    }

    vector<vector<bool>> edges(V, vector<bool>(V, false));
    vector<bool> visited(V, false);

    int result = countGraphs(V, E, edges, visited, 0, 0);

    cout << "So do thi vo huong khac nhau co " << V << " dinh va " << E << " canh la: " << result << endl;

    return 0;
}
// (VC2)CE
