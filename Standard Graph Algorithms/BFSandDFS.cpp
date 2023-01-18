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
void bfs(int v)
{
    queue<int> q;
    q.push(v);
    vis[v]=1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0;i<g[temp].size();i++)
        {
            int child = g[temp][i];
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
            }
        }
    }
}
