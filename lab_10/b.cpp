#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    int graph[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int start,end;
    cin >> start >> end;
    start--;end--;

    int visited[100] = {0};
    int dist[100];
    for (int i = 0; i < n; i++) dist[i] = -1;

    queue<int> q;
    q.push(start);
    visited[start] = 1;
    dist[start] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u = 0; u <n;u++){
            if(graph[v][u] && !visited[u]){
                visited[u] = 1;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    cout << dist[end] << endl;
    return 0;
}
