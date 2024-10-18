vector<vector<int>> ans;
int src=0;
int des;
vector<int> g[16];
bool vis[16];
void solve(int current,vector<int> &route)
{
    route.push_back(current);
    vis[current]=true;
    if(current==des)
    ans.push_back(route);
    else
    {
        for(int i=0;i<g[current].size();i++)
        {
            int child = g[current][i];
            if(vis[child]==false)
            solve(child,route);
        }
    }
    route.pop_back();
    vis[current]=false;
}


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        ans.clear();
        int n = graph.size();
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            g[i].clear();
        }
        des=n-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int a = graph[i][j];
                g[i].push_back(a);
            }
        }
        vector<int> route;
        solve(0,route);
        return ans;
    }
};
