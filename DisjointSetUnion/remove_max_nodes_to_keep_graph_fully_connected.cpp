int par[100001];
int set_size[100001];
int find(int a)
{
    if(par[a]<0)
    return a;
    else
    return find(par[a]);
}

void merge(int par1, int par2)
{
    if(set_size[par1] < set_size[par2])
    {
        par[par1] = par2;
        set_size[par2] += set_size[par1];
    }
    else
    {
        par[par2] = par1;
        set_size[par1] += set_size[par2];
    }
}

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
         /*
        we will first see if alice can reach all the nodes or not 
        If alice can reach all the nodes using the alice edges and the common edges , we will then go and check the same for the bob.
        In both the cases , we note the common edges , alice edges and bob edges used by alice and bob to make them travel through
        the entire graph. After this we can easily remove the unused alice edges , bob edges and common edges.
        NOTE : there will be no more than one connected components in this case. If there are more than one connected component then
        we cannot start at a node and traverse all other nodes.
        */
        vector<vector<int>> common_edges;
        vector<vector<int>> alice_edges;
        vector<vector<int>> bob_edges;
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i][0]==1)
            alice_edges.push_back(edges[i]);
            else if(edges[i][0]==2)
            bob_edges.push_back(edges[i]);
            else
            common_edges.push_back(edges[i]);
        }
        vector<bool> is_common_edge_used(common_edges.size(),false);
        vector<bool> is_alice_edge_used(alice_edges.size(), false);
        vector<bool> is_bob_edge_used(bob_edges.size(),false);
        int ans = 0; 
        for(int i=1;i<=n;i++)
        {
            par[i]=-1;
            set_size[i]=1;
        }
        
        /* checking for alice */
        for(int i=0;i<common_edges.size();i++)
        {
            int k = find(common_edges[i][1]);
            int l = find(common_edges[i][2]);
            if(k!=l)
            {
                merge(k,l);
                is_common_edge_used[i]=true;
            }
        }
        for(int i=0;i<alice_edges.size();i++)
        {
            int k = find(alice_edges[i][1]);
            int l = find(alice_edges[i][2]);
            if(k!=l)
            {
                merge(k,l);
                is_alice_edge_used[i]=true;
            }
        }
        // if alice can reach all the nodes , then all the nodes should have only one parent
        int parents_count=0;
        for(int i=1;i<=n;i++)
        {
            if(par[i]==-1)
            parents_count++;
        }
        if(parents_count >= 2)
        return -1;

        // we will repeat the same process for bob
        for(int i=1;i<=n;i++)
        {
            set_size[i]=1;
            par[i]=-1;
        }
        for(int i=0;i<common_edges.size();i++)
        {
            int k = find(common_edges[i][1]);
            int l = find(common_edges[i][2]);
            if(k!=l)
            {
                merge(k,l);
                is_common_edge_used[i]=true;
            }
        }
        for(int i=0;i<bob_edges.size();i++)
        {
            int k = find(bob_edges[i][1]);
            int l = find(bob_edges[i][2]);
            if(k!=l)
            {
                merge(k,l);
                is_bob_edge_used[i]=true;
            }
        }
        // if bob can reach all the nodes , then all the nodes should have only one parent
        parents_count=0;
        for(int i=1;i<=n;i++)
        {
            if(par[i]==-1)
            parents_count++;
        }
        if(parents_count >= 2)
        return -1;

        // we will now count the unused nodes
        int unused_edges = 0; 
        for(int i=0;i<common_edges.size();i++)
        {
            if(is_common_edge_used[i] == false)
            unused_edges++;
        }
        for(int i=0;i<bob_edges.size();i++)
        {
            if(is_bob_edge_used[i] == false)
            unused_edges++;
        }
        for(int i=0;i<alice_edges.size();i++)
        {
            if(is_alice_edge_used[i] == false)
            unused_edges++;
        }
        return unused_edges;
    }
};
