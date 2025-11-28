#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> in_degree;

bool isAcyclic() {
    queue<int> q;
    vector<int> indeg = in_degree;
    for (int i = 1; i <= n; i++) 
        if (indeg[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        count++;
        for (int v : graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    return count == n;
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    in_degree.resize(n + 1, 0);

    vector<pair<int,int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        in_degree[v]++;
        edges.push_back({u,v});
    }

    if (isAcyclic()) {
        cout << "YES\n";
        return 0;
    }

    bool possible = false;
    for (auto e : edges) {
        int u = e.first, v = e.second;

        for (auto it = graph[u].begin(); it != graph[u].end(); ++it) {
            if (*it == v) {
                graph[u].erase(it);
                break;
            }
        }
        in_degree[v]--;

        if (isAcyclic()) possible = true;

        graph[u].push_back(v);
        in_degree[v]++;

        if (possible) break;
    }

    cout << (possible ? "YES\n" : "NO\n");

    return 0;
}
