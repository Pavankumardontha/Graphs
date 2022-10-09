// link: https://leetcode.com/problems/keys-and-rooms/

vector<int> g[1001];
bool vis[1001];

void dfs(int v)
{
    vis[v]=true;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(!vis[child])
            dfs(child);
    }
}
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            g[i].clear();
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                g[i].push_back(rooms[i][j]);
            }
        }
        dfs(0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
        
    }
};
