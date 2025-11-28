#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 100001;
int head[MAXN], nxt[2*MAXN], to[2*MAXN], edge_count = 0;
bool visited[MAXN];

void add_edge(int u, int v) {
    nxt[edge_count] = head[u];
    to[edge_count] = v;
    head[u] = edge_count++;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) head[i] = -1;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }

    int s, f;
    cin >> s >> f;

    for(int i = 1; i <= n; i++) visited[i] = false;

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    if(visited[f]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
