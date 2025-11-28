#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ---------- Adjacency Matrix ----------
    int n1,m1;
    cin >> n1 >> m1;
    int graphm[10000][10000] = {0};
    
    for(int i= 0; i < m1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        graphm[a][b] = 1;
        graphm[b][a] = 1;
    }

    // ---------- Adjacency List ----------
    int n ,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    

    // ---------- Edge List ----------
    int n3, m3;
    cin >> n3 >> m3;
    vector<pair<int,int>> edges(m3);
    for (int i = 0; i < m3; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[i] = {a, b};
    }

    return 0;
}
