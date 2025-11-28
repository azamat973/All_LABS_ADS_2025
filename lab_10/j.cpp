#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> children;

void dfs(int u, int parent, vector<int>& parentArr) {
    parentArr[u] = parent;
    int cnt = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != parent) {
            cnt++;
            dfs(v, u, parentArr);
        }
    }
    children[u] = cnt; 
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    children.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int bigFamCount = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int root = i;
            vector<int> component;
            vector<int> stack;
            stack.push_back(i);
            visited[i] = true;

            while (!stack.empty()) {
                int u = stack.back();
                stack.pop_back();
                component.push_back(u);

                for (int j = 0; j < graph[u].size(); j++) {
                    int v = graph[u][j];
                    if (!visited[v]) {
                        visited[v] = true;
                        stack.push_back(v);
                        if (v < root) root = v; 
                    }
                }
            }
            vector<int> parent(n + 1, 0);
            dfs(root, 0, parent);

            for (int k = 0; k < component.size(); k++) {
                int u = component[k];
                if (u == root) bigFamCount++;
                else if (children[u] > children[parent[u]]) bigFamCount++;
            }
        }
    }

    cout << bigFamCount << endl;

    return 0;
}
