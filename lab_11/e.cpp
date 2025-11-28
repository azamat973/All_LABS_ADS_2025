#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2000005;

vector<int> g[MAXN];
int parent[MAXN];
int sz[MAXN];
bool active[MAXN];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
        active[i] = false;
    }
    
    vector<int> ans(n + 1);
    int components = 0;

    for (int i = n; i >= 1; i--) {
        
        active[i] = true;
        components++;

        for (int neighbor : g[i]) {
            if (active[neighbor]) {
                if (union_sets(i, neighbor)) {
                    components--;
                }
            }
        }

        ans[i] = components - 1;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
