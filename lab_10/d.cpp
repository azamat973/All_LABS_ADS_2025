#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100001;
int color[MAXN]; 
int dist[MAXN];
int head[MAXN], nxt[2*MAXN], to[2*MAXN], edge_count = 0;

void add_edge(int u, int v) {
    nxt[edge_count] = head[u];
    to[edge_count] = v;
    head[u] = edge_count++;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) head[i] = -1;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    while (q--) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            color[v] = 1;
        } else {
            for (int i = 1; i <= n; i++) dist[i] = -1;
            queue<int> bfs;
            bfs.push(v);
            dist[v] = 0;
            int answer = -1;
            while (!bfs.empty()) {
                int u = bfs.front(); bfs.pop();
                if (color[u] == 1) {
                    answer = dist[u];
                    break;
                }
                for (int e = head[u]; e != -1; e = nxt[e]) {
                    int x = to[e];
                    if (dist[x] == -1) {
                        dist[x] = dist[u] + 1;
                        bfs.push(x);
                    }
                }
            }
            cout << answer << endl;
        }
    }

    return 0;
}