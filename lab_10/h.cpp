#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (visited[i][j] || grid[i][j] == '0') return;

    visited[i][j] = true;

    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i, j+1);
}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int islands = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                dfs(i, j);
                islands++;
            }
        }
    }

    cout << islands << endl;
    return 0;
}
