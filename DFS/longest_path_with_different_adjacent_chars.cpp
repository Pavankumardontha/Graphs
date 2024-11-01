string s;
int n;
int find_maximum_path_length(int v,vector<int> &dp, vector<vector<int>> &g)
{
    // finds the maximum path length starting from node v
    if(dp[v]!=-1)
    return dp[v];
    dp[v]=1;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(s[v] != s[child])
        dp[v]=max(dp[v], 1 + find_maximum_path_length(child,dp,g));
    }
    return dp[v];
}


int solve(int v,vector<int> &dp, vector<vector<int>> &g)
{
    int a=0; // first maximum path length starting from child x of node v
    int b=0; // second maximum path length starting from child y of node index v
    /*
    We need to track the top 2 longest paths of children of node v 
    lets say the maximum children path lengths are l1 and l2 then the longest path with different adjacent characters is 
    l1+l2+1
    */
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(s[v] != s[child])
        {
            int max_length_from_child = find_maximum_path_length(child,dp,g);
            if(max_length_from_child>=a)
            {
                b=a;
                a=max_length_from_child;
            }
            else if(max_length_from_child>=b)
            {
                b=max_length_from_child;
            }
        }
    }
    return a+b+1;
}


class Solution {
public:
    int longestPath(vector<int>& parent, string s1) 
    {
        s=s1;
        n = parent.size();
        vector<int> dp(n,-1);
        vector<vector<int>> g(n);
        for(int i=0;i<n;i++)
        {
            if(parent[i] != -1)
            {
                g[parent[i]].push_back(i);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,solve(i,dp,g));
        }
        return ans;
    }
};
