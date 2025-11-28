/*
void BFS(int start){
    vector<bool> visited_bfs(graph.size,false);
    queue<int> q;
    
    visited_bfs[start] = true;
    q.push(start);

    while(!q.empty){
        int v = q.front();
        q.pop();

        cout << v+1 << " ";
        for(int u : graph[v]){
            if(!visited_bfs){
                visited_bfs[u] = 1;
                q.push(u);
            }
        }
    }

}
*/