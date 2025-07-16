int par[100001];
int find(int a)
{
    if(par[a]<0)
    return a;
    else
    return find(par[a]);
}

void merge(int a, int b)
{
    par[a]=b;
}

bool Edgecomp(vector<int>& a, vector<int>& b)
{
    if(a[2]<b[2])
    return true;
    return false;
}

bool Querycomp(vector<int>& a, vector<int>& b)
{
    if(a[2]<b[2])
    return true;
    return false;
}

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        /*
        We need to think about 2 things here 
        1) Does there exist any path between 2 given nodes ?
        2) If there is a path, what is the edge having maximum distance in this path ?

        If there is a path between 2 nodes in a graph, they should belong to the same set in DSU or they should be 
        explored in the same BFS call. since the queries are large we cannot do bfs each time to tell whether a 
        path exists between 2 nodes in the graph or not. The graph configuration also does not change. So 
        if we apply DSU and segregate them into disjoint sets , we can easily tell whether there is a path between
        2 nodes or not.

        For the second question , we can maintain a minimum spanning tree. Even if we maintain a MST and add all the edges
        at once, we need to traverse from source node to the destination node to find the max edge distance in 
        the path. This is not optimal. So what we can do is , lets say we have a query q: [a,b,m] then 
        we will add all the egdes into the graph that have a distance less than m and then see if a path exists 
        between (a,b). If it exists then all the edges in the path will definitely have a distance less than 
        m and so we can return true.
        */
        int m = edgeList.size();
        int q = queries.size();
        for(int i=0;i<n;i++)
        par[i]=-1;
        // sort all the edges distance wise
        sort(edgeList.begin(),edgeList.end(),Edgecomp);
        // sort all queries limit wise but before sorting add the index since it changes after sorting
        for(int i=0;i<q;i++)
        queries[i].push_back(i);
        sort(queries.begin(),queries.end(),Querycomp);
        int last_added_edge_index = -1; // index of the last added edge into MST
        vector<bool> ans(q,false);
        int limit;
        int a,b,distance;
        for(int i=0;i<q;i++)
        {
            limit = queries[i][2]; 
            // add all the edges having a distance less than the max limit of the current query
            for(int j=last_added_edge_index+1;j<m;j++)
            {
                if(edgeList[j][2]<limit)
                {
                    // add the current edge into MST
                    a = find(edgeList[j][0]);
                    b = find(edgeList[j][1]);
                    distance = edgeList[j][2];
                    if(a!=b)
                    merge(a,b);
                    last_added_edge_index = j;
                }
                else
                break;
            }
            /* after adding all the edges which have distance less than the limit of 
            the current query we can easily tell whether there exists a path between
            nodes of the current query */
            if(find(queries[i][0]) != find(queries[i][1]))
            {
                // both belong to a different set and hence there is no path
                ans[queries[i][3]] = false;
            }
            else
            ans[queries[i][3]]=true;
        }
        return ans;
    }
};
