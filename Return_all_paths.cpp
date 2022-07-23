// link :- https://leetcode.com/problems/all-paths-from-source-to-target/
// Return all Paths From Source to Target. We need to use back-tracking here !!

bool vis[15];
int n;
int source = 0;
int destination;
vector<vector<int>> ans;
void dfs(int v,vector<vector<int>>& graph,vector<int>& res)
{
    vis[v]=true;
    res.push_back(v);
    if(v == destination)
    ans.push_back(res);
    else
    {
        for(int i=0;i<graph[v].size();i++)
        {
            int child = graph[v][i];
            if(!vis[child])
                dfs(child,graph,res);
        }
    }
    vis[v]=false;
    res.pop_back();
    
}
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        n = graph.size();
        destination = n-1;
        ans.clear();
        vector<int> res;
        dfs(0,graph,res);
        return ans;
        
    }
};
