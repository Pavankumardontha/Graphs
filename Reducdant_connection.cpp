int par[1001];
void merge(int a,int b)
{
    par[b]=a;
}
int find(int a)
{
    if(par[a]<0)
        return a;
    else
    {
        par[a]=find(par[a]);
        return par[a];
    }
}
    
    
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        
        int n = edges.size() ; // n = no. of nodes = no. of edges in the graph always in the present problem
        for(int i=1;i<=n;i++)
            par[i]=-1;
        bool include_edge[n];
        for(int i=0;i<edges.size();i++)
            include_edge[i]=false;
        for(int i=0;i<edges.size();i++)
        {
            int k = find(edges[i][0]);
            int l = find(edges[i][1]);
            if(k!=l)
            {
                include_edge[i]=true;
                merge(k,l);
            }
        }
        vector<int> ans;
        for(int i=0;i<edges.size();i++)
        {
            if(include_edge[i]==false)
            {
                ans = edges[i];
                break;
            }
        }
        return ans;
    }
};
