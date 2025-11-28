#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() == n) {
        cout << "Possible\n";
        for (int i = 0; i < n; ++i) {
            cout << order[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
