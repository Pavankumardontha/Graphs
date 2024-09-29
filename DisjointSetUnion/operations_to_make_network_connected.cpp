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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        /*
        if there are n nodes , we need atleast n-1 nodes to connect them all into one single connected component
        */
        if(connections.size() < n-1)
        return -1;
        else
        {
            /*
            Lets say there are 3 disconnected components , we need 2 extra edges to make them into one connected component
            similarly, if there are 4 disconnected components , we need 3 extra edges to make them into one connected component
            so , if there are n disconnected components -> we need n-1 extra edges to make them one connected component
            */
            for(int i=0;i<n;i++)
            {
                par[i]=-1;
                set_size[i]=1;
            }
            for(int i=0;i<connections.size();i++)
            {
                int k = find(connections[i][0]);
                int l = find(connections[i][1]);
                if(k!=l)
                merge(k,l);
            }
            int connected_components = 0;
            for(int i=0;i<n;i++)
            {
                if(par[i]<0)
                connected_components++;
            }
            return connected_components - 1;
        }
        
    }
};
