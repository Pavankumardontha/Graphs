
//using topological sort !!
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        int in[V];
        int n = V;
        for(int i=0;i<n;i++)
        in[i]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<adj[i].size();j++)
                in[adj[i][j]]++;
        
        queue<int> q;        
        for(int i=0;i<n;i++)
        if(in[i]==0)
        q.push(i);
        vector<int> tp; //toposort order
        while(!q.empty())
        {
            int temp = q.front();
            tp.push_back(temp);
            q.pop();
            for(int i=0;i<adj[temp].size();i++)
            {
                int child = adj[temp][i];
                in[child]--;
                if(in[child]==0)
                q.push(child);
            }
        }
        if(tp.size() == n) // no cycle 
        return false;
        else
        return true; //cycle exists
    }
};
