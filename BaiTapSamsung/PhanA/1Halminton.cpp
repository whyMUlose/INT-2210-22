#include <bits/stdc++.h>
#define task "Hamilton."

using namespace std;

const int maxn = 101;

typedef int arr[maxn];
typedef int arr2[maxn][maxn];

void enter(int &n, int &m, arr2 adj, arr deg)
{
    cin >> n >> m;

    memset(adj, 0, sizeof(adj));
    memset(deg, 0, sizeof(deg));

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;

        ++adj[u][v];
        ++adj[v][u];

        ++deg[u];
        ++deg[v];
    }
}

bool check_hamilton_graph(int n, arr deg)
{
    for (int u = 1; u <= n; ++u)
        if (deg[u] < 2)
            return false;

    return true;
}

void print_hamilton_circuit(int n, arr circuit)
{
    for (int i = 1; i <= n; ++i)
        cout << circuit[i] << ' ';
    cout << circuit[1] << endl;
}


void find_hamilton_circuit(int i, int n, arr2 adj, arr circuit, arr is_free)
{

    for (int v = 1; v <= n; ++v)
        if (is_free[v] && adj[circuit[i - 1]][v])
        {
            circuit[i] = v;
            if (i < n)
            {
                is_free[v] = false;
                find_hamilton_circuit(i + 1, n, adj, circuit, is_free);
                is_free[v] = true;
            }
            else if (adj[v][circuit[1]])
                print_hamilton_circuit(n, circuit);
        }
}

void solution(int n, arr2 adj, arr deg, arr is_free, arr circuit)
{
    fill(is_free + 1, is_free + n + 1, 1);
    circuit[1] = 1;

    if (!check_hamilton_graph(n, deg))
        cout << 0;
    else
        find_hamilton_circuit(2, n, adj, circuit, is_free);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    arr2 adj;
    arr deg, is_free, circuit;

    enter(n, m, adj, deg);
    solution(n, adj, deg, is_free, circuit);

    return 0;
}

//Kết luận:
//Đồ thị có chu trình Hamilton : 1,3,4
