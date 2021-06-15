//DFS
void dfs(int v)
{
    vis[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(!vis[child)
        dfs(child);
    }
}


//BFS
queue<int> q;
void bfs(int v)
{
    q.push(v);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        vis[temp]=1;
        for(int i=0;i<g[temp].size();i++)
        {
            int child = g[temp][i];
            if(!vis[child])
            q.push(child);
        }
    }
}
