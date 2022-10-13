vector<int> g[201];
int n;
bool vis[201];
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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        n = isConnected.size(); // no of nodes
        for(int i=0;i<n;i++)
        {
            g[i].clear();
            vis[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(i==j)
                    continue;
                else
                    if(isConnected[i][j])
                    g[i].push_back(j);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
                cnt++;
            }
        }
        return cnt;
    }
};
