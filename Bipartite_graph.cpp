vector<int> g[101];
bool vis[101];
bool color[101];

bool dfs(int v, int col)
{
    // color can be either 0 or 1
    vis[v]=true;
    color[v] = col;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(vis[child])
        {
            /* if child is already visited , check if the child and the parent is having the same color. If both have the same color then graph is not bipartite */
            if(color[v]==color[child])
                return false;
        }
        else
        {
            /*Explore the unvisited child and find if it is bipartite or not */
            bool ans = dfs(child,!col);
            if(ans==false)
                return ans;
        }
    }
    return true;
    
}
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        /*
            Initialise the colours array with -1 since none of the nodes are coloured 
        */
        memset(vis,false,sizeof(vis));
        memset(color,-1,sizeof(color));
        for(int i=0;i<graph.size();i++)
            g[i].clear();
        
        int n = graph.size();
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
                g[i].push_back(graph[i][j]);
        }
        
        /* since the graph can be disconnected we need to loop over all the nodes and start the dfs if they are not visited */
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bool ans = dfs(i,0);
                if(ans == false)
                    return false;
            }
        }
        return true;
    }
};



/* Bipartite graph with BFS */
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        /* Bipartite check with BFS */
        int n = graph.size();
        int color[n];
        bool vis[n];
        for(int i=0;i<n;i++)
        {
            color[i]=-1;
            vis[i]=false;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                q.push(i);
                color[i]=0;
                while(!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    for(int i=0;i<graph[v].size();i++)
                    {
                        int child = graph[v][i];
                        if(vis[child])
                        {
                            if(color[child]==color[v])
                                return false;
                        }
                        else
                        {
                            q.push(child);
                            vis[child]=true;
                            color[child] = !color[v];
                        }
                    }
                }
            }
        }
        return true;
        
    }
};

