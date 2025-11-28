#include <iostream>
using namespace std;

struct Node {
    int r, c, d;
};

int main() {
    int m, n;
    cin >> m >> n;

    int **a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    Node *q = new Node[m*n];
    int head = 0, tail = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 2)
                q[tail++] = {i, j, 0};

    int total = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1)
                total++;

    if (total == 0) {
        cout << 0;
        return 0;
    }

    bool **vis = new bool*[m];
    for (int i = 0; i < m; i++) {
        vis[i] = new bool[n];
        for (int j = 0; j < n; j++) vis[i][j] = false;
    }

    for (int i = 0; i < tail; i++)
        vis[q[i].r][q[i].c] = true;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int maxd = 0;

    while (head < tail) {
        Node cur = q[head++];
        for (int k = 0; k < 4; k++) {
            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (vis[nr][nc]) continue;
            if (a[nr][nc] == 0) continue;
            vis[nr][nc] = true;
            if (a[nr][nc] == 1) total--;
            q[tail++] = {nr, nc, cur.d + 1};
            if (cur.d + 1 > maxd) maxd = cur.d + 1;
        }
    }

    if (total > 0) cout << -1;
    else cout << maxd;

    return 0;
}
