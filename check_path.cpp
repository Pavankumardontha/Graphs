// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/

vector<int> g[200001];
bool vis[200001];

void dfs(int v)
{
    vis[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(!vis[child])
            dfs(child);
    }
}
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        // just do dfs call from source node. If there is path , the destination node also gets visited in this dfs call.
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            g[i].clear();
        }
        int m = edges.size();
        for(int i=0;i<m;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(source);
        if(vis[destination])
            return true;
        else
            return false;
    }
};
