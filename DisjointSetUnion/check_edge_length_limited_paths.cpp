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
    // always merge by size is much better than normal merge
    if(set_size[par1]<set_size[par2])
    {
        par[par1] = par2;
        set_size[par2] += set_size[par1];
    }
    else
    {
        par[par2]=par1;
        set_size[par1] += set_size[par2];
    }
}

bool comp(vector<int> x, vector<int> y)
{
    if(x[2] < y[2])
    return true;
    else
    return false;
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        vector<bool> ans(queries.size(),false);
        int m = edgeList.size();
        // sort the edge list in increasing order of their weight
        sort(edgeList.begin() , edgeList.end(), comp);

        /*
        NOTE: We cannot directly sort the query array because we need to return the answers in the same order as queries. So we will
        add an extra index field to the queries and then sort
        */
        for(int i=0;i<queries.size();i++)
        queries[i].push_back(i);

        // sort the queries list in the increasing order of their limit
        sort(queries.begin() , queries.end() , comp);
        for(int i=0;i<n;i++)
        {
            par[i]=-1;
            set_size[i]=1;
        }
        /*
        LOGIC: 
        traverse each query in the increasing order of limit
        {
            traverse each edge in the increasing order of their weight
            {
                add all nodes connected to the edges in DSU which are strictly less than query limit 
            }
            finally check if the first and the second node in the query belong to the same set. If they belong to the same set
            then we can travel from first node to second node with the query limit. If not we cannot.
        }
        */
        int current_edges_index = 0;
        for(int i=0;i<queries.size();i++)
        {
            int index = queries[i][3];
            int limit = queries[i][2];
            for(int j=current_edges_index;j<m;j++)
            {
                if(edgeList[j][2] < limit)
                {
                    // add the 2 edges into DSU
                    int k = find(edgeList[j][0]);
                    int l = find(edgeList[j][1]);
                    if(k != l)
                    merge(k,l);
                }
                else
                {
                    current_edges_index = j;
                    break;
                }
            }
            /* 
            we are now sure that the DSU is only constructed using the edges less than the current query limit.
            If both the first and second element now belong to the same set then it means we can traverse within the 
            query limit.
            */
            ans[index] = find(queries[i][0]) == find(queries[i][1]);
        }
        return ans;
    }
};
