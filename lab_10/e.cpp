#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }
    for (int k = 0; k < q; ++k) {
        int e1, e2, e3;
        cin >> e1 >> e2 >> e3;
        if (adj[e1][e2] && adj[e2][e3] && adj[e3][e1]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}



