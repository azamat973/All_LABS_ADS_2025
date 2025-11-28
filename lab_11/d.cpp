#include <iostream>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int parent[55], sz[55];

int find(int x) {
    while (x != parent[x]) x = parent[x];
    return x;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) {
        parent[a] = b;
        sz[b] += sz[a];
    } else {
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void sortEdges(Edge e[], int m) {
    for (int i = 0; i < m; i++) {
        int mn = i;
        for (int j = i + 1; j < m; j++) {
            if (e[j].w < e[mn].w) mn = j;
        }
        Edge tmp = e[i];
        e[i] = e[mn];
        e[mn] = tmp;
    }
}

int main() {
    int n;
    cin >> n;

    int a[55][55];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    Edge edges[3000]; 
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == 0) {
                
                unite(i, j);
            } else {
                
                edges[cnt].u = i;
                edges[cnt].v = j;
                edges[cnt].w = a[i][j];
                cnt++;
            }
        }
    }

    sortEdges(edges, cnt);

    long long ans = 0;

    // Kruskal
    for (int i = 0; i < cnt; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            unite(u, v);
            ans += w;
        }
    }

    cout << ans;
    return 0;
}
