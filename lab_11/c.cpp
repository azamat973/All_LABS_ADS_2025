#include <iostream>
#include <string>
using namespace std;

struct Edge {
    int a, b;
    int cost;
};

int parent[1005];
int sz[1005];

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
            if (e[j].cost < e[mn].cost) mn = j;
        }
        Edge temp = e[i];
        e[i] = e[mn];
        e[mn] = temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    Edge edges[1005];

    for (int i = 0; i < m; i++) {
        string type;
        int a, b, c;
        cin >> type >> a >> b >> c;

        int cost;
        if (type == "big") cost = c * x;
        else if (type == "small") cost = c * y;
        else cost = c * (x < y ? x : y); // both

        edges[i].a = a;
        edges[i].b = b;
        edges[i].cost = cost;
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    sortEdges(edges, m);

    long long ans = 0;
    int used = 0;

    for (int i = 0; i < m; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        if (find(a) != find(b)) {
            unite(a, b);
            ans += edges[i].cost;
            used++;
            if (used == n - 1) break;
        }
    }

    cout << ans;
    return 0;
}
